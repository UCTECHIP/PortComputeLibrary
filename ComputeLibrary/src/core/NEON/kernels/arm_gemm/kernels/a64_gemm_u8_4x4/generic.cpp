/*
 * Copyright (c) 2017 ARM Limited.
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

namespace arm_gemm {

void a64_gemm_u8_4x4(const uint8_t *Apanel, const uint8_t *Bpanel, uint32_t *Cpanel, int ablocks, int bblocks, int K) {
    const uint8_t *a_ptr = Apanel;
    uint32_t *c_ptr = Cpanel;
    K /= 16;

    for (int yb=0; yb<ablocks; yb++) {
        const uint8_t *a_ptr0 = a_ptr;
        const uint8_t *b_ptr = Bpanel;

        for (int xb=0; xb<bblocks; xb++) {
            a_ptr = a_ptr0;

            int k = K-1;

	unsigned int s0[4] = {0xffffffff,0xffffffff,0,0};
	unsigned int *sa = s0;
	unsigned int s1[4] = {0,0,0xffffffff,0xffffffff};
	unsigned int *sb = s1;
	unsigned int q0[4] = {0,2,1,3};
	unsigned int *q = q0;
	unsigned short p0[8] = {0,2,4,6,1,3,5,7};
	unsigned short *p = p0;
	
	__asm__ __volatile__(
		"li  a0, 16\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vle8.v    v0, (%[a_ptr])\n"
		"vle8.v    v4, (%[b_ptr])\n"
		"add    a1, %[b_ptr], 16\n"
		"vle8.v    v5, (a1)\n"
		"add    a1, %[b_ptr], 32\n"
		"vle8.v    v6, (a1)\n"
		"add    a1, %[b_ptr], 48\n"
		"vle8.v    v7, (a1)\n"
		"add    a1, %[a_ptr], 16\n"
		"vle8.v    v1, (a1)\n"
		"add    a1, %[a_ptr], 32\n"
		"vle8.v    v2, (a1)\n"
		"add    a1, %[a_ptr], 48\n"
		"vle8.v    v3, (a1)\n"

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

		"add    %[a_ptr], %[a_ptr], 64\n"
		"add    %[b_ptr], %[b_ptr], 64\n"

		// Skip loop if we are doing zero iterations of it.
		"beqz    %[k], 2f\n"

		// Unroll 0 continuation (branch target)
		"1:\n"

		"vwmulu.vv      v14, v0, v4\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v16, v16, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v0, v5\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v17, v17, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v0, v6\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v18, v18, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v0, v7\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v19, v19, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vle8.v    v0, (%[a_ptr])\n"

		"vwmulu.vv      v14, v1, v4\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v20, v20, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v1, v5\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v21, v21, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v1, v6\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v22, v22, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v1, v7\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v23, v23, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"addi   %[k], %[k], -1\n"
		"add    a1, %[a_ptr], 16\n"
		"vle8.v    v1, (a1)\n"

		"vwmulu.vv      v14, v2, v4\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v24, v24, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v2, v5\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v25, v25, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v2, v6\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v26, v26, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v2, v7\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v27, v27, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"add    a1, %[a_ptr], 32\n"
		"vle8.v    v2, (a1)\n"

		"vwmulu.vv      v14, v3, v4\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v28, v28, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v3, v5\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v29, v29, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v3, v6\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v30, v30, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v3, v7\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v31, v31, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vle8.v    v4, (%[b_ptr])\n"
		"add    a1, %[b_ptr], 16\n"
		"vle8.v    v5, (a1)\n"
		"add    a1, %[b_ptr], 32\n"
		"vle8.v    v6, (a1)\n"
		"add    a1, %[b_ptr], 48\n"
		"vle8.v    v7, (a1)\n"

		"bnez   %[k], 1b\n"

		// Branch target
		"2:\n"

		"vwmulu.vv      v14, v0, v4\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v16, v16, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v0, v5\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v17, v17, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v0, v6\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v18, v18, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v0, v7\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v19, v19, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v1, v4\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v20, v20, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v1, v5\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v21, v21, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v1, v6\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v22, v22, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v1, v7\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v23, v23, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v2, v4\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v24, v24, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v2, v5\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v25, v25, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v2, v6\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v26, v26, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v2, v7\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v27, v27, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v3, v4\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v28, v28, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v3, v5\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v29, v29, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v3, v6\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v30, v30, v14\n"
		"vsetvli  t0, a0, e8, m1\n"

		"vwmulu.vv      v14, v3, v7\n"
		"vsetvli  t0, a0, e16, m1\n"
		"vle16.v    v13, (%[p])\n"
		"vadd.vv        v14, v14, v15\n"
		"vrgather.vv    v12, v14, v13\n"
		"vslidedown.vi  v13, v12, 4\n"
		"vwaddu.vv      v14, v12, v13\n"
		"vsetvli  t0, a0, e32, m1\n"
		"vadd.vv        v31, v31, v14\n"

		"vle32.v    v13, (%[q])\n"        //addp
		"vrgather.vv    v14, v16, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v17, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v16, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v18, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v19, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v17, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v20, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v21, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v18, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v22, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v23, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v19, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v24, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v25, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v20, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v26, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v27, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v21, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v28, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v29, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v22, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v30, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v31, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v23, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v16, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v17, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v16, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v18, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v19, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v17, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v20, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v21, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v18, v12, v15\n"

		"vle32.v    v13, (%[q])\n"
		"vrgather.vv    v14, v22, v13\n"
		"vslidedown.vi  v15, v14, 2\n"
		"vadd.vv        v12, v14, v15\n"
		"vrgather.vv    v14, v23, v13\n"
		"vslideup.vi    v15, v14, 2\n"
		"vadd.vv        v15, v14, v15\n"
		"vle32.v    v13, (%[sa])\n"
		"vand.vv        v12, v12, v13\n"
		"vle32.v    v13, (%[sb])\n"
		"vand.vv        v15, v15, v13\n"
		"vadd.vv        v19, v12, v15\n"

		"vse32.v    v16, (%[c_ptr])\n"
		"add    a1, %[c_ptr], 16\n"
		"vse32.v    v17, (a1)\n"
		"add    a1, %[c_ptr], 32\n"
		"vse32.v    v18, (a1)\n"
		"add    a1, %[c_ptr], 48\n"
		"vse32.v    v19, (a1)\n"
		"add    %[c_ptr], %[c_ptr], 64\n"

    :
	[a_ptr] "+r" (a_ptr), [b_ptr] "+r" (b_ptr), [c_ptr] "+r" (c_ptr),
	[k] "+r" (k), [p] "+r" (p), [q] "+r" (q), [sa] "+r" (sa), [sb] "+r" (sb)
    :
	: "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v12", "v13", "v14", "v15", "v16", "v17", "v18", "v19",
	  "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31", "t0", "a0", "a1"
	);
        }
    }
}

} // namespace arm_gemm

#endif // __aarch64__
