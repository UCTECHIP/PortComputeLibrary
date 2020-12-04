/*
 * Copyright (c) 2017-2018 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifdef __aarch64__

#include <cstddef>

#include <arm_neon.h>

#include "../../asmlib.hpp"
#include "../../utils.hpp"

// Kernel implementation - transposed GEMV
//
// The kernel will process "M" rows of A (= steps of dot product) and "N"
// columns (= dot products total)
//
// General plan is to do as many columns simultaneously as possible - a
// reasonable limit is half the NEON regfile = 64 total accumulators.
//
// It's possible that messing around with sub-blocking M and N can yield
// higher performance, but that's left to the outer loop.  In this kernel we
// process all of M at the same time.


// How far ahead to prefetch for the first and subsequent prefetches.
// These values work for A72 on JunoR2...

#define FIRST_PFD 9
#define PFD 6

namespace arm_gemm {

void a64_sgemv_trans(const float *Astart, const float *Xstart, float *Ystart, float beta, int lda, int M, int N) {
    const float *a_ptr_base = Astart;
    float *y_ptr = Ystart;
    const bool beta0 = (beta == 0.0f);


    float32x4_t vb = vdupq_n_f32(beta);

    int firstpfd=FIRST_PFD;
    if (firstpfd > M) {
        firstpfd = (M-1);
    }

    int pfd = PFD;
    if (pfd > M) {
        pfd = (M-1);
    }

    ptrdiff_t jump = lda * sizeof(int);

    for (;N>=96;N-=96) {
        int k = M-1;

        const float *a_ptr = a_ptr_base;
        const float *x_ptr = Xstart;
        const float *pf_ptr = a_ptr;
        const float *firstpf_ptr = a_ptr;
        const float *pf_limit = a_ptr + (M * lda);

        for (int i=0; i<firstpfd; i++) {
            prefetch_1x(firstpf_ptr);
            firstpf_ptr += lda;
        }

        for (int i=0; i<pfd; i++) {
            prefetch_5x(pf_ptr + 16);
            pf_ptr += lda;
        }

        a_ptr_base += 96;

	float *vb0 = &vb[0];
        __asm__ __volatile__(
		"li  a0, 4\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vle32.v  v1, (%[vb0])\n"
		
		"vmv.v.i       v8,0x0\n"
		"flw  	      f0, (%[x_ptr])\n"
		"vmv.v.i       v9,0x0\n"
		"vle32.v        v2,  (%[a_ptr])\n"
		"vmv.v.i       v10,0x0\n"
		"add    a1, %[a_ptr], 0x10\n"
		"vle32.v        v3,  (a1)\n"
		"vmv.v.i       v11,0x0\n"
		"add    a1, %[a_ptr], 0x20\n"
		"vle32.v        v4, (a1)\n"
		"vmv.v.i       v12,0x0\n"
		"add    a1, %[a_ptr], 0x30\n"
		"vle32.v        v5, (a1)\n"
		"vmv.v.i       v13,0x0\n"
		"add    a1, %[a_ptr], 0x40\n"
		"vle32.v        v6, (a1)\n"
		"vmv.v.i       v14,0x0\n"
		"add    a1, %[a_ptr], 0x50\n"
		"vle32.v        v7, (a1)\n"
		"vmv.v.i       v15,0x0\n"
		
		"vmv.v.i       v16, 0x0\n"
		"vmv.v.i       v17, 0x0\n"
		
		"vmv.v.i       v18, 0x0\n"
		"vmv.v.i       v19, 0x0\n"
		
		"vmv.v.i       v20, 0x0\n"
		"vmv.v.i       v21, 0x0\n"
		"vmv.v.i       v22, 0x0\n"
		"vmv.v.i       v23, 0x0\n"
		
		"vmv.v.i       v24, 0x0\n"
		"vmv.v.i       v25, 0x0\n"
		
		"vmv.v.i       v26, 0x0\n"
		"vmv.v.i       v27, 0x0\n"
		"add        %[pf_ptr], %[pf_ptr], %[jump]\n"
		"vmv.v.i       v28, 0x0\n"
		"add        %[firstpf_ptr], %[firstpf_ptr], %[jump]\n"
		"vmv.v.i       v29, 0x0\n"
		"vmv.v.i       v30, 0x0\n"
		"vmv.v.i       v31, 0x0\n"
		
		// Skip everything if there are no iterations of the main loop to do.
		"beqz        %[k], 10f\n"
		
		// Loop with all prefetches.  Exit this loop when firstpf_ptr
		// hits pf_limit.
		"1:\n"
		"vfmv.v.f       v0, f0\n"
		"add            a1, %[x_ptr], 4\n"
		"flw            f0, (a1)\n"
		"add        %[x_ptr], %[x_ptr], 0x4\n"

		"vfmacc.vv       v8, v2, v0\n"
		"vfmacc.vv       v9, v3, v0\n"
		"vfmacc.vv       v10, v4, v0\n"
		"vfmacc.vv       v11, v5, v0\n"
		"vfmacc.vv       v12, v6, v0\n"
		"vfmacc.vv       v13, v7, v0\n"
		"add            a1, %[a_ptr], 0x60\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x70\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x80\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x90\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0xa0\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0xb0\n"
		"vle32.v          v7, (a1)\n"
		"add        %[firstpf_ptr], %[firstpf_ptr], %[jump]\n"
		"addi        %[k], %[k], -1\n"
		"vfmacc.vv       v14, v2, v0\n"
		"vfmacc.vv       v15, v3, v0\n"
		"vfmacc.vv       v16, v4, v0\n"
		"vfmacc.vv       v17, v5, v0\n"
		"vfmacc.vv       v18, v6, v0\n"
		"vfmacc.vv       v19, v7, v0\n"
		"add            a1, %[a_ptr], 0xc0\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0xd0\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0xe0\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0xf0\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x100\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x110\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv       v20, v2, v0\n"
		"vfmacc.vv       v21, v3, v0\n"
		"vfmacc.vv       v22, v4, v0\n"
		"vfmacc.vv       v23, v5, v0\n"
		"vfmacc.vv       v24, v6, v0\n"
		"vfmacc.vv       v25, v7, v0\n"
		"add            a1, %[a_ptr], 0x120\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x130\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x140\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x150\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x160\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x170\n"
		"vle32.v          v7, (a1)\n"
		"add        %[a_ptr], %[a_ptr], %[jump]\n"
		"vfmacc.vv       v26, v2, v0\n"
		"vfmacc.vv       v27, v3, v0\n"
		"vfmacc.vv       v28, v4, v0\n"
		"vfmacc.vv       v29, v5, v0\n"
		"vfmacc.vv       v30, v6, v0\n"
		"vfmacc.vv       v31, v7, v0\n"
		"add            a1, %[a_ptr], 0x00\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x10\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x20\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x30\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x40\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x50\n"
		"vle32.v          v7, (a1)\n"
		"add        %[pf_ptr], %[pf_ptr], %[jump]\n"
		
		"blt            %[firstpf_ptr], %[pf_limit], 1b\n"
		
		// Check that there are still "main" prefetches to do.
		"bge            %[pf_ptr], %[pf_limit], 9f\n"
		
		// Just the main prefetches, exit this loop when pf_ptr hits pf_limit.
		"8:\n"
		"vfmv.v.f       v0, f0\n"
		"add            a1, %[x_ptr], 4\n"
		"flw            f0, (a1)\n"
		"add        %[x_ptr], %[x_ptr], 0x4\n"
		
		"vfmacc.vv       v8, v2, v0\n"
		"vfmacc.vv       v9, v3, v0\n"
		"vfmacc.vv       v10, v4, v0\n"
		"vfmacc.vv       v11, v5, v0\n"
		"vfmacc.vv       v12, v6, v0\n"
		"vfmacc.vv       v13, v7, v0\n"
		"add            a1, %[a_ptr], 0x60\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x70\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x80\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x90\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0xa0\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0xb0\n"
		"vle32.v          v7, (a1)\n"
		"addi        %[k], %[k], -1\n"
		"vfmacc.vv       v14, v2, v0\n"
		"vfmacc.vv       v15, v3, v0\n"
		"vfmacc.vv       v16, v4, v0\n"
		"vfmacc.vv       v17, v5, v0\n"
		"vfmacc.vv       v18, v6, v0\n"
		"vfmacc.vv       v19, v7, v0\n"
		"add            a1, %[a_ptr], 0xc0\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0xd0\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0xe0\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0xf0\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x100\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x110\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv       v20, v2, v0\n"
		"vfmacc.vv       v21, v3, v0\n"
		"vfmacc.vv       v22, v4, v0\n"
		"vfmacc.vv       v23, v5, v0\n"
		"vfmacc.vv       v24, v6, v0\n"
		"vfmacc.vv       v25, v7, v0\n"
		"add            a1, %[a_ptr], 0x120\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x130\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x140\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x150\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x160\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x170\n"
		"vle32.v          v7, (a1)\n"
		"add        %[a_ptr], %[a_ptr], %[jump]\n"
		"vfmacc.vv       v26, v2, v0\n"
		"vfmacc.vv       v27, v3, v0\n"
		"vfmacc.vv       v28, v4, v0\n"
		"vfmacc.vv       v29, v5, v0\n"
		"vfmacc.vv       v30, v6, v0\n"
		"vfmacc.vv       v31, v7, v0\n"
		"add            a1, %[a_ptr], 0x00\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x10\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x20\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x30\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x40\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x50\n"
		"vle32.v          v7, (a1)\n"
		"add        %[pf_ptr], %[pf_ptr], %[jump]\n"
		
		"blt            %[pf_ptr], %[pf_limit], 8b\n"
		
		// Check that there is still work to do.
		"9:\n"
		"beqz        %[k], 10f\n"
		
		// Loop without prefetches, exit when k hits 0.
		"2:\n"
		"vfmv.v.f       v0, f0\n"
		"add            a1, %[x_ptr], 4\n"
		"flw            f0, (a1)\n"
		"add        %[x_ptr], %[x_ptr], 0x4\n"
		
		"vfmacc.vv       v8, v2, v0\n"
		"vfmacc.vv       v9, v3, v0\n"
		"vfmacc.vv       v10, v4, v0\n"
		"vfmacc.vv       v11, v5, v0\n"
		"vfmacc.vv       v12, v6, v0\n"
		"vfmacc.vv       v13, v7, v0\n"
		"add            a1, %[a_ptr], 0x60\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x70\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x80\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x90\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0xa0\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0xb0\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv       v14, v2, v0\n"
		"vfmacc.vv       v15, v3, v0\n"
		"vfmacc.vv       v16, v4, v0\n"
		"vfmacc.vv       v17, v5, v0\n"
		"vfmacc.vv       v18, v6, v0\n"
		"vfmacc.vv       v19, v7, v0\n"
		"add            a1, %[a_ptr], 0xc0\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0xd0\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0xe0\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0xf0\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x100\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x110\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv       v20, v2, v0\n"
		"vfmacc.vv       v21, v3, v0\n"
		"vfmacc.vv       v22, v4, v0\n"
		"vfmacc.vv       v23, v5, v0\n"
		"vfmacc.vv       v24, v6, v0\n"
		"vfmacc.vv       v25, v7, v0\n"
		"add            a1, %[a_ptr], 0x120\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x130\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x140\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x150\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x160\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x170\n"
		"vle32.v          v7, (a1)\n"
		"add        %[a_ptr], %[a_ptr], %[jump]\n"
		"vfmacc.vv       v26, v2, v0\n"
		"vfmacc.vv       v27, v3, v0\n"
		"vfmacc.vv       v28, v4, v0\n"
		"vfmacc.vv       v29, v5, v0\n"
		"vfmacc.vv       v30, v6, v0\n"
		"vfmacc.vv       v31, v7, v0\n"
		"add            a1, %[a_ptr], 0x00\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x10\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x20\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x30\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x40\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x50\n"
		"vle32.v          v7, (a1)\n"
		
		"addi        %[k], %[k], -1\n"
		"bnez           %[k], 2b\n"
		
		"10:\n"
		// Final iteration
		"vfmacc.vv       v8, v2, v0\n"
		"vfmacc.vv       v9, v3, v0\n"
		"vfmacc.vv       v10, v4, v0\n"
		"vfmacc.vv       v11, v5, v0\n"
		"vfmacc.vv       v12, v6, v0\n"
		"vfmacc.vv       v13, v7, v0\n"
		"add            a1, %[a_ptr], 0x60\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x70\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x80\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x90\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0xa0\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0xb0\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv       v14, v2, v0\n"
		"vfmacc.vv       v15, v3, v0\n"
		"vfmacc.vv       v16, v4, v0\n"
		"vfmacc.vv       v17, v5, v0\n"
		"vfmacc.vv       v18, v6, v0\n"
		"vfmacc.vv       v19, v7, v0\n"
		"add            a1, %[a_ptr], 0xc0\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0xd0\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0xe0\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0xf0\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x100\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x110\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv       v20, v2, v0\n"
		"vfmacc.vv       v21, v3, v0\n"
		"vfmacc.vv       v22, v4, v0\n"
		"vfmacc.vv       v23, v5, v0\n"
		"vfmacc.vv       v24, v6, v0\n"
		"vfmacc.vv       v25, v7, v0\n"
		"add            a1, %[a_ptr], 0x120\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[a_ptr], 0x130\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[a_ptr], 0x140\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[a_ptr], 0x150\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[a_ptr], 0x160\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[a_ptr], 0x170\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv       v26, v2, v0\n"
		
		"bnez           %[beta0], 11f\n"
		
		"vfmacc.vv       v27, v3, v0\n"
		"vfmacc.vv       v28, v4, v0\n"
		"vfmacc.vv       v29, v5, v0\n"
		"vfmacc.vv       v30, v6, v0\n"
		"vfmacc.vv       v31, v7, v0\n"
		"vle32.v          v2, (%[y_ptr])\n"
		"add            a1, %[y_ptr], 0x10\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[y_ptr], 0x20\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[y_ptr], 0x30\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[y_ptr], 0x40\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[y_ptr], 0x50\n"
		"vle32.v          v7, (a1)\n"
		
		"vfmacc.vv       v8, v2, v1\n"
		"vfmacc.vv       v9, v3, v1\n"
		"vfmacc.vv       v10, v4, v1\n"
		"vfmacc.vv       v11, v5, v1\n"
		"vfmacc.vv       v12, v6, v1\n"
		"vfmacc.vv       v13, v7, v1\n"
		"add            a1, %[y_ptr], 0x60\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[y_ptr], 0x70\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[y_ptr], 0x80\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[y_ptr], 0x90\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[y_ptr], 0xa0\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[y_ptr], 0xb0\n"
		"vle32.v          v7, (a1)\n"
		"vse32.v          v8, (%[y_ptr])\n"
		"add            a1, %[y_ptr], 0x10\n"
		"vse32.v          v9, (a1)\n"
		"add            a1, %[y_ptr], 0x20\n"
		"vse32.v          v10, (a1)\n"
		"add            a1, %[y_ptr], 0x30\n"
		"vse32.v          v11, (a1)\n"
		"add            a1, %[y_ptr], 0x40\n"
		"vse32.v          v12, (a1)\n"
		"add            a1, %[y_ptr], 0x50\n"
		"vse32.v          v13, (a1)\n"
		
		"vfmacc.vv       v14, v2, v1\n"
		"vfmacc.vv       v15, v3, v1\n"
		"vfmacc.vv       v16, v4, v1\n"
		"vfmacc.vv       v17, v5, v1\n"
		"vfmacc.vv       v18, v6, v1\n"
		"vfmacc.vv       v19, v7, v1\n"
		"add            a1, %[y_ptr], 0xc0\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[y_ptr], 0xd0\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[y_ptr], 0xe0\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[y_ptr], 0xf0\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[y_ptr], 0x100\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[y_ptr], 0x110\n"
		"vle32.v          v7, (a1)\n"
		"add            a1, %[y_ptr], 0x60\n"
		"vse32.v          v14, (a1)\n"
		"add            a1, %[y_ptr], 0x70\n"
		"vse32.v          v15, (a1)\n"
		"add            a1, %[y_ptr], 0x80\n"
		"vse32.v          v16, (a1)\n"
		"add            a1, %[y_ptr], 0x90\n"
		"vse32.v          v17, (a1)\n"
		"add            a1, %[y_ptr], 0xa0\n"
		"vse32.v          v18, (a1)\n"
		"add            a1, %[y_ptr], 0xb0\n"
		"vse32.v          v19, (a1)\n"
		
		"vfmacc.vv       v20, v2, v1\n"
		"vfmacc.vv       v21, v3, v1\n"
		"vfmacc.vv       v22, v4, v1\n"
		"vfmacc.vv       v23, v5, v1\n"
		"vfmacc.vv       v24, v6, v1\n"
		"vfmacc.vv       v25, v7, v1\n"
		"add            a1, %[y_ptr], 0x120\n"
		"vle32.v          v2, (a1)\n"
		"add            a1, %[y_ptr], 0x130\n"
		"vle32.v          v3, (a1)\n"
		"add            a1, %[y_ptr], 0x140\n"
		"vle32.v          v4, (a1)\n"
		"add            a1, %[y_ptr], 0x150\n"
		"vle32.v          v5, (a1)\n"
		"add            a1, %[y_ptr], 0x160\n"
		"vle32.v          v6, (a1)\n"
		"add            a1, %[y_ptr], 0x170\n"
		"vle32.v          v7, (a1)\n"
		"add            a1, %[y_ptr], 0xc0\n"
		"vse32.v          v20, (a1)\n"
		"add            a1, %[y_ptr], 0xd0\n"
		"vse32.v          v21, (a1)\n"
		"add            a1, %[y_ptr], 0xe0\n"
		"vse32.v          v22, (a1)\n"
		"add            a1, %[y_ptr], 0xf0\n"
		"vse32.v          v23, (a1)\n"
		"add            a1, %[y_ptr], 0x100\n"
		"vse32.v          v24, (a1)\n"
		"add            a1, %[y_ptr], 0x110\n"
		"vse32.v          v25, (a1)\n"
		
		"vfmacc.vv       v26, v2, v1\n"
		"vfmacc.vv       v27, v3, v1\n"
		"vfmacc.vv       v28, v4, v1\n"
		"vfmacc.vv       v29, v5, v1\n"
		"vfmacc.vv       v30, v6, v1\n"
		"vfmacc.vv       v31, v7, v1\n"
		"add            a1, %[y_ptr], 0x120\n"
		"vse32.v          v26, (a1)\n"
		"add            a1, %[y_ptr], 0x130\n"
		"vse32.v          v27, (a1)\n"
		
		"j              12f\n"
		
		// beta 0 code - don't read.
		"11:\n"
		
		"vfmacc.vv       v27, v3, v0\n"
		"vfmacc.vv       v28, v4, v0\n"
		"vfmacc.vv       v29, v5, v0\n"
		"vfmacc.vv       v30, v6, v0\n"
		"vfmacc.vv       v31, v7, v0\n"
		"vse32.v          v8, (%[y_ptr])\n"
		"add            a1, %[y_ptr], 0x10\n"
		"vse32.v          v9, (a1)\n"
		"add            a1, %[y_ptr], 0x20\n"
		"vse32.v          v10, (a1)\n"
		"add            a1, %[y_ptr], 0x30\n"
		"vse32.v          v11, (a1)\n"
		"add            a1, %[y_ptr], 0x40\n"
		"vse32.v          v12, (a1)\n"
		"add            a1, %[y_ptr], 0x50\n"
		"vse32.v          v13, (a1)\n"
		"add            a1, %[y_ptr], 0x60\n"
		"vse32.v          v14, (a1)\n"
		"add            a1, %[y_ptr], 0x70\n"
		"vse32.v          v15, (a1)\n"
		"add            a1, %[y_ptr], 0x80\n"
		"vse32.v          v16, (a1)\n"
		"add            a1, %[y_ptr], 0x90\n"
		"vse32.v          v17, (a1)\n"
		"add            a1, %[y_ptr], 0xa0\n"
		"vse32.v          v18, (a1)\n"
		"add            a1, %[y_ptr], 0xb0\n"
		"vse32.v          v19, (a1)\n"
		"add            a1, %[y_ptr], 0xc0\n"
		"vse32.v          v20, (a1)\n"
		"add            a1, %[y_ptr], 0xd0\n"
		"vse32.v          v21, (a1)\n"
		"add            a1, %[y_ptr], 0xe0\n"
		"vse32.v          v22, (a1)\n"
		"add            a1, %[y_ptr], 0xf0\n"
		"vse32.v          v23, (a1)\n"
		"add            a1, %[y_ptr], 0x100\n"
		"vse32.v          v24, (a1)\n"
		"add            a1, %[y_ptr], 0x110\n"
		"vse32.v          v25, (a1)\n"
		"add            a1, %[y_ptr], 0x120\n"
		"vse32.v          v26, (a1)\n"
		"add            a1, %[y_ptr], 0x130\n"
		"vse32.v          v27, (a1)\n"
		
		"12:\n"
		"add            a1, %[y_ptr], 0x140\n"
		"vse32.v          v28, (a1)\n"
		"add            a1, %[y_ptr], 0x150\n"
		"vse32.v          v29, (a1)\n"
		"add            a1, %[y_ptr], 0x160\n"
		"vse32.v          v30, (a1)\n"
		"add            a1, %[y_ptr], 0x170\n"
		"vse32.v          v31, (a1)\n"
		"add        %[y_ptr], %[y_ptr], 0x180\n"
		
		: [a_ptr] "+r" (a_ptr), [x_ptr] "+r" (x_ptr), [y_ptr] "+r" (y_ptr), [k] "+r" (k), [pf_ptr] "+r" (pf_ptr), [firstpf_ptr] "+r" (firstpf_ptr)
		: [jump] "r" (jump), [vb0] "r" (vb0), [pf_limit] "r" (pf_limit), [beta0] "r" (beta0)
		: "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15",
		  "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31", "t0", "a0", "a1", "f0"
		);
    }

    if (N>0) {
        // Handle N tail - up to 95 stragglers.
        // This is 0-23 vectors, plus optionally an 64-bit vector and/or a
        // single value for the remainder.

        // Independent pointers into the matrix for the odd 2 and odd 1.
        // Double up as flag to indicate whether they are needed.
        const float *odd2_aptr=NULL;
        const float *odd1_aptr=NULL;

        // Figure out how much work we need to do.
        int numvecs = N/4;
        int rem = N%4;
        int k=M;

        // Set up pointers for the odd 2/1 if needed.
        if (rem >= 2) {
            odd2_aptr = a_ptr_base + (numvecs * 4);
        }

        if (rem & 1) {
            odd1_aptr = a_ptr_base + (numvecs * 4) + (odd2_aptr==NULL ? 0 : 2);
        }

        const float *a_ptr = a_ptr_base;
        const float *firstpf_ptr = a_ptr_base;
        const float *pf_ptr = a_ptr_base;
        const float *pf_limit = a_ptr + (M * lda);

        const float *x_ptr = Xstart;
        int vecs=0; // Working variable to count how many vectors to work on.
        int dopf=1; // Track whether we are doing prefetches.

        // Figure out how many cache lines we need to prefetch each time.
        int numpfs = (N + 15) / 16;

        // Do initial prefetches
        for (int i=0; i<firstpfd+1; i++) {
            prefetch_1x(firstpf_ptr);
            firstpf_ptr += lda;
        }

        // Do "main" prefetches - adapt number to the number we actually need.
        if (numpfs > 1) {
            for (int i=0; i<pfd+1; i++) {
                switch (numpfs) {
                    case 2:
                        prefetch_1x(pf_ptr + 16);
                        break;

                    case 3:
                        prefetch_2x(pf_ptr + 16);
                        break;

                    case 4:
                        prefetch_3x(pf_ptr + 16);
                        break;

                    case 5:
                        prefetch_4x(pf_ptr + 16);
                        break;

                    case 6:
                        prefetch_5x(pf_ptr + 16);
                        break;

                    default:
                        UNREACHABLE("Impossible.");
                }
                pf_ptr += lda;
            }
        } else {
            // Just disable additional prefetches
            dopf=0;
        }

        // Do the real work

	float *vb0 = &vb[0];
        __asm__ __volatile__(
		// Initialize all the vectors - not worth skipping this if only
		// some are needed.
		
		"li  a0, 4\n"
		"li  a2, 2\n"
		"li  a3, 1\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vle32.v  v1, (%[vb0])\n"
		
		"vmv.v.i       v8,0x0\n"
		"flw            f0, (%[x_ptr])\n"
		"vmv.v.i       v9,0x0\n"
		"vmv.v.i       v10,0x0\n"
		"vmv.v.i       v11,0x0\n"
		"vmv.v.i       v12,0x0\n"
		"vmv.v.i       v13,0x0\n"
		"vmv.v.i       v14,0x0\n"
		"vmv.v.i       v15,0x0\n"
		"vmv.v.i       v16, 0x0\n"
		"vmv.v.i       v17, 0x0\n"
		"vmv.v.i       v18, 0x0\n"
		"vmv.v.i       v19, 0x0\n"
		"vmv.v.i       v20, 0x0\n"
		"vmv.v.i       v21, 0x0\n"
		"vmv.v.i       v22, 0x0\n"
		"vmv.v.i       v23, 0x0\n"
		"vmv.v.i       v24, 0x0\n"
		"vmv.v.i       v25, 0x0\n"
		"vmv.v.i       v26, 0x0\n"
		"vmv.v.i       v27, 0x0\n"
		"vmv.v.i       v28, 0x0\n"
		"vmv.v.i       v29, 0x0\n"
		"vmv.v.i       v30, 0x0\n"
		"vmv.v.i       v6, 0x0\n"
		"vmv.v.i       v5, 0x0\n"
		
		
		"1:\n"
		
		"11:\n"
		"vfmv.v.f       v0, f0\n"
		"add            a1, %[x_ptr], 4\n"
		"flw            f0, (a1)\n"
		"add        %[x_ptr], %[x_ptr], 0x4\n"
		
		"beqz           %[numvecs], 2f\n"
		"mv            %[vecs], %[numvecs]\n"
		
		// Vector 0
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[a_ptr])\n"
		"vfmacc.vv      v8, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 1
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x10\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v9, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 2
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x20\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v10, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 3
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x30\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v11, v7, v0\n"
		
		// Prefetch
		"beqz           %[dopf], 3f\n"
		
		"3:\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 4
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x40\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v12, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 5
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x50\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v13, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 6
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x60\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v14, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 7
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x70\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v15, v7, v0\n"
		
		// Prefetch
		"beqz           %[dopf], 4f\n"
		
		"4:\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 8
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x80\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v16, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 9
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x90\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v17, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 10
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0xa0\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v18, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 11
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0xb0\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v19, v7, v0\n"
		
		// Prefetch
		"beqz           %[dopf], 5f\n"
		
		"5:\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 12
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0xc0\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v20, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 13
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0xd0\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v21, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 14
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0xe0\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v22, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 15
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0xf0\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v23, v7, v0\n"
		
		// Prefetch
		"beqz           %[dopf], 6f\n"
		
		"6:\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 16
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x100\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v24, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 17
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x110\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v25, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 18
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x120\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v26, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 19
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x130\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v27, v7, v0\n"
		
		// Prefetch
		"beqz           %[dopf], 7f\n"
		
		"7:\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 20
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x140\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v28, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 21
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x150\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v29, v7, v0\n"
		"beqz           %[vecs], 2f\n"
		
		// Vector 22
		"addi           %[vecs], %[vecs], -1\n"
		"add            a1, %[a_ptr], 0x160\n"
		"vle32.v          v7, (a1)\n"
		"vfmacc.vv      v30, v7, v0\n"
		
		"2:\n"
		"add        %[a_ptr], %[a_ptr], %[jump]\n"
		
		// Do the odd 2-vector, if needed
		"beqz           %[odd2_aptr], 8f\n"
		"vle32.v          v7, (%[odd2_aptr])\n"
		"vfmacc.vv      v6, v7, v0\n"
		"add        %[odd2_aptr], %[odd2_aptr], %[jump]\n"
		
		 "8:\n"
		// Do the odd 1-vector, if needed
		"beqz           %[odd1_aptr], 9f\n"
		"vle32.v          v7, (%[odd1_aptr])\n"
		"vfmacc.vv      v5, v7, v0\n"
		"add        %[odd1_aptr], %[odd1_aptr], %[jump]\n"
		
		// Get out if needed.
		"9:\n"
		"addi       %[k], %[k], -1\n"
		"beqz           %[k], 10f\n"
		
		// Update the "main" prefetch pointer, if it strays beyond the limit turn off "dopf"
		"add        %[pf_ptr], %[pf_ptr], %[jump]\n"
		"blt            %[pf_ptr], %[pf_limit], 19f\n"
		"mv             %[dopf],x0\n"
		"19:\n"
		
		// Update the "leading" prefetch pointer, don't do the first
		// instruction of the loop if it's over the limit.
		"add        %[firstpf_ptr], %[firstpf_ptr], %[jump]\n"
		"blt            %[firstpf_ptr], %[pf_limit], 1b\n"
		"j              11b\n"
		
		// Now write out the outputs
		"10:\n"
		"bnez           %[beta0], 15f\n"
		
		"beqz           %[numvecs], 12f\n"
		"mv             %[vecs], %[numvecs]\n"
		
		// Vector 0
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7, (%[y_ptr])\n"
		"vfmacc.vv      v8, v7, v1\n"
		"vse32.v          v8, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 1
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v9, v7, v1\n"
		"vse32.v          v9, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 2
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v10, v7, v1\n"
		"vse32.v          v10, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 3
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v11, v7, v1\n"
		"vse32.v          v11, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 4
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v12, v7, v1\n"
		"vse32.v          v12, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 5
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v13, v7, v1\n"
		"vse32.v          v13, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 6
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v14, v7, v1\n"
		"vse32.v          v14, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 7
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v15, v7, v1\n"
		"vse32.v          v15, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 8
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v16, v7, v1\n"
		"vse32.v          v16, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 9
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v17, v7, v1\n"
		"vse32.v          v17, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 10
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v18, v7, v1\n"
		"vse32.v          v18, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 11
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v19, v7, v1\n"
		"vse32.v          v19, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 12
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v20, v7, v1\n"
		"vse32.v          v20, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 13
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v21, v7, v1\n"
		"vse32.v          v21, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 14
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v22, v7, v1\n"
		"vse32.v          v22, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 15
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v23, v7, v1\n"
		"vse32.v          v23, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 16
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v24, v7, v1\n"
		"vse32.v          v24, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 17
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v25, v7, v1\n"
		"vse32.v          v25, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 18
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v26, v7, v1\n"
		"vse32.v          v26, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 19
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v27, v7, v1\n"
		"vse32.v          v27, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 20
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v28, v7, v1\n"
		"vse32.v          v28, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 21
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v29, v7, v1\n"
		"vse32.v          v29, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 12f\n"
		
		// Vector 22
		"addi           %[vecs], %[vecs], -1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v30, v7, v1\n"
		"vse32.v          v30, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		
		// Odd 2
		"12:\n"
		"beqz           %[odd2_aptr], 13f\n"
		"vsetvli  t0, a2, e32, m1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v6, v7, v1\n"
		"vse32.v          v6, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x8\n"
		"vsetvli  t0, a0, e32, m1\n"
		
		// Odd 1
		"13:\n"
		"beqz           %[odd1_aptr], 14f\n"
		"vsetvli  t0, a3, e32, m1\n"
		"vle32.v          v7,(%[y_ptr])\n"
		"vfmacc.vv      v5, v7, v1\n"
		"vse32.v          v5, (%[y_ptr])\n"
		"vsetvli  t0, a0, e32, m1\n"
		"j              14f\n"
		
		"15:\n"
		// beta0 code
		"beqz           %[numvecs], 16f\n"
		"mv        %[vecs], %[numvecs]\n"
		
		// Vector 0
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v8, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 1
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v9, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 2
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v10, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 3
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v11, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 4
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v12, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 5
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v13, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 6
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v14, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 7
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v15, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 8
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v16, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 9
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v17, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 10
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v18, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 11
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v19, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 12
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v20, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 13
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v21, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 14
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v22, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 15
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v23, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 16
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v24, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 17
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v25, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 18
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v26, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 19
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v27, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 20
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v28, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 21
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v29, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		"beqz           %[vecs], 16f\n"
		
		// Vector 22
		"addi           %[vecs], %[vecs], -1\n"
		"vse32.v          v30, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x10\n"
		
		// Odd 2
		"16:\n"
		"beqz           %[odd2_aptr], 17f\n"
		"vsetvli  t0, a2, e32, m1\n"
		"vse32.v          v6, (%[y_ptr])\n"
		"add            %[y_ptr], %[y_ptr], 0x8\n"
		"vsetvli  t0, a0, e32, m1\n"
		
		// Odd 1
		"17:\n"
		"beqz           %[odd1_aptr], 14f\n"
		"vsetvli  t0, a3, e32, m1\n"
		"vse32.v          v5, (%[y_ptr])\n"
		"vsetvli  t0, a0, e32, m1\n"
		
		"14:\n"
	: [a_ptr] "+r" (a_ptr), [x_ptr] "+r" (x_ptr), [y_ptr] "+r" (y_ptr), [k] "+r" (k),
	  [pf_ptr] "+r" (pf_ptr), [firstpf_ptr] "+r" (firstpf_ptr),
	  [odd1_aptr] "+r" (odd1_aptr), [odd2_aptr] "+r" (odd2_aptr),
	  [dopf] "+r" (dopf), [vecs] "+r" (vecs)
	: [jump] "r" (jump), [vb0] "r" (vb0), [pf_limit] "r" (pf_limit), [numvecs] "r" (numvecs), [beta0] "r" (beta0)
	: "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8",  "v9", "v10", "v11", "v12", "v13",
	  "v14", "v15", "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", "v24", "v25", "v26",
	  "v27", "v28", "v29", "v30", "v31", "t0", "a0", "a1", "a2", "a3", "x0", "f0"
	);
    }
}

} // namespace arm_gemm

#endif // __aarch64__
