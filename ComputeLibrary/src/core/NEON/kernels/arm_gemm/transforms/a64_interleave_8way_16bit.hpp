/*
 * Copyright (c) 2017-2019 ARM Limited.
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
#pragma once

#ifdef __aarch64__

#include <arm_neon.h>

#include "../asmlib.hpp"

template<>
template<typename T>
void TransformImpl<8, 1, false, 2, 2, false>::Transform(T *out, const T *in, int ldin, int y0, int ymax, int k0, int kmax) {
    uint16_t *outptr = (uint16_t *)out;
    const uint16_t *inptr = (const uint16_t *)in;
    bool first=true;

    uint16_t zerobuff[16] = { 0 }; // 8 for asm loop plus up to 7 for overflow loop

    for (int y=y0; y<ymax; y+=8) {
        const uint16_t *inptr0 = inptr + y * ldin + k0;
        const uint16_t *inptr1 = inptr0 + ldin;
        const uint16_t *inptr2 = inptr1 + ldin;
        const uint16_t *inptr3 = inptr2 + ldin;
        const uint16_t *inptr4 = inptr3 + ldin;
        const uint16_t *inptr5 = inptr4 + ldin;
        const uint16_t *inptr6 = inptr5 + ldin;
        const uint16_t *inptr7 = inptr6 + ldin;

        prefetch_2x(inptr0);
        prefetch_2x(inptr1);
        prefetch_2x(inptr2);
        prefetch_2x(inptr3);
        prefetch_2x(inptr4);
        prefetch_2x(inptr5);
        prefetch_2x(inptr6);
        prefetch_2x(inptr7);

        int x=(kmax-k0);
        for (;(x>7) || first;x-=8) {
            /* Cope with ragged cases by copying from a buffer of zeroes instead */
            /* 'first' forces this to always run at least once, needed if the total size is <=7. */
            if ((y + 7) >= ymax) {
                switch ((y + 7) - ymax) {
                    /* Everything falls through in here */
                    case 6:
                        inptr1 = zerobuff;
                        // fall through
                    case 5:
                        inptr2 = zerobuff;
                        // fall through
                    case 4:
                        inptr3 = zerobuff;
                        // fall through
                    case 3:
                        inptr4 = zerobuff;
                        // fall through
                    case 2:
                        inptr5 = zerobuff;
                        // fall through
                    case 1:
                        inptr6 = zerobuff;
                        // fall through
                    case 0:
                        inptr7 = zerobuff;
                        break;

                    default:
                        UNREACHABLE("Impossible.");
                }
            }

            if (first) {
                if (x <= 7) {
                    break;
                }

                first = false;
            }

            int skippf = (x & 31);
            __asm__ __volatile__(
            		// Load up 8 elements (1 vector) from each of 8 sources.
            		"li  a0, 8\n"
            		"vsetvli  t0, a0, e16, m1\n"

            		"bnez %[skippf], 1f\n"

            		"1:\n"
            		"vle16.v v0, (%[inptr0])\n"               // q0=A0A1A2A3A4A5A6A7
            		"add %[inptr0], %[inptr0], 16\n"
            		"vle16.v v4, (%[inptr4])\n"               // q8=E0E1E2E3E4E5E6E7
            		"add %[inptr4], %[inptr4], 16\n"
            		"vle16.v v2, (%[inptr2])\n"               // q4=C0C1C2C3...
            		"add %[inptr2], %[inptr2], 16\n"
            		"vle16.v v6, (%[inptr6])\n"
            		"add %[inptr6], %[inptr6], 16\n"

            		"li a2, 0\n"
            		"vwaddu.vx v24, v0, a2\n"
            		"vwaddu.vx v26, v4, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v8, v24, v28\n"                // q8=A0E0A1E1A2E2A3E3
            		"vwaddu.vx v24, v0, a2\n"
            		"vwaddu.vx v26, v4, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v16, v25, v28\n"               //q16=A4E4A5E5A6E6A7E7
            		"vwaddu.vx v24, v2, a2\n"
            		"vwaddu.vx v26, v6, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v9, v24, v28\n"                // q9=C0G0C1G1C2G2C3G3
            		"vwaddu.vx v24, v2, a2\n"
            		"vwaddu.vx v26, v6, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v17, v25, v28\n"               //q17=C4G4C5G5C6G6C7G7

            		"vle16.v v1, (%[inptr1])\n"               // q1=B0B1B2B3B4B5B6B7
            		"add %[inptr1], %[inptr1], 16\n"
            		"vle16.v v5, (%[inptr5])\n"               //
            		"add %[inptr5], %[inptr5], 16\n"
            		"vle16.v v3, (%[inptr3])\n"               // q3=D0D1D2D3....
            		"add %[inptr3], %[inptr3], 16\n"
            		"vle16.v v7, (%[inptr7])\n"
            		"add %[inptr7], %[inptr7], 16\n"

            		"vwaddu.vx v24, v1, a2\n"
            		"vwaddu.vx v26, v5, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v10, v24, v28\n"               //q18=B0F0B1F1B2F2B3F3
            		"vwaddu.vx v24, v1, a2\n"
            		"vwaddu.vx v26, v5, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v18, v25, v28\n"               //q18=B4F4B5F5B6F6B7F7
            		"vwaddu.vx v24, v3, a2\n"
            		"vwaddu.vx v26, v7, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v11, v24, v28\n"               // q19=D0H0D1H1D2H2D3H3
            		"vwaddu.vx v24, v3, a2\n"
            		"vwaddu.vx v26, v7, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v19, v25, v28\n"               //q19=D4H4D5H5D6H6D7H7

            		"vwaddu.vx v24, v8, a2\n"
            		"vwaddu.vx v26, v9, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v12, v24, v28\n"               //q20=A0C0E0G0A1C1E1G1
            		"vwaddu.vx v24, v8, a2\n"
            		"vwaddu.vx v26, v9, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v20, v25, v28\n"
            		"vwaddu.vx v24, v10, a2\n"
            		"vwaddu.vx v26, v11, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v13, v24, v28\n"               // q21=B0D0F0H0B1I1F1H1
            		"vwaddu.vx v24, v10, a2\n"
            		"vwaddu.vx v26, v11, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v21, v25, v28\n"

            		"bnez %[skippf], 2f\n"

            		"2:\n"
            		"vwaddu.vx v24, v16, a2\n"
            		"vwaddu.vx v26, v17, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v22, v24, v28\n"
            		"vwaddu.vx v24, v16, a2\n"
            		"vwaddu.vx v26, v17, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v30, v25, v28\n"
            		"vwaddu.vx v24, v18, a2\n"
            		"vwaddu.vx v26, v19, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v23, v24, v28\n"
            		"vwaddu.vx v24, v18, a2\n"
            		"vwaddu.vx v26, v19, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v31, v25, v28\n"

            		"vwaddu.vx v24, v12, a2\n"
            		"vwaddu.vx v26, v13, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v14, v24, v28\n"               //q22=A0B0C0D0E0F0G0H0
            		"vwaddu.vx v24, v12, a2\n"
            		"vwaddu.vx v26, v13, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v15, v25, v28\n"               //q23=A1B1C1D1E1F1G1H1
            		"vse16.v v14 ,(%[outptr])\n"
            		"add %[outptr], %[outptr], 16\n"        // Write back first two elements
            		"vse16.v v15 ,(%[outptr])\n"
            		"add %[outptr], %[outptr], 16\n"

            		"vwaddu.vx v24, v20, a2\n"
            		"vwaddu.vx v26, v21, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v0, v24, v28\n"
            		"vwaddu.vx v24, v20, a2\n"
            		"vwaddu.vx v26, v21, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v1, v25, v28\n"
            		"vse16.v v0 ,(%[outptr])\n"
            		"add %[outptr], %[outptr], 16\n"        // Write back next two elements
            		"vse16.v v1 ,(%[outptr])\n"
            		"add %[outptr], %[outptr], 16\n"

            		"vwaddu.vx v24, v22, a2\n"
            		"vwaddu.vx v26, v23, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v2, v24, v28\n"
            		"vwaddu.vx v24, v22, a2\n"
            		"vwaddu.vx v26, v23, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v3, v25, v28\n"
            		"vse16.v v2 ,(%[outptr])\n"
            		"add %[outptr], %[outptr], 16\n"        // Write back next two elements
            		"vse16.v v3 ,(%[outptr])\n"
            		"add %[outptr], %[outptr], 16\n"

            		"vwaddu.vx v24, v30, a2\n"
            		"vwaddu.vx v26, v31, a2\n"
            		"vslide1up.vx v28, v26, a2\n"
            		"vadd.vv v4, v24, v28\n"
            		"vwaddu.vx v24, v30, a2\n"
            		"vwaddu.vx v26, v31, a2\n"
            		"vslide1up.vx v28, v27, a2\n"
            		"vadd.vv v5, v25, v28\n"
            		"vse16.v v4 ,(%[outptr])\n"
            		"add %[outptr], %[outptr], 16\n"        // Write back next two elements
            		"vse16.v v5 ,(%[outptr])\n"
            		"add %[outptr], %[outptr], 16\n"

            		: [inptr0] "+r" (inptr0), [inptr1] "+r" (inptr1), [inptr2] "+r" (inptr2), [inptr3] "+r" (inptr3), [outptr] "+r" (outptr),
            		  [inptr4] "+r" (inptr4), [inptr5] "+r" (inptr5), [inptr6] "+r" (inptr6), [inptr7] "+r" (inptr7)
            		: [skippf] "r" (skippf)
            		: "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9", "v10", "v11", "v12","v13", "v14", "v15", "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", "v24", "v25", "v26","v27", "v28", "v29", "v30", "v31", "a0", "a1", "a2", "t0"
            	);
        }

        for (;x>0;x--) {
            *outptr++ = *inptr0++;
            *outptr++ = *inptr1++;
            *outptr++ = *inptr2++;
            *outptr++ = *inptr3++;
            *outptr++ = *inptr4++;
            *outptr++ = *inptr5++;
            *outptr++ = *inptr6++;
            *outptr++ = *inptr7++;
        }
    }
}

#endif // __aarch64__
