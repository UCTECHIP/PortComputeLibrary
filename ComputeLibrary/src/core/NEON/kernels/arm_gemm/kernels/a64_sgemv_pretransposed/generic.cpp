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

#include <algorithm>

#include <arm_neon.h>

#include "../../asmlib.hpp"
#include "../../utils.hpp"

namespace arm_gemm {

void a64_sgemv_pretransposed(const float *A, int lda, const float *X, float *Y, float beta, int M, int N) {
    const bool beta0 = (beta==0.0f);
    const bool beta1 = (beta==1.0f);

    for (int x=0; x<N; x+=32) {
        float *y_ptr = Y + x;

        // How many elements are we processing in this loop?
        int l = std::min(N - x, 32);



		float32x4_t r0;
		float32x4_t r1;
		float32x4_t r2;
		float32x4_t r3;
		float32x4_t r4;
		float32x4_t r5;
		float32x4_t r6;
		float32x4_t r7;

		float32x4_t x0;
		float32x4_t x0a;
        float s[4] = {0,0,0,0};
        float *s0 = s;
        float *s1 = s0 + 1;
        float *s2 = s1 + 1;
        float *s3 = s2 + 1;

        float *r00 = &r0[0];
        float *r01 = &r1[0];
        float *r02 = &r2[0];
        float *r03 = &r3[0];
        float *r04 = &r4[0];
        float *r05 = &r5[0];
        float *r06 = &r6[0];
        float *r07 = &r7[0];

        float *x00 = &x0[0];
        float *x01 = &x0a[0];

        const float *x_ptr = X;
        const float *a_ptr = A + ((x/32) * lda);

        if (beta0) {
            r0=r1=r2=r3=r4=r5=r6=r7=vdupq_n_f32(0.0f);
        } else {
            if (l==32) {
                // Fastest path - load all 8 vectors
                r0 = vld1q_f32(y_ptr);
                r1 = vld1q_f32(y_ptr + 4);
                r2 = vld1q_f32(y_ptr + 8);
                r3 = vld1q_f32(y_ptr + 12);
                r4 = vld1q_f32(y_ptr + 16);
                r5 = vld1q_f32(y_ptr + 20);
                r6 = vld1q_f32(y_ptr + 24);
                r7 = vld1q_f32(y_ptr + 28);
            } else {
                // Slow case - leftovers.  Note that we don't care about
                // out-of-range vectors and lanes as we will throw them away at
                // the end.
                int vecs=l/4; // How many leftover vectors?
                int oddbits=l%4; // And how many odd single values?

                if (oddbits) {
                    // Load the outstanding odd values into a vector first
                    float32x4_t oddvec = vdupq_n_f32(0.0f); // This does not really need to be initialized, but the compiler has a hard time with that.
                    float *oddbase = y_ptr + l - oddbits;

                    switch (oddbits) {
                        case 3:
                            oddvec = vld1q_lane_f32(oddbase + 2, oddvec, 2);
                            // fall through
                        case 2:
                            oddvec = vld1q_lane_f32(oddbase + 1, oddvec, 1);
                            // fall through
                        case 1:
                            oddvec = vld1q_lane_f32(oddbase, oddvec, 0);
                            break;

                        default:
                            UNREACHABLE("Impossible case in switch.");
                    }

                    // Now load the whole vectors, putting the oddments in when we run out.
                    do {
                        if (vecs==0) { r0 = oddvec; break; }

                        r0 = vld1q_f32(y_ptr);
                        if (--vecs==0) { r1 = oddvec; break; }

                        r1 = vld1q_f32(y_ptr + 4);
                        if (--vecs==0) { r2 = oddvec; break; }

                        r2 = vld1q_f32(y_ptr + 8);
                        if (--vecs==0) { r3 = oddvec; break; }

                        r3 = vld1q_f32(y_ptr + 12);
                        if (--vecs==0) { r4 = oddvec; break; }

                        r4 = vld1q_f32(y_ptr + 16);
                        if (--vecs==0) { r5 = oddvec; break; }

                        r5 = vld1q_f32(y_ptr + 20);
                        if (--vecs==0) { r6 = oddvec; break; }

                        r6 = vld1q_f32(y_ptr + 24);
                        r7 = oddvec;
                    } while (0);
                } else {
                    // Slightly less slow path - just load the whole vectors
                    do {
                        // It can't be the case that oddbits==0 AND vecs==0 or we wouldn't be here.
                        if (vecs==0) { UNREACHABLE("Impossible lack of work to do"); }

                        r0 = vld1q_f32(y_ptr);
                        if (--vecs==0) { break; }

                        r1 = vld1q_f32(y_ptr + 4);
                        if (--vecs==0) { break; }

                        r2 = vld1q_f32(y_ptr + 8);
                        if (--vecs==0) { break; }

                        r3 = vld1q_f32(y_ptr + 12);
                        if (--vecs==0) { break; }

                        r4 = vld1q_f32(y_ptr + 16);
                        if (--vecs==0) { break; }

                        r5 = vld1q_f32(y_ptr + 20);
                        if (--vecs==0) { break; }

                        r6 = vld1q_f32(y_ptr + 24);
                    } while (0);
                }
            }

            if (!beta1) {
                const float32x4_t vb = vdupq_n_f32(beta);

                r0 = vmulq_f32(r0, vb);
                r1 = vmulq_f32(r1, vb);
                r2 = vmulq_f32(r2, vb);
                r3 = vmulq_f32(r3, vb);
                r4 = vmulq_f32(r4, vb);
                r5 = vmulq_f32(r5, vb);
                r6 = vmulq_f32(r6, vb);
                r7 = vmulq_f32(r7, vb);
            }
        }

        if (M>=8) {
            int k = (M/8)-1;
            x0 = vld1q_f32(x_ptr);

        __asm__ __volatile__(
				"li  a0, 4\n"
				"vsetvli  t0, a0, e32, m1\n"

				"vle32.v    v0, (%[x00])\n"
				"vle32.v    v1, (%[x01])\n"
				"vle32.v    v24, (%[r00])\n"
				"vle32.v    v25, (%[r01])\n"
				"vle32.v    v26, (%[r02])\n"
				"vle32.v    v27, (%[r03])\n"
				"vle32.v    v28, (%[r04])\n"
				"vle32.v    v29, (%[r05])\n"
				"vle32.v    v30, (%[r06])\n"
				"vle32.v    v31, (%[r07])\n"

				"vle32.v    v2, (%[a_ptr])\n"
				"add    a1, %[a_ptr], 16\n"
				"vle32.v    v3, (a1)\n"
				"add    a1, %[a_ptr], 32\n"
				"vle32.v    v4, (a1)\n"
				"add    a1, %[a_ptr], 48\n"
				"vle32.v    v5, (a1)\n"
				"add    a1, %[a_ptr], 64\n"
				"vle32.v    v6, (a1)\n"
				"add    a1, %[a_ptr], 80\n"
				"vle32.v    v7, (a1)\n"
				"add    a1, %[a_ptr], 96\n"
				"vle32.v    v8, (a1)\n"
				"add    a1, %[a_ptr], 112\n"
				"vle32.v    v9, (a1)\n"
				"add    a1, %[a_ptr], 128\n"
				"vle32.v    v10, (a1)\n"
				"add    a1, %[a_ptr], 144\n"
				"vle32.v    v11, (a1)\n"
				"add    a1, %[a_ptr], 160\n"
				"vle32.v    v12, (a1)\n"
				"add    a1, %[a_ptr], 176\n"
				"vle32.v    v13, (a1)\n"
				"add    a1, %[a_ptr], 192\n"
				"vle32.v    v14, (a1)\n"
				"add    a1, %[a_ptr], 208\n"
				"vle32.v    v15, (a1)\n"
				"add    a1, %[a_ptr], 224\n"
				"vle32.v    v16, (a1)\n"
				"add    a1, %[a_ptr], 240\n"
				"vle32.v    v17, (a1)\n"
				"add    a1, %[a_ptr], 256\n"
				"vle32.v    v18, (a1)\n"
				"add    a1, %[a_ptr], 272\n"
				"vle32.v    v19, (a1)\n"
				"add    a1, %[a_ptr], 288\n"
				"vle32.v    v20, (a1)\n"
				"add    a1, %[a_ptr], 304\n"
				"vle32.v    v21, (a1)\n"
				"add    a1, %[a_ptr], 320\n"
				"vle32.v    v22, (a1)\n"
				"add    a1, %[a_ptr], 336\n"
				"vle32.v    v23, (a1)\n"

				"add    %[a_ptr], %[a_ptr], 352\n"

				"beqz    %[k], 2f\n"

				"1:\n"

				// Unroll 0
				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v2\n"
				"vfmacc.vf      v25, f0, v3\n"
				"vfmacc.vf      v26, f0, v4\n"
				"vfmacc.vf      v27, f0, v5\n"
				"vfmacc.vf      v28, f0, v6\n"
				"vfmacc.vf      v29, f0, v7\n"
				"vfmacc.vf      v30, f0, v8\n"
				"vfmacc.vf      v31, f0, v9\n"

				"add    a1, %[x_ptr], 16\n"
				"vle32.v    v1, (a1)\n"
				"vle32.v    v3, (%[a_ptr])\n"
				"addi   %[k], %[k], -1\n"
				"add    a1, %[a_ptr], 16\n"
				"vle32.v    v4, (a1)\n"
				"add    a1, %[a_ptr], 32\n"
				"vle32.v    v5, (a1)\n"
				"add    %[x_ptr], %[x_ptr], 32\n"
				"add    a1, %[a_ptr], 48\n"
				"vle32.v    v6, (a1)\n"
				"add    a1, %[a_ptr], 64\n"
				"vle32.v    v7, (a1)\n"
				"add    a1, %[a_ptr], 80\n"
				"vle32.v    v8, (a1)\n"
				"add    a1, %[a_ptr], 96\n"
				"vle32.v    v9, (a1)\n"

				// Unroll 1
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v24, f0, v10\n"
				"vfmacc.vf      v25, f0, v11\n"
				"vfmacc.vf      v26, f0, v12\n"
				"vfmacc.vf      v27, f0, v13\n"
				"vfmacc.vf      v28, f0, v14\n"
				"vfmacc.vf      v29, f0, v15\n"
				"vfmacc.vf      v30, f0, v16\n"
				"vfmacc.vf      v31, f0, v17\n"

				"add    a1, %[a_ptr], 112\n"
				"vle32.v    v10, (a1)\n"
				"add    a1, %[a_ptr], 128\n"
				"vle32.v    v11, (a1)\n"
				"add    a1, %[a_ptr], 144\n"
				"vle32.v    v12, (a1)\n"
				"add    a1, %[a_ptr], 160\n"
				"vle32.v    v13, (a1)\n"
				"add    a1, %[a_ptr], 176\n"
				"vle32.v    v14, (a1)\n"
				"add    a1, %[a_ptr], 192\n"
				"vle32.v    v15, (a1)\n"
				"add    a1, %[a_ptr], 208\n"
				"vle32.v    v16, (a1)\n"
				"add    a1, %[a_ptr], 224\n"
				"vle32.v    v17, (a1)\n"

				// Unroll 2
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v24, f0, v18\n"
				"vfmacc.vf      v25, f0, v19\n"
				"vfmacc.vf      v26, f0, v20\n"
				"vfmacc.vf      v27, f0, v21\n"
				"vfmacc.vf      v28, f0, v22\n"
				"vfmacc.vf      v29, f0, v23\n"
				"vfmacc.vf      v30, f0, v3\n"
				"vfmacc.vf      v31, f0, v4\n"

				"add    a1, %[a_ptr], 240\n"
				"vle32.v    v18, (a1)\n"
				"add    a1, %[a_ptr], 256\n"
				"vle32.v    v19, (a1)\n"
				"add    a1, %[a_ptr], 272\n"
				"vle32.v    v20, (a1)\n"
				"add    a1, %[a_ptr], 288\n"
				"vle32.v    v21, (a1)\n"
				"add    a1, %[a_ptr], 304\n"
				"vle32.v    v22, (a1)\n"
				"add    a1, %[a_ptr], 320\n"
				"vle32.v    v23, (a1)\n"
				"add    a1, %[a_ptr], 336\n"
				"vle32.v    v2, (a1)\n"
				"add    a1, %[a_ptr], 352\n"
				"vle32.v    v3, (a1)\n"
				"add    a1, %[a_ptr], 368\n"
				"vle32.v    v4, (a1)\n"

				// Unroll 3
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v24, f0, v5\n"
				"vfmacc.vf      v25, f0, v6\n"
				"vfmacc.vf      v26, f0, v7\n"
				"vfmacc.vf      v27, f0, v8\n"
				"vfmacc.vf      v28, f0, v9\n"
				"vfmacc.vf      v29, f0, v10\n"
				"vfmacc.vf      v30, f0, v11\n"
				"vfmacc.vf      v31, f0, v12\n"

				"add    a1, %[a_ptr], 384\n"
				"vle32.v    v5, (a1)\n"
				"add    a1, %[a_ptr], 400\n"
				"vle32.v    v6, (a1)\n"
				"add    a1, %[a_ptr], 416\n"
				"vle32.v    v7, (a1)\n"
				"add    a1, %[a_ptr], 432\n"
				"vle32.v    v8, (a1)\n"
				"add    a1, %[a_ptr], 448\n"
				"vle32.v    v9, (a1)\n"
				"add    a1, %[a_ptr], 464\n"
				"vle32.v    v10, (a1)\n"
				"add    a1, %[a_ptr], 480\n"
				"vle32.v    v11, (a1)\n"
				"add    a1, %[a_ptr], 496\n"
				"vle32.v    v12, (a1)\n"

				// Unroll 4
				"vse32.v          v1, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v13\n"
				"vfmacc.vf      v25, f0, v14\n"
				"vfmacc.vf      v26, f0, v15\n"
				"vfmacc.vf      v27, f0, v16\n"
				"vfmacc.vf      v28, f0, v17\n"
				"vfmacc.vf      v29, f0, v18\n"
				"vfmacc.vf      v30, f0, v19\n"
				"vfmacc.vf      v31, f0, v20\n"

				"vle32.v    v0, (%[x_ptr])\n"
				"add    a1, %[a_ptr], 512\n"
				"vle32.v    v14, (a1)\n"
				"add    a1, %[a_ptr], 528\n"
				"vle32.v    v15, (a1)\n"
				"add    a1, %[a_ptr], 544\n"
				"vle32.v    v16, (a1)\n"
				"add    a1, %[a_ptr], 560\n"
				"vle32.v    v17, (a1)\n"
				"add    a1, %[a_ptr], 576\n"
				"vle32.v    v18, (a1)\n"
				"add    a1, %[a_ptr], 592\n"
				"vle32.v    v19, (a1)\n"
				"add    a1, %[a_ptr], 608\n"
				"vle32.v    v20, (a1)\n"

				// Unroll 5
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v24, f0, v21\n"
				"vfmacc.vf      v25, f0, v22\n"
				"vfmacc.vf      v26, f0, v23\n"
				"vfmacc.vf      v27, f0, v2\n"
				"vfmacc.vf      v28, f0, v3\n"
				"vfmacc.vf      v29, f0, v4\n"
				"vfmacc.vf      v30, f0, v5\n"
				"vfmacc.vf      v31, f0, v6\n"

				"add    a1, %[a_ptr], 624\n"
				"vle32.v    v21, (a1)\n"
				"add    a1, %[a_ptr], 640\n"
				"vle32.v    v22, (a1)\n"
				"add    a1, %[a_ptr], 656\n"
				"vle32.v    v23, (a1)\n"
				"add    a1, %[a_ptr], 672\n"
				"vle32.v    v2, (a1)\n"
				"add    a1, %[a_ptr], 688\n"
				"vle32.v    v3, (a1)\n"
				"add    a1, %[a_ptr], 704\n"
				"vle32.v    v4, (a1)\n"
				"add    a1, %[a_ptr], 720\n"
				"vle32.v    v5, (a1)\n"
				"add    a1, %[a_ptr], 736\n"
				"vle32.v    v6, (a1)\n"

				// Unroll 6
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v24, f0, v7\n"
				"vfmacc.vf      v25, f0, v8\n"
				"vfmacc.vf      v26, f0, v9\n"
				"vfmacc.vf      v27, f0, v10\n"
				"vfmacc.vf      v28, f0, v11\n"
				"vfmacc.vf      v29, f0, v12\n"
				"vfmacc.vf      v30, f0, v14\n"
				"vfmacc.vf      v31, f0, v15\n"

				"add    a1, %[a_ptr], 752\n"
				"vle32.v    v7, (a1)\n"
				"add    a1, %[a_ptr], 768\n"
				"vle32.v    v8, (a1)\n"
				"add    a1, %[a_ptr], 784\n"
				"vle32.v    v9, (a1)\n"
				"add    a1, %[a_ptr], 800\n"
				"vle32.v    v10, (a1)\n"
				"add    a1, %[a_ptr], 816\n"
				"vle32.v    v11, (a1)\n"
				"add    a1, %[a_ptr], 832\n"
				"vle32.v    v12, (a1)\n"
				"add    a1, %[a_ptr], 848\n"
				"vle32.v    v13, (a1)\n"
				"add    a1, %[a_ptr], 864\n"
				"vle32.v    v14, (a1)\n"
				"add    a1, %[a_ptr], 880\n"
				"vle32.v    v15, (a1)\n"

				// Unroll 7
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v24, f0, v16\n"
				"vfmacc.vf      v25, f0, v17\n"
				"vfmacc.vf      v26, f0, v18\n"
				"vfmacc.vf      v27, f0, v19\n"
				"vfmacc.vf      v28, f0, v20\n"
				"vfmacc.vf      v29, f0, v21\n"
				"vfmacc.vf      v30, f0, v22\n"
				"vfmacc.vf      v31, f0, v23\n"

				"add    a1, %[a_ptr], 896\n"
				"vle32.v    v16, (a1)\n"
				"add    a1, %[a_ptr], 912\n"
				"vle32.v    v17, (a1)\n"
				"add    a1, %[a_ptr], 928\n"
				"vle32.v    v18, (a1)\n"
				"add    a1, %[a_ptr], 944\n"
				"vle32.v    v19, (a1)\n"
				"add    a1, %[a_ptr], 960\n"
				"vle32.v    v20, (a1)\n"
				"add    a1, %[a_ptr], 976\n"
				"vle32.v    v21, (a1)\n"
				"add    %[a_ptr], %[a_ptr], 1024\n"
				"add    a1, %[a_ptr], -32\n"
				"vle32.v    v22, (a1)\n"
				"add    a1, %[a_ptr], -16\n"
				"vle32.v    v23, (a1)\n"

				"bnez   %[k], 1b\n"

				// Detached final iteration
				"2:\n"

				// Unroll 0
				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v2\n"
				"vfmacc.vf      v25, f0, v3\n"
				"vfmacc.vf      v26, f0, v4\n"
				"vfmacc.vf      v27, f0, v5\n"
				"vfmacc.vf      v28, f0, v6\n"
				"vfmacc.vf      v29, f0, v7\n"
				"vfmacc.vf      v30, f0, v8\n"
				"vfmacc.vf      v31, f0, v9\n"

				"add    a1, %[x_ptr], 16\n"
				"vle32.v    v1, (a1)\n"
				"vle32.v    v3, (%[a_ptr])\n"
				"addi   %[k], %[k], -1\n"
				"add    a1, %[a_ptr], 16\n"
				"vle32.v    v4, (a1)\n"
				"add    a1, %[a_ptr], 32\n"
				"vle32.v    v5, (a1)\n"
				"add    %[x_ptr], %[x_ptr], 32\n"
				"add    a1, %[a_ptr], 48\n"
				"vle32.v    v6, (a1)\n"
				"add    a1, %[a_ptr], 64\n"
				"vle32.v    v7, (a1)\n"
				"add    a1, %[a_ptr], 80\n"
				"vle32.v    v8, (a1)\n"
				"add    a1, %[a_ptr], 96\n"
				"vle32.v    v9, (a1)\n"

				// Unroll 1
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v24, f0, v10\n"
				"vfmacc.vf      v25, f0, v11\n"
				"vfmacc.vf      v26, f0, v12\n"
				"vfmacc.vf      v27, f0, v13\n"
				"vfmacc.vf      v28, f0, v14\n"
				"vfmacc.vf      v29, f0, v15\n"
				"vfmacc.vf      v30, f0, v16\n"
				"vfmacc.vf      v31, f0, v17\n"

				"add    a1, %[a_ptr], 112\n"
				"vle32.v    v10, (a1)\n"
				"add    a1, %[a_ptr], 128\n"
				"vle32.v    v11, (a1)\n"
				"add    a1, %[a_ptr], 144\n"
				"vle32.v    v12, (a1)\n"
				"add    a1, %[a_ptr], 160\n"
				"vle32.v    v13, (a1)\n"
				"add    a1, %[a_ptr], 176\n"
				"vle32.v    v14, (a1)\n"
				"add    a1, %[a_ptr], 192\n"
				"vle32.v    v15, (a1)\n"
				"add    a1, %[a_ptr], 208\n"
				"vle32.v    v16, (a1)\n"
				"add    a1, %[a_ptr], 224\n"
				"vle32.v    v17, (a1)\n"

				// Unroll 2
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v24, f0, v18\n"
				"vfmacc.vf      v25, f0, v19\n"
				"vfmacc.vf      v26, f0, v20\n"
				"vfmacc.vf      v27, f0, v21\n"
				"vfmacc.vf      v28, f0, v22\n"
				"vfmacc.vf      v29, f0, v23\n"
				"vfmacc.vf      v30, f0, v3\n"
				"vfmacc.vf      v31, f0, v4\n"

				"add    a1, %[a_ptr], 240\n"
				"vle32.v    v18, (a1)\n"
				"add    a1, %[a_ptr], 256\n"
				"vle32.v    v19, (a1)\n"
				"add    a1, %[a_ptr], 272\n"
				"vle32.v    v20, (a1)\n"
				"add    a1, %[a_ptr], 288\n"
				"vle32.v    v21, (a1)\n"
				"add    a1, %[a_ptr], 304\n"
				"vle32.v    v22, (a1)\n"
				"add    a1, %[a_ptr], 320\n"
				"vle32.v    v23, (a1)\n"
				"add    a1, %[a_ptr], 336\n"
				"vle32.v    v2, (a1)\n"
				"add    a1, %[a_ptr], 352\n"
				"vle32.v    v3, (a1)\n"
				"add    a1, %[a_ptr], 368\n"
				"vle32.v    v4, (a1)\n"

				// Unroll 3
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v24, f0, v5\n"
				"vfmacc.vf      v25, f0, v6\n"
				"vfmacc.vf      v26, f0, v7\n"
				"vfmacc.vf      v27, f0, v8\n"
				"vfmacc.vf      v28, f0, v9\n"
				"vfmacc.vf      v29, f0, v10\n"
				"vfmacc.vf      v30, f0, v11\n"
				"vfmacc.vf      v31, f0, v12\n"

				"add    a1, %[a_ptr], 384\n"
				"vle32.v    v5, (a1)\n"
				"add    a1, %[a_ptr], 400\n"
				"vle32.v    v6, (a1)\n"
				"add    a1, %[a_ptr], 416\n"
				"vle32.v    v7, (a1)\n"
				"add    a1, %[a_ptr], 432\n"
				"vle32.v    v8, (a1)\n"
				"add    a1, %[a_ptr], 448\n"
				"vle32.v    v9, (a1)\n"
				"add    a1, %[a_ptr], 464\n"
				"vle32.v    v10, (a1)\n"
				"add    a1, %[a_ptr], 480\n"
				"vle32.v    v11, (a1)\n"
				"add    a1, %[a_ptr], 496\n"
				"vle32.v    v12, (a1)\n"

				// Unroll 4
				"vse32.v          v1, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v13\n"
				"vfmacc.vf      v25, f0, v14\n"
				"vfmacc.vf      v26, f0, v15\n"
				"vfmacc.vf      v27, f0, v16\n"
				"vfmacc.vf      v28, f0, v17\n"
				"vfmacc.vf      v29, f0, v18\n"
				"vfmacc.vf      v30, f0, v19\n"
				"vfmacc.vf      v31, f0, v20\n"

				"add    a1, %[a_ptr], 512\n"
				"vle32.v    v14, (a1)\n"
				"add    a1, %[a_ptr], 528\n"
				"vle32.v    v15, (a1)\n"
				"add    a1, %[a_ptr], 544\n"
				"vle32.v    v16, (a1)\n"
				"add    a1, %[a_ptr], 560\n"
				"vle32.v    v17, (a1)\n"
				"add    a1, %[a_ptr], 576\n"
				"vle32.v    v18, (a1)\n"
				"add    a1, %[a_ptr], 592\n"
				"vle32.v    v19, (a1)\n"
				"add    a1, %[a_ptr], 608\n"
				"vle32.v    v20, (a1)\n"

				// Unroll 5
				"flw            f0, (%[s1])\n"
				"vfmacc.vf      v24, f0, v21\n"
				"vfmacc.vf      v25, f0, v22\n"
				"vfmacc.vf      v26, f0, v23\n"
				"vfmacc.vf      v27, f0, v2\n"
				"vfmacc.vf      v28, f0, v3\n"
				"vfmacc.vf      v29, f0, v4\n"
				"vfmacc.vf      v30, f0, v5\n"
				"vfmacc.vf      v31, f0, v6\n"

				"add    a1, %[a_ptr], 624\n"
				"vle32.v    v21, (a1)\n"
				"add    a1, %[a_ptr], 640\n"
				"vle32.v    v22, (a1)\n"
				"add    a1, %[a_ptr], 656\n"
				"vle32.v    v23, (a1)\n"
				"add    %[a_ptr], %[a_ptr], 672\n"

				// Unroll 6
				"flw            f0, (%[s2])\n"
				"vfmacc.vf      v24, f0, v7\n"
				"vfmacc.vf      v25, f0, v8\n"
				"vfmacc.vf      v26, f0, v9\n"
				"vfmacc.vf      v27, f0, v10\n"
				"vfmacc.vf      v28, f0, v11\n"
				"vfmacc.vf      v29, f0, v12\n"
				"vfmacc.vf      v30, f0, v14\n"
				"vfmacc.vf      v31, f0, v15\n"

				// Unroll 7
				"flw            f0, (%[s3])\n"
				"vfmacc.vf      v24, f0, v16\n"
				"vfmacc.vf      v25, f0, v17\n"
				"vfmacc.vf      v26, f0, v18\n"
				"vfmacc.vf      v27, f0, v19\n"
				"vfmacc.vf      v28, f0, v20\n"
				"vfmacc.vf      v29, f0, v21\n"
				"vfmacc.vf      v30, f0, v22\n"
				"vfmacc.vf      v31, f0, v23\n"

				"vse32.v  v0, (%[x00])\n"
				"vse32.v  v1, (%[x01])\n"
				"vse32.v  v24, (%[r00])\n"
				"vse32.v  v25, (%[r01])\n"
				"vse32.v  v26, (%[r02])\n"
				"vse32.v  v27, (%[r03])\n"
				"vse32.v  v28, (%[r04])\n"
				"vse32.v  v29, (%[r05])\n"
				"vse32.v  v30, (%[r06])\n"
				"vse32.v  v31, (%[r07])\n"

			: [a_ptr] "+r" (a_ptr), [x_ptr] "+r" (x_ptr), [k] "+r" (k),
			  [r00] "+r" (r00), [r01] "+r" (r01), [r02] "+r" (r02), [r03] "+r" (r03),
			  [r04] "+r" (r04), [r05] "+r" (r05), [r06] "+r" (r06), [r07] "+r" (r07),
			  [x00] "+r" (x00), [x01] "+r" (x01)
			: [s0] "r" (s0) , [s1] "r" (s1), [s2] "r" (s2), [s3] "r" (s3)
			: "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15",
				  "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31", "t0", "a0", "a1"
		);
        }

        // Deal with ragged M
        if (M % 8) {
            int l=(M%8)-1;

        __asm__ __volatile__(
				"li  a0, 4\n"
				"vsetvli  t0, a0, e32, m1\n"

				"vle32.v    v0, (%[x00])\n"
				"vle32.v    v24, (%[r00])\n"
				"vle32.v    v25, (%[r01])\n"
				"vle32.v    v26, (%[r02])\n"
				"vle32.v    v27, (%[r03])\n"
				"vle32.v    v28, (%[r04])\n"
				"vle32.v    v29, (%[r05])\n"
				"vle32.v    v30, (%[r06])\n"
				"vle32.v    v31, (%[r07])\n"

				"vle32.v    v2, (%[a_ptr])\n"
				"add    a1, %[a_ptr], 16\n"
				"vle32.v    v3, (a1)\n"
				"add    a1, %[a_ptr], 32\n"
				"vle32.v    v4, (a1)\n"
				"add    a1, %[a_ptr], 48\n"
				"vle32.v    v5, (a1)\n"
				"add    a1, %[a_ptr], 64\n"
				"vle32.v    v6, (a1)\n"
				"add    a1, %[a_ptr], 80\n"
				"vle32.v    v7, (a1)\n"
				"add    a1, %[a_ptr], 96\n"
				"vle32.v    v8, (a1)\n"
				"add    a1, %[a_ptr], 112\n"
				"vle32.v    v9, (a1)\n"

				"vle32.v    v0, (%[x_ptr])\n"
				"add    %[a_ptr], %[a_ptr], 128\n"
				"add    %[x_ptr], %[x_ptr], 4\n"

				"beqz    %[l], 2f\n"

				"1:\n"
				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v2\n"
				"vfmacc.vf      v25, f0, v3\n"
				"vfmacc.vf      v26, f0, v4\n"
				"vfmacc.vf      v27, f0, v5\n"
				"vfmacc.vf      v28, f0, v6\n"
				"vfmacc.vf      v29, f0, v7\n"
				"vfmacc.vf      v30, f0, v8\n"
				"vfmacc.vf      v31, f0, v9\n"

				"vle32.v    v2, (%[a_ptr])\n"
				"addi   %[l], %[l], -1\n"
				"add    a1, %[a_ptr], 16\n"
				"vle32.v    v3, (a1)\n"
				"add    a1, %[a_ptr], 32\n"
				"vle32.v    v4, (a1)\n"
				"add    a1, %[a_ptr], 48\n"
				"vle32.v    v5, (a1)\n"
				"add    a1, %[a_ptr], 64\n"
				"vle32.v    v6, (a1)\n"
				"add    a1, %[a_ptr], 80\n"
				"vle32.v    v7, (a1)\n"
				"add    a1, %[a_ptr], 96\n"
				"vle32.v    v8, (a1)\n"
				"add    a1, %[a_ptr], 112\n"
				"vle32.v    v9, (a1)\n"

				"vle32.v    v0, (%[x_ptr])\n"
				"add    %[a_ptr], %[a_ptr], 128\n"
				"add    %[x_ptr], %[x_ptr], 4\n"

				"bnez    %[l], 1b\n"

				"2:\n"
				"vse32.v          v0, (%[s0])\n"
				"flw            f0, (%[s0])\n"
				"vfmacc.vf      v24, f0, v2\n"
				"vfmacc.vf      v25, f0, v3\n"
				"vfmacc.vf      v26, f0, v4\n"
				"vfmacc.vf      v27, f0, v5\n"
				"vfmacc.vf      v28, f0, v6\n"
				"vfmacc.vf      v29, f0, v7\n"
				"vfmacc.vf      v30, f0, v8\n"
				"vfmacc.vf      v31, f0, v9\n"

                "vse32.v  v0, (%[x00])\n"
                "vse32.v  v24, (%[r00])\n"
                "vse32.v  v25, (%[r01])\n"
                "vse32.v  v26, (%[r02])\n"
                "vse32.v  v27, (%[r03])\n"
                "vse32.v  v28, (%[r04])\n"
                "vse32.v  v29, (%[r05])\n"
                "vse32.v  v30, (%[r06])\n"
                "vse32.v  v31, (%[r07])\n"


			: [a_ptr] "+r" (a_ptr), [x_ptr] "+r" (x_ptr), [l] "+r" (l),[s0] "+r" (s0) ,
			  [r00] "+r" (r00), [r01] "+r" (r01), [r02] "+r" (r02), [r03] "+r" (r03),
			  [r04] "+r" (r04), [r05] "+r" (r05), [r06] "+r" (r06), [r07] "+r" (r07),
			  [x00] "+r" (x00)
			:
			: "v0", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31", "t0", "a0", "a1"
        );

        }

        if (l==32) {
            // Fast path
            vst1q_f32(y_ptr, r0);
            vst1q_f32(y_ptr + 4, r1);
            vst1q_f32(y_ptr + 8, r2);
            vst1q_f32(y_ptr + 12, r3);
            vst1q_f32(y_ptr + 16, r4);
            vst1q_f32(y_ptr + 20, r5);
            vst1q_f32(y_ptr + 24, r6);
            vst1q_f32(y_ptr + 28, r7);
        } else {
            int vecs=l/4;
            int oddbits=l%4;

            if (oddbits) {
                // As above - slowest path deals with vectors plus odd bits
                float32x4_t oddvec;

                do {
                    if (vecs==0) { oddvec=r0; break; }

                    vst1q_f32(y_ptr, r0);
                    if (--vecs==0) { oddvec=r1; break; }

                    vst1q_f32(y_ptr + 4, r1);
                    if (--vecs==0) { oddvec=r2; break; }

                    vst1q_f32(y_ptr + 8, r2);
                    if (--vecs==0) { oddvec=r3; break; }

                    vst1q_f32(y_ptr + 12, r3);
                    if (--vecs==0) { oddvec=r4; break; }

                    vst1q_f32(y_ptr + 16, r4);
                    if (--vecs==0) { oddvec=r5; break; }

                    vst1q_f32(y_ptr + 20, r5);
                    if (--vecs==0) { oddvec=r6; break; }

                    vst1q_f32(y_ptr + 24, r6);
                    oddvec=r7;
                } while (0);

                float *oddbase = y_ptr + l - oddbits;

                switch(oddbits) {
                    case 3:
                        vst1q_lane_f32(oddbase + 2, oddvec, 2);
                        // fall through
                    case 2:
                        vst1q_lane_f32(oddbase + 1, oddvec, 1);
                        // fall through
                    case 1:
                        vst1q_lane_f32(oddbase, oddvec, 0);
                        break;

                    default:
                        // oddbits must be 1, 2 or 3.
                        UNREACHABLE("Impossible case in switch.");
                }
            } else {
                // As above - medium path deals with vectors only
                do {
                    if (vecs==0) { UNREACHABLE("vecs and oddbits can't both be 0"); }

                    vst1q_f32(y_ptr, r0);
                    if (--vecs==0) { break; }

                    vst1q_f32(y_ptr + 4, r1);
                    if (--vecs==0) { break; }

                    vst1q_f32(y_ptr + 8, r2);
                    if (--vecs==0) { break; }

                    vst1q_f32(y_ptr + 12, r3);
                    if (--vecs==0) { break; }

                    vst1q_f32(y_ptr + 16, r4);
                    if (--vecs==0) { break; }

                    vst1q_f32(y_ptr + 20, r5);
                    if (--vecs==0) { break; }

                    vst1q_f32(y_ptr + 24, r6);
                } while (0);
            }
        }
    }
}

} // namespace arm_gemm

#endif // aarch64
