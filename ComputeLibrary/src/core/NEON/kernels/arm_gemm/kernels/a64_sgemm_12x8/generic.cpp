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

#include <arm_neon.h>

#include "../../asmlib.hpp"

// Kernel implementation.
//
// Assume that "Apanel" points to a chunk of A blocks (each size 8xK) in read-order.
// Assume that "Bpanel" points to a chunk of B blocks (each size 12xK) in read-order.
// Assume that "Cpanel" points to a chunk of C output blocks (each size
// 12x8), the chunks being arranged in a row major fashion.
//
// Note that the intent of this is that either ablocks or bblocks will be 1
// - this construction allows the output loop to proceed in either order.

namespace arm_gemm {

void a64_sgemm_asimd_12x8(const float *Apanel, const float *Bpanel, float *Cpanel, int ablocks, int bblocks, int K) {
    const float *a_ptr = Apanel;
    float *c_ptr = Cpanel;

    for (int yb=0; yb<ablocks; yb++) {
        const float *a_ptr0 = a_ptr;
        const float *b_ptr = Bpanel;

        for (int xb=0; xb<bblocks; xb++) {
            a_ptr = a_ptr0;
            // Fix up for odd lengths - set a flag if K is odd, but make
            // sure we round up the iteration count.
            int oddk = (K & 1);
            int k = ((K+1)/2) - 1;


	    float s[4] = {0,0,0,0};
    	    float *s0 = s;
    	    float *s1 = s0 + 1;
    	    float *s2 = s1 + 1;
    	    float *s3 = s2 + 1;
            __asm__ __volatile__(
            	// Initialize result registers, load initial operands, prime prefetches.
				"li  a0, 4\n"
				"vsetvli  t0, a0, e32, m1\n"

				"vmv.v.i        v8, 0x0\n"
				"vle32.v  v0, (%[a_ptr])\n"
				"vmv.v.i        v9, 0x0\n"
				"vle32.v  v2, (%[b_ptr])\n"
				"vmv.v.i        v10, 0x0\n"
				"add   a1, %[a_ptr], 16\n"
				"vle32.v  v1, (a1)\n"
				"vmv.v.i        v11, 0x0\n"
				"add   a1, %[b_ptr], 16\n"
				"vle32.v  v3, (a1)\n"

				"vmv.v.i        v12, 0x0\n"

				"vmv.v.i        v13, 0x0\n"

				"vmv.v.i        v14, 0x0\n"

				"vmv.v.i        v15, 0x0\n"

				"vmv.v.i        v16, 0x0\n"

				"vmv.v.i        v17, 0x0\n"

				"vmv.v.i        v18, 0x0\n"

				"vmv.v.i        v19, 0x0\n"

				"vmv.v.i        v20, 0x0\n"

				"vmv.v.i        v21, 0x0\n"

				"vmv.v.i        v22, 0x0\n"
				"vmv.v.i        v23, 0x0\n"
				"vmv.v.i        v24, 0x0\n"
				"vmv.v.i        v25, 0x0\n"
				"vmv.v.i        v26, 0x0\n"
				"vmv.v.i        v27, 0x0\n"
				"vmv.v.i        v28, 0x0\n"
				"vmv.v.i        v29, 0x0\n"
				"vmv.v.i        v30, 0x0\n"
				"vmv.v.i        v31, 0x0\n"

				// Skip loop if we are doing zero iterations of it.
				"beqz   %[k], 4f\n"

				// Loop proper
				"1:\n"

				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v8, f0, v2\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v9, f0, v2\n"
				"add            a1, %[b_ptr], 32\n"
				"vle32.v          v4, (a1)\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v10, f0, v2\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v11, f0, v2\n"
				"add            a1, %[a_ptr], 32\n"
				"vle32.v          v5, (a1)\n"

				"vse32.v          v1, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v12, f0, v2\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v13, f0, v2\n"
				"add            a1, %[a_ptr], 48\n"
				"vle32.v          v6, (a1)\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v14, f0, v2\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v15, f0, v2\n"
				"add            a1, %[b_ptr], 48\n"
				"vle32.v          v2, (a1)\n"

				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v16, f0, v3\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v17, f0, v3\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v18, f0, v3\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v19, f0, v3\n"

				"vse32.v          v1, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v20, f0, v3\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v21, f0, v3\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v22, f0, v3\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v23, f0, v3\n"
				"add            a1, %[b_ptr], 64\n"
				"vle32.v          v3, (a1)\n"

				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v4\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v25, f0, v4\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v26, f0, v4\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v27, f0, v4\n"

				"vse32.v          v1, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v28, f0, v4\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v29, f0, v4\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v30, f0, v4\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v31, f0, v4\n"
				"add            a1, %[b_ptr], 80\n"
				"vle32.v          v4, (a1)\n"

				"vse32.v          v5, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v8, f0, v2\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v9, f0, v2\n"
				"add            a1, %[a_ptr], 64\n"
				"vle32.v          v0, (a1)\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v10, f0, v2\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v11, f0, v2\n"

				"vse32.v          v6, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v12, f0, v2\n"
				"add            a1, %[a_ptr], 80\n"
				"vle32.v          v1, (a1)\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v13, f0, v2\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v14, f0, v2\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v15, f0, v2\n"
				"add            a1, %[b_ptr], 96\n"
				"vle32.v          v2, (a1)\n"

				"vse32.v          v5, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v16, f0, v3\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v17, f0, v3\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v18, f0, v3\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v19, f0, v3\n"

				"vse32.v          v6, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v20, f0, v3\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v21, f0, v3\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v22, f0, v3\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v23, f0, v3\n"
				"add            a1, %[b_ptr], 112\n"
				"vle32.v          v3, (a1)\n"

				"vse32.v          v5, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v4\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v25, f0, v4\n"
				"add    %[a_ptr], %[a_ptr], 64\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v26, f0, v4\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v27, f0, v4\n"

				"add    %[b_ptr], %[b_ptr], 96\n"
				"vse32.v          v6, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v28, f0, v4\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v29, f0, v4\n"
				"addi   %[k], %[k], -1\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v30, f0, v4\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v31, f0, v4\n"

				"bnez           %[k], 1b\n"

				// Target to use when K is 1 or 2 (i.e. zero iterations of main loop)
				"4:\n"

				// Branch to alternative tail for odd K
				"bnez           %[oddk], 2f\n"

				// Detached final iteration (even K)
				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v8, f0, v2\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v9, f0, v2\n"
				"add            a1, %[b_ptr], 32\n"
				"vle32.v          v4, (a1)\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v10, f0, v2\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v11, f0, v2\n"
				"add            a1, %[a_ptr], 32\n"
				"vle32.v          v5, (a1)\n"

				"vse32.v          v1, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v12, f0, v2\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v13, f0, v2\n"
				"add            a1, %[a_ptr], 48\n"
				"vle32.v          v6, (a1)\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v14, f0, v2\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v15, f0, v2\n"
				"add            a1, %[b_ptr], 48\n"
				"vle32.v          v2, (a1)\n"

				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v16, f0, v3\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v17, f0, v3\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v18, f0, v3\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v19, f0, v3\n"

				"vse32.v          v1, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v20, f0, v3\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v21, f0, v3\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v22, f0, v3\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v23, f0, v3\n"
				"add            a1, %[b_ptr], 64\n"
				"vle32.v          v3, (a1)\n"

				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v4\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v25, f0, v4\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v26, f0, v4\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v27, f0, v4\n"
				"add    %[a_ptr], %[a_ptr], 64\n"

				"vse32.v          v1, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v28, f0, v4\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v29, f0, v4\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v30, f0, v4\n"
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v31, f0, v4\n"
				"add            a1, %[b_ptr], 80\n"
				"vle32.v          v4, (a1)\n"

				"vse32.v          v5, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v8, f0, v2\n"
				"vfmacc.vf      v16, f0, v3\n"
				"add            %[b_ptr], %[b_ptr], 96\n"

				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v9, f0, v2\n"
				"vse32.v          v8, (%[c_ptr])\n"
				"vfmacc.vf      v17, f0, v3\n"
				"add            a1, %[c_ptr], 16\n"
				"vse32.v          v16, (a1)\n"

				"vse32.v          v5, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v4\n"
				"add            a1, %[c_ptr], 32\n"
				"vse32.v          v24, (a1)\n"

				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v25, f0, v4\n"
				"add            a1, %[c_ptr], 48\n"
				"vse32.v          v9, (a1)\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v10, f0, v2\n"
				"add            a1, %[c_ptr], 64\n"
				"vse32.v          v17, (a1)\n"
				"vfmacc.vf      v18, f0, v3\n"
				"add            a1, %[c_ptr], 80\n"
				"vse32.v          v25, (a1)\n"
				"vfmacc.vf      v26, f0, v4\n"
				"add            a1, %[c_ptr], 96\n"
				"vse32.v          v10, (a1)\n"

				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v11, f0, v2\n"
				"add            a1, %[c_ptr], 112\n"
				"vse32.v          v18, (a1)\n"
				"vfmacc.vf      v19, f0, v3\n"
				"add            a1, %[c_ptr], 128\n"
				"vse32.v          v26, (a1)\n"
				"vfmacc.vf      v27, f0, v4\n"
				"add            a1, %[c_ptr], 144\n"
				"vse32.v          v11, (a1)\n"

				"vse32.v          v6, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v12, f0, v2\n"
				"add            a1, %[c_ptr], 160\n"
				"vse32.v          v19, (a1)\n"
				"vfmacc.vf      v20, f0, v3\n"
				"add            a1, %[c_ptr], 176\n"
				"vse32.v          v27, (a1)\n"
				"vfmacc.vf      v28, f0, v4\n"
				"add            a1, %[c_ptr], 192\n"
				"vse32.v          v12, (a1)\n"

				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v13, f0, v2\n"
				"add            a1, %[c_ptr], 208\n"
				"vse32.v          v20, (a1)\n"
				"vfmacc.vf      v21, f0, v3\n"
				"add            a1, %[c_ptr], 224\n"
				"vse32.v          v28, (a1)\n"
				"vfmacc.vf      v29, f0, v4\n"
				"add            a1, %[c_ptr], 240\n"
				"vse32.v          v13, (a1)\n"

				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v14, f0, v2\n"
				"add            a1, %[c_ptr], 256\n"
				"vse32.v          v21, (a1)\n"
				"vfmacc.vf      v22, f0, v3\n"
				"add            a1, %[c_ptr], 272\n"
				"vse32.v          v29, (a1)\n"
				"vfmacc.vf      v30, f0, v4\n"
				"add            a1, %[c_ptr], 288\n"
				"vse32.v          v14, (a1)\n"

				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v15, f0, v2\n"
				"add            a1, %[c_ptr], 304\n"
				"vse32.v          v22, (a1)\n"
				"vfmacc.vf      v23, f0, v3\n"
				"add            a1, %[c_ptr], 320\n"
				"vse32.v          v30, (a1)\n"
				"vfmacc.vf      v31, f0, v4\n"
				"add            a1, %[c_ptr], 336\n"
				"vse32.v          v15, (a1)\n"

				"j              3f\n"

				// Detached final iteration (odd K)
				"2:\n"
				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v8, f0, v2\n"
				"add            a1, %[b_ptr], 32\n"
				"vle32.v          v4, (a1)\n"
				"vfmacc.vf      v16, f0, v3\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v9, f0, v2\n"
				"vse32.v          v8, (%[c_ptr])\n"
				"vfmacc.vf      v17, f0, v3\n"
				"add            a1, %[c_ptr], 16\n"
				"vse32.v          v16, (a1)\n"

				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v4\n"
				"add    %[b_ptr], %[b_ptr], 48\n"
				"add    %[a_ptr], %[a_ptr], 32\n"
				"add            a1, %[c_ptr], 32\n"
				"vse32.v          v24, (a1)\n"
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v25, f0, v4\n"
				"add            a1, %[c_ptr], 48\n"
				"vse32.v          v9, (a1)\n"
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v10, f0, v2\n"
				"add            a1, %[c_ptr], 64\n"
				"vse32.v          v17, (a1)\n"
				"vfmacc.vf      v18, f0, v3\n"
				"add            a1, %[c_ptr], 80\n"
				"vse32.v          v25, (a1)\n"
				"vfmacc.vf      v26, f0, v4\n"
				"add            a1, %[c_ptr], 96\n"
				"vse32.v          v10, (a1)\n"

				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v11, f0, v2\n"
				"add            a1, %[c_ptr], 112\n"
				"vse32.v          v18, (a1)\n"
				"vfmacc.vf      v19, f0, v3\n"
				"add            a1, %[c_ptr], 128\n"
				"vse32.v          v26, (a1)\n"
				"vfmacc.vf      v27, f0, v4\n"
				"add            a1, %[c_ptr], 144\n"
				"vse32.v          v11, (a1)\n"

				"vse32.v          v1, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v12, f0, v2\n"
				"add            a1, %[c_ptr], 160\n"
				"vse32.v          v19, (a1)\n"
				"vfmacc.vf      v20, f0, v3\n"
				"add            a1, %[c_ptr], 176\n"
				"vse32.v          v27, (a1)\n"
				"vfmacc.vf      v28, f0, v4\n"
				"add            a1, %[c_ptr], 192\n"
				"vse32.v          v12, (a1)\n"

				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v13, f0, v2\n"
				"add            a1, %[c_ptr], 208\n"
				"vse32.v          v20, (a1)\n"
				"vfmacc.vf      v21, f0, v3\n"
				"add            a1, %[c_ptr], 224\n"
				"vse32.v          v28, (a1)\n"
				"vfmacc.vf      v29, f0, v4\n"
				"add            a1, %[c_ptr], 240\n"
				"vse32.v          v13, (a1)\n"

				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v14, f0, v2\n"
				"add            a1, %[c_ptr], 256\n"
				"vse32.v          v21, (a1)\n"
				"vfmacc.vf      v22, f0, v3\n"
				"add            a1, %[c_ptr], 272\n"
				"vse32.v          v29, (a1)\n"
				"vfmacc.vf      v30, f0, v4\n"
				"add            a1, %[c_ptr], 288\n"
				"vse32.v          v14, (a1)\n"

				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v15, f0, v2\n"
				"add            a1, %[c_ptr], 304\n"
				"vse32.v          v22, (a1)\n"
				"vfmacc.vf      v23, f0, v3\n"
				"add            a1, %[c_ptr], 320\n"
				"vse32.v          v30, (a1)\n"
				"vfmacc.vf      v31, f0, v4\n"
				"add            a1, %[c_ptr], 336\n"
				"vse32.v          v15, (a1)\n"

				// Common tail
				"3:\n"
				"add            a1, %[c_ptr], 352\n"
				"vse32.v          v23, (a1)\n"
				"add            a1, %[c_ptr], 368\n"
				"vse32.v          v31, (a1)\n"
				"add    %[c_ptr], %[c_ptr], 384\n"

				: [a_ptr] "+r" (a_ptr), [b_ptr] "+r" (b_ptr), [c_ptr] "+r" (c_ptr), [s0] "+r" (s0), [s1] "+r" (s1), [s2] "+r" (s2), [s3] "+r" (s3),
				  [k] "+r" (k)
				: [oddk] "r" (oddk)
				: "v0", "v1","v2", "v3", "v4", "v5", "v6", "v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15", "v16", "v17", "v18",
				  "v19", "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31", "t0", "a0", "a1", "f0"
			);
        }
    }
}

} // namespace arm_gemm

#endif
