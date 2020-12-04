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

namespace arm_gemm {

void a64_gemm_u8_12x8(const uint8_t *Apanel, const uint8_t *Bpanel, uint32_t *Cpanel, int ablocks, int bblocks, int K) {
    const uint8_t *a_ptr = Apanel;
    uint32_t *c_ptr = Cpanel;
    // We divide K by 4 because the udot instruction processes 4 elements at a time.
    const int W = K/4;
    // Fix up for odd lengths - set a flag if K is odd, but make
    // sure we round up the iteration count.
    const int oddk = (W & 1);
    const int init_value_k = ((W+1)/2) - 1;
    for (int yb=0; yb<ablocks; yb++) {
        const uint8_t *a_ptr0 = a_ptr;
        const uint8_t *b_ptr = Bpanel;
        for (int xb=0; xb<bblocks; xb++) {
            a_ptr = a_ptr0;
            int k = init_value_k;
/*
            register uint8x16_t a0  asm("v0");
            register uint8x16_t a1  asm("v1");
            register uint8x16_t b0  asm("v2");
            register uint8x16_t b1  asm("v3");
            register uint8x16_t b2  asm("v4");
            register uint8x16_t a0a asm("v5");
            register uint8x16_t a1a asm("v6");
            __asm __volatile (
                // Initialize result registers, load initial operands, prime prefetches.
                "movi	v8.4s, #0x0\n"
                "ldr	%q[a0], [%[a_ptr]]\n"
                "movi	v9.4s, #0x0\n"
                "ldr	%q[b0], [%[b_ptr]]\n"
                "movi	v10.4s, #0x0\n"
                "ldr	%q[a1], [%[a_ptr], #16]\n"
                "movi	v11.4s, #0x0\n"
                "ldr	%q[b1], [%[b_ptr], #16]\n"
                "movi	v12.4s, #0x0\n"
                ASM_PREFETCH("[%[b_ptr], #64]")
                "movi	v13.4s, #0x0\n"
                ASM_PREFETCH("[%[a_ptr], #64]")
                "movi	v14.4s, #0x0\n"
                ASM_PREFETCH("[%[b_ptr], #128]")
                "movi	v15.4s, #0x0\n"
                ASM_PREFETCH("[%[a_ptr], #128]")
                "movi	v16.4s, #0x0\n"
                ASM_PREFETCH("[%[b_ptr], #192]")
                "movi	v17.4s, #0x0\n"
                ASM_PREFETCH("[%[b_ptr], #256]")
                "movi	v18.4s, #0x0\n"
                ASM_PREFETCH("[%[a_ptr], #192]")
                "movi	v19.4s, #0x0\n"
                ASM_PREFETCH("[%[b_ptr], #320]")
                "movi	v20.4s, #0x0\n"
                ASM_PREFETCH("[%[a_ptr], #256]")
                "movi	v21.4s, #0x0\n"
                ASM_PREFETCH("[%[b_ptr], #384]")
                "movi	v22.4s, #0x0\n"
                "movi	v23.4s, #0x0\n"
                "movi	v24.4s, #0x0\n"
                "movi	v25.4s, #0x0\n"
                "movi	v26.4s, #0x0\n"
                "movi	v27.4s, #0x0\n"
                "movi	v28.4s, #0x0\n"
                "movi	v29.4s, #0x0\n"
                "movi	v30.4s, #0x0\n"
                "movi	v31.4s, #0x0\n"

                // Skip loop if we are doing zero iterations of it.
                "cbz	%w[k], 4f\n"

                // Loop proper
                "1:\n"
                ".word 0x6f80e048 // udot v8.4s , %[b0].16b, %[a0].4b[0]\n"
                ".word 0x6fa0e049 // udot v9.4s , %[b0].16b, %[a0].4b[1]\n"

                "ldr	%q[b2], [%[b_ptr], #32]\n"
                ".word 0x6f80e84a // udot v10.4s, %[b0].16b, %[a0].4b[2]\n"
                ".word 0x6fa0e84b // udot v11.4s, %[b0].16b, %[a0].4b[3]\n"
                "ldr	%q[a0a], [%[a_ptr], #32]\n"
                ".word 0x6f81e04c // udot v12.4s, %[b0].16b, %[a1].4b[0]\n"
                ".word 0x6fa1e04d // udot v13.4s, %[b0].16b, %[a1].4b[1]\n"
                "ldr	%q[a1a], [%[a_ptr], #48]\n"
                ".word 0x6f81e84e // udot v14.4s, %[b0].16b, %[a1].4b[2]\n"
                ".word 0x6fa1e84f // udot v15.4s, %[b0].16b, %[a1].4b[3]\n"
                "ldr	%q[b0], [%[b_ptr], #48]\n"

                ".word 0x6f80e070 // udot v16.4s, %[b1].16b, %[a0].4b[0]\n"
                ".word 0x6fa0e071 // udot v17.4s, %[b1].16b, %[a0].4b[1]\n"
                ASM_PREFETCH("[%[a_ptr], #320]")
                ".word 0x6f80e872 // udot v18.4s, %[b1].16b, %[a0].4b[2]\n"
                ".word 0x6fa0e873 // udot v19.4s, %[b1].16b, %[a0].4b[3]\n"
                ".word 0x6f81e074 // udot v20.4s, %[b1].16b, %[a1].4b[0]\n"
                ".word 0x6fa1e075 // udot v21.4s, %[b1].16b, %[a1].4b[1]\n"
                ".word 0x6f81e876 // udot v22.4s, %[b1].16b, %[a1].4b[2]\n"
                ".word 0x6fa1e877 // udot v23.4s, %[b1].16b, %[a1].4b[3]\n"
                "ldr	%q[b1], [%[b_ptr], #64]\n"

                ".word 0x6f80e098 // udot v24.4s, %[b2].16b, %[a0].4b[0]\n"
                ".word 0x6fa0e099 // udot v25.4s, %[b2].16b, %[a0].4b[1]\n"
                ASM_PREFETCH("[%[b_ptr], #448]")
                ".word 0x6f80e89a // udot v26.4s, %[b2].16b, %[a0].4b[2]\n"
                ".word 0x6fa0e89b // udot v27.4s, %[b2].16b, %[a0].4b[3]\n"
                ".word 0x6f81e09c // udot v28.4s, %[b2].16b, %[a1].4b[0]\n"
                ".word 0x6fa1e09d // udot v29.4s, %[b2].16b, %[a1].4b[1]\n"
                ".word 0x6f81e89e // udot v30.4s, %[b2].16b, %[a1].4b[2]\n"
                ".word 0x6fa1e89f // udot v31.4s, %[b2].16b, %[a1].4b[3]\n"
                "ldr	%q[b2], [%[b_ptr], #80]\n"

                ".word 0x6f85e048 // udot v8.4s , %[b0].16b, %[a0a].4b[0]\n"
                ".word 0x6fa5e049 // udot v9.4s , %[b0].16b, %[a0a].4b[1]\n"
                "ldr	%q[a0], [%[a_ptr], #64]\n"
                ".word 0x6f85e84a // udot v10.4s, %[b0].16b, %[a0a].4b[2]\n"
                ".word 0x6fa5e84b // udot v11.4s, %[b0].16b, %[a0a].4b[3]\n"
                ".word 0x6f86e04c // udot v12.4s, %[b0].16b, %[a1a].4b[0]\n"
                "ldr	%q[a1], [%[a_ptr], #80]\n"
                ".word 0x6fa6e04d // udot v13.4s, %[b0].16b, %[a1a].4b[1]\n"
                ".word 0x6f86e84e // udot v14.4s, %[b0].16b, %[a1a].4b[2]\n"
                ".word 0x6fa6e84f // udot v15.4s, %[b0].16b, %[a1a].4b[3]\n"
                "ldr	%q[b0], [%[b_ptr], #96]\n"

                ".word 0x6f85e070 // udot v16.4s, %[b1].16b, %[a0a].4b[0]\n"
                ".word 0x6fa5e071 // udot v17.4s, %[b1].16b, %[a0a].4b[1]\n"
                ASM_PREFETCH("[%[b_ptr], #512]")
                ".word 0x6f85e872 // udot v18.4s, %[b1].16b, %[a0a].4b[2]\n"
                ".word 0x6fa5e873 // udot v19.4s, %[b1].16b, %[a0a].4b[3]\n"
                ".word 0x6f86e074 // udot v20.4s, %[b1].16b, %[a1a].4b[0]\n"
                ".word 0x6fa6e075 // udot v21.4s, %[b1].16b, %[a1a].4b[1]\n"
                ".word 0x6f86e876 // udot v22.4s, %[b1].16b, %[a1a].4b[2]\n"
                ".word 0x6fa6e877 // udot v23.4s, %[b1].16b, %[a1a].4b[3]\n"
                "ldr	%q[b1], [%[b_ptr], #112]\n"

                ".word 0x6f85e098 // udot v24.4s, %[b2].16b, %[a0a].4b[0]\n"
                ".word 0x6fa5e099 // udot v25.4s, %[b2].16b, %[a0a].4b[1]\n"
                "add	%[a_ptr], %[a_ptr], #64\n"
                ".word 0x6f85e89a // udot v26.4s, %[b2].16b, %[a0a].4b[2]\n"
                ".word 0x6fa5e89b // udot v27.4s, %[b2].16b, %[a0a].4b[3]\n"
                "add	%[b_ptr], %[b_ptr], #96\n"
                ".word 0x6f86e09c // udot v28.4s, %[b2].16b, %[a1a].4b[0]\n"
                ".word 0x6fa6e09d // udot v29.4s, %[b2].16b, %[a1a].4b[1]\n"
                "subs	%w[k], %w[k], #1\n"
                ".word 0x6f86e89e // udot v30.4s, %[b2].16b, %[a1a].4b[2]\n"
                ".word 0x6fa6e89f // udot v31.4s, %[b2].16b, %[a1a].4b[3]\n"
                "bne	1b\n"

                // Target to use when K is 1 or 2 (i.e. zero iterations of main loop)
                "4:\n"

                // Branch to alternative tail for odd K
                "cbnz	%w[oddk], 2f\n"

                // Detached final iteration (even K)
                ".word 0x6f80e048 // udot v8.4s , %[b0].16b, %[a0].4b[0]\n"
                ".word 0x6fa0e049 // udot v9.4s , %[b0].16b, %[a0].4b[1]\n"
                "ldr	%q[b2], [%[b_ptr], #32]\n"
                ".word 0x6f80e84a // udot v10.4s, %[b0].16b, %[a0].4b[2]\n"
                ".word 0x6fa0e84b // udot v11.4s, %[b0].16b, %[a0].4b[3]\n"
                "ldr	%q[a0a], [%[a_ptr], #32]\n"
                ".word 0x6f81e04c // udot v12.4s, %[b0].16b, %[a1].4b[0]\n"
                ".word 0x6fa1e04d // udot v13.4s, %[b0].16b, %[a1].4b[1]\n"
                "ldr	%q[a1a], [%[a_ptr], #48]\n"
                ".word 0x6f81e84e // udot v14.4s, %[b0].16b, %[a1].4b[2]\n"
                ".word 0x6fa1e84f // udot v15.4s, %[b0].16b, %[a1].4b[3]\n"
                "ldr	%q[b0], [%[b_ptr], #48]\n"

                ".word 0x6f80e070 // udot v16.4s, %[b1].16b, %[a0].4b[0]\n"
                ".word 0x6fa0e071 // udot v17.4s, %[b1].16b, %[a0].4b[1]\n"
                ".word 0x6f80e872 // udot v18.4s, %[b1].16b, %[a0].4b[2]\n"
                ".word 0x6fa0e873 // udot v19.4s, %[b1].16b, %[a0].4b[3]\n"
                ".word 0x6f81e074 // udot v20.4s, %[b1].16b, %[a1].4b[0]\n"
                ".word 0x6fa1e075 // udot v21.4s, %[b1].16b, %[a1].4b[1]\n"
                ".word 0x6f81e876 // udot v22.4s, %[b1].16b, %[a1].4b[2]\n"
                ".word 0x6fa1e877 // udot v23.4s, %[b1].16b, %[a1].4b[3]\n"
                "ldr	%q[b1], [%[b_ptr], #64]\n"

                ".word 0x6f80e098 // udot v24.4s, %[b2].16b, %[a0].4b[0]\n"
                ".word 0x6fa0e099 // udot v25.4s, %[b2].16b, %[a0].4b[1]\n"
                "add	%[a_ptr], %[a_ptr], #64\n"
                ".word 0x6f80e89a // udot v26.4s, %[b2].16b, %[a0].4b[2]\n"
                ".word 0x6fa0e89b // udot v27.4s, %[b2].16b, %[a0].4b[3]\n"
                ".word 0x6f81e09c // udot v28.4s, %[b2].16b, %[a1].4b[0]\n"
                ".word 0x6fa1e09d // udot v29.4s, %[b2].16b, %[a1].4b[1]\n"
                ".word 0x6f81e89e // udot v30.4s, %[b2].16b, %[a1].4b[2]\n"
                ".word 0x6fa1e89f // udot v31.4s, %[b2].16b, %[a1].4b[3]\n"
                "ldr	%q[b2], [%[b_ptr], #80]\n"

                ".word 0x6f85e048 // udot v8.4s , %[b0].16b, %[a0a].4b[0]\n"

                ".word 0x6f85e070 // udot v16.4s, %[b1].16b, %[a0a].4b[0]\n"
                "add	%[b_ptr], %[b_ptr], #96\n"
                ".word 0x6fa5e049 // udot v9.4s , %[b0].16b, %[a0a].4b[1]\n"
                "str	q8, [%[c_ptr], #0]\n"
                ".word 0x6fa5e071 // udot v17.4s, %[b1].16b, %[a0a].4b[1]\n"
                "str	q16, [%[c_ptr], #16]\n"
                ".word 0x6f85e098 // udot v24.4s, %[b2].16b, %[a0a].4b[0]\n"
                "str	q24, [%[c_ptr], #32]\n"

                ".word 0x6fa5e099 // udot v25.4s, %[b2].16b, %[a0a].4b[1]\n"
                "str	q9, [%[c_ptr], #48]\n"
                ".word 0x6f85e84a // udot v10.4s, %[b0].16b, %[a0a].4b[2]\n"
                "str	q17, [%[c_ptr], #64]\n"
                ".word 0x6f85e872 // udot v18.4s, %[b1].16b, %[a0a].4b[2]\n"
                "str	q25, [%[c_ptr], #80]\n"
                ".word 0x6f85e89a // udot v26.4s, %[b2].16b, %[a0a].4b[2]\n"
                "str	q10, [%[c_ptr], #96]\n"

                ".word 0x6fa5e84b // udot v11.4s, %[b0].16b, %[a0a].4b[3]\n"
                "str	q18, [%[c_ptr], #112]\n"
                ".word 0x6fa5e873 // udot v19.4s, %[b1].16b, %[a0a].4b[3]\n"
                "str	q26, [%[c_ptr], #128]\n"
                ".word 0x6fa5e89b // udot v27.4s, %[b2].16b, %[a0a].4b[3]\n"
                "str	q11, [%[c_ptr], #144]\n"

                ".word 0x6f86e04c // udot v12.4s, %[b0].16b, %[a1a].4b[0]\n"
                "str	q19, [%[c_ptr], #160]\n"
                ".word 0x6f86e074 // udot v20.4s, %[b1].16b, %[a1a].4b[0]\n"
                "str	q27, [%[c_ptr], #176]\n"
                ".word 0x6f86e09c // udot v28.4s, %[b2].16b, %[a1a].4b[0]\n"
                "str	q12, [%[c_ptr], #192]\n"

                ".word 0x6fa6e04d // udot v13.4s, %[b0].16b, %[a1a].4b[1]\n"
                "str	q20, [%[c_ptr], #208]\n"
                ".word 0x6fa6e075 // udot v21.4s, %[b1].16b, %[a1a].4b[1]\n"
                "str	q28, [%[c_ptr], #224]\n"
                ".word 0x6fa6e09d // udot v29.4s, %[b2].16b, %[a1a].4b[1]\n"
                "str	q13, [%[c_ptr], #240]\n"

                ".word 0x6f86e84e // udot v14.4s, %[b0].16b, %[a1a].4b[2]\n"
                "str	q21, [%[c_ptr], #256]\n"
                ".word 0x6f86e876 // udot v22.4s, %[b1].16b, %[a1a].4b[2]\n"
                "str	q29, [%[c_ptr], #272]\n"
                ".word 0x6f86e89e // udot v30.4s, %[b2].16b, %[a1a].4b[2]\n"
                "str	q14, [%[c_ptr], #288]\n"

                ".word 0x6fa6e84f // udot v15.4s, %[b0].16b, %[a1a].4b[3]\n"
                "str	q22, [%[c_ptr], #304]\n"
                ".word 0x6fa6e877 // udot v23.4s, %[b1].16b, %[a1a].4b[3]\n"
                "str	q30, [%[c_ptr], #320]\n"
                ".word 0x6fa6e89f // udot v31.4s, %[b2].16b, %[a1a].4b[3]\n"
                "str	q15, [%[c_ptr], #336]\n"

                "b	3f\n"

                // Detached final iteration (odd K)
                "2:\n"
                ".word 0x6f80e048 // udot v8.4s , %[b0].16b, %[a0].4b[0]\n"
                "ldr	%q[b2], [%[b_ptr], #32]\n"
                ".word 0x6f80e070 // udot v16.4s, %[b1].16b, %[a0].4b[0]\n"
                ".word 0x6fa0e049 // udot v9.4s , %[b0].16b, %[a0].4b[1]\n"
                "str	q8, [%[c_ptr], #0]\n"
                ".word 0x6fa0e071 // udot v17.4s, %[b1].16b, %[a0].4b[1]\n"
                "str	q16, [%[c_ptr], #16]\n"
                ".word 0x6f80e098 // udot v24.4s, %[b2].16b, %[a0].4b[0]\n"
                "add	%[b_ptr], %[b_ptr], #48\n"
                "add	%[a_ptr], %[a_ptr], #32\n"
                "str	q24, [%[c_ptr], #32]\n"
                ".word 0x6fa0e099 // udot v25.4s, %[b2].16b, %[a0].4b[1]\n"
                "str	q9, [%[c_ptr], #48]\n"

                ".word 0x6f80e84a // udot v10.4s, %[b0].16b, %[a0].4b[2]\n"
                "str	q17, [%[c_ptr], #64]\n"
                ".word 0x6f80e872 // udot v18.4s, %[b1].16b, %[a0].4b[2]\n"
                "str	q25, [%[c_ptr], #80]\n"
                ".word 0x6f80e89a // udot v26.4s, %[b2].16b, %[a0].4b[2]\n"
                "str	q10, [%[c_ptr], #96]\n"

                ".word 0x6fa0e84b // udot v11.4s, %[b0].16b, %[a0].4b[3]\n"
                "str	q18, [%[c_ptr], #112]\n"
                ".word 0x6fa0e873 // udot v19.4s, %[b1].16b, %[a0].4b[3]\n"
                "str	q26, [%[c_ptr], #128]\n"
                ".word 0x6fa0e89b // udot v27.4s, %[b2].16b, %[a0].4b[3]\n"
                "str	q11, [%[c_ptr], #144]\n"

                ".word 0x6f81e04c // udot v12.4s, %[b0].16b, %[a1].4b[0]\n"
                "str	q19, [%[c_ptr], #160]\n"
                ".word 0x6f81e074 // udot v20.4s, %[b1].16b, %[a1].4b[0]\n"
                "str	q27, [%[c_ptr], #176]\n"
                ".word 0x6f81e09c // udot v28.4s, %[b2].16b, %[a1].4b[0]\n"
                "str	q12, [%[c_ptr], #192]\n"

                ".word 0x6fa1e04d // udot v13.4s, %[b0].16b, %[a1].4b[1]\n"
                "str	q20, [%[c_ptr], #208]\n"
                ".word 0x6fa1e075 // udot v21.4s, %[b1].16b, %[a1].4b[1]\n"
                "str	q28, [%[c_ptr], #224]\n"
                ".word 0x6fa1e09d // udot v29.4s, %[b2].16b, %[a1].4b[1]\n"
                "str	q13, [%[c_ptr], #240]\n"

                ".word 0x6f81e84e // udot v14.4s, %[b0].16b, %[a1].4b[2]\n"
                "str	q21, [%[c_ptr], #256]\n"
                ".word 0x6f81e876 // udot v22.4s, %[b1].16b, %[a1].4b[2]\n"
                "str	q29, [%[c_ptr], #272]\n"
                ".word 0x6f81e89e // udot v30.4s, %[b2].16b, %[a1].4b[2]\n"
                "str	q14, [%[c_ptr], #288]\n"

                ".word 0x6fa1e84f // udot v15.4s, %[b0].16b, %[a1].4b[3]\n"
                "str	q22, [%[c_ptr], #304]\n"
                ".word 0x6fa1e877 // udot v23.4s, %[b1].16b, %[a1].4b[3]\n"
                "str	q30, [%[c_ptr], #320]\n"
                ".word 0x6fa1e89f // udot v31.4s, %[b2].16b, %[a1].4b[3]\n"
                "str	q15, [%[c_ptr], #336]\n"


                // Common tail
                "3:\n"
                "str	q23, [%[c_ptr], #352]\n"
                "str	q31, [%[c_ptr], #368]\n"
                "add	%[c_ptr], %[c_ptr], #384\n"

            :
              [a_ptr] "+r" (a_ptr), [b_ptr] "+r" (b_ptr), [c_ptr] "+r" (c_ptr),
              [a0] "+w" (a0), [a1] "+w" (a1), [a0a] "+w" (a0a), [a1a] "+w" (a1a),
              [b0] "+w" (b0), [b1] "+w" (b1), [b2] "+w" (b2), [k] "+r" (k)
            : [oddk] "r" (oddk)
            : "x20", "x21", "v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15", "v16", "v17", "v18",
              "v19", "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31", "cc"
            );
*/

        printf("no support now\n");
        __asm__ __volatile__(
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
        ".word 0x6f80e048\n"
        ".word 0x6fa0e049\n"
        "add    a1, %[b_ptr], 32\n"
        "vle32.v    v4, (a1)\n"
        ".word 0x6f80e84a\n"
        ".word 0x6fa0e84b\n"
        "add    a1, %[a_ptr], 32\n"
        "vle32.v    v5, (a1)\n"
        ".word 0x6f81e04c\n"
        ".word 0x6fa1e04d\n"
        "add    a1, %[a_ptr], 48\n"
        "vle32.v    v6, (a1)\n"
        ".word 0x6f81e84e\n"
        ".word 0x6fa1e84f\n"
        "add    a1, %[b_ptr], 48\n"
        "vle32.v    v2, (a1)\n"

        ".word 0x6f80e070\n"
        ".word 0x6fa0e071\n"

        ".word 0x6f80e872\n"
        ".word 0x6fa0e873\n"
        ".word 0x6f81e074\n"
        ".word 0x6fa1e075\n"
        ".word 0x6f81e876\n"
        ".word 0x6fa1e877\n"
        "add    a1, %[b_ptr], 64\n"
        "vle32.v    v3, (a1)\n"

        ".word 0x6f80e098\n"
        ".word 0x6fa0e099\n"

        ".word 0x6f80e89a\n"
        ".word 0x6fa0e89b\n"
        ".word 0x6f81e09c\n"
        ".word 0x6fa1e09d\n"
        ".word 0x6f81e89e\n"

        ".word 0x6fa1e89f\n"
        "add    a1, %[b_ptr], 80\n"
        "vle32.v    v4, (a1)\n"

        ".word 0x6f85e048\n"
        ".word 0x6fa5e049\n"
        "add    a1, %[a_ptr], 64\n"
        "vle32.v    v0, (a1)\n"
        ".word 0x6f85e84a\n"
        ".word 0x6fa5e84b\n"
        ".word 0x6f86e04c\n"
        "add    a1, %[a_ptr], 80\n"
        "vle32.v    v1, (a1)\n"
        ".word 0x6fa6e04d\n"
        ".word 0x6f86e84e\n"
        ".word 0x6fa6e84f\n"
        "add    a1, %[b_ptr], 96\n"
        "vle32.v    v2, (a1)\n"

        ".word 0x6f85e070\n"
        ".word 0x6fa5e071\n"

        ".word 0x6f85e872\n"
        ".word 0x6fa5e873\n"
        ".word 0x6f86e074\n"
        ".word 0x6fa6e075\n"
        ".word 0x6f86e876\n"
        ".word 0x6fa6e877\n"
        "add    a1, %[b_ptr], 112\n"
        "vle32.v    v3, (a1)\n"

        ".word 0x6f85e098\n"
        ".word 0x6fa5e099\n"
        "add    %[a_ptr], %[a_ptr], 64\n"
        ".word 0x6f85e89a\n"
        ".word 0x6fa5e89b\n"
        "add    %[b_ptr], %[b_ptr], 96\n"
        ".word 0x6f86e09c\n"
        ".word 0x6fa6e09d\n"
        "addi   %[k], %[k], -1\n"
        ".word 0x6f86e89e\n"
        ".word 0x6fa6e89f\n"
        "bnez   %[k], 1b\n"

        // Target to use when K is 1 or 2 (i.e. zero iterations of main loop)
        "4:\n"

        // Branch to alternative tail for odd K
        "bnez   %[oddk], 2f\n"

        // Detached final iteration (even K)
        ".word 0x6f80e048\n"
        ".word 0x6fa0e049\n"
        "add    a1, %[b_ptr], 32\n"
        "vle32.v    v4, (a1)\n"
        ".word 0x6f80e84a\n"
        ".word 0x6fa0e84b\n"
        "add    a1, %[a_ptr], 32\n"
        "vle32.v    v5, (a1)\n"
        ".word 0x6f81e04c\n"
        ".word 0x6fa1e04d\n"
        "add    a1, %[a_ptr], 48\n"
        "vle32.v    v6, (a1)\n"
        ".word 0x6f81e84e\n"
        ".word 0x6fa1e84f\n"
        "add    a1, %[b_ptr], 48\n"
        "vle32.v    v2, (a1)\n"

        ".word 0x6f80e070\n"
        ".word 0x6fa0e071\n"
        ".word 0x6f80e872\n"
        ".word 0x6fa0e873\n"
        ".word 0x6f81e074\n"
        ".word 0x6fa1e075\n"
        ".word 0x6f81e876\n"
        ".word 0x6fa1e877\n"
        "add    a1, %[b_ptr], 64\n"
        "vle32.v    v3, (a1)\n"

        ".word 0x6f80e098\n"
        ".word 0x6fa0e099\n"
        "add    %[a_ptr], %[a_ptr], 64\n"
        ".word 0x6f80e89a\n"
        ".word 0x6fa0e89b\n"
        ".word 0x6f81e09c\n"
        ".word 0x6fa1e09d\n"
        ".word 0x6f81e89e\n"
        ".word 0x6fa1e89f\n"
        "add    a1, %[b_ptr], 80\n"
        "vle32.v    v4, (a1)\n"

        ".word 0x6f85e048\n"

        ".word 0x6f85e070\n"
        "add    %[b_ptr], %[b_ptr], 96\n"
        ".word 0x6fa5e049\n"
        "vse32.v    v8, (%[c_ptr])\n"
        ".word 0x6fa5e071\n"
        "add    a1, %[c_ptr], 16\n"
        "vse32.v    v16, (a1)\n"
        ".word 0x6f85e098\n"
        "add    a1, %[c_ptr], 32\n"
        "vse32.v    v24, (a1)\n"

        ".word 0x6fa5e099\n"
        "add    a1, %[c_ptr], 48\n"
        "vse32.v    v9, (a1)\n"
        ".word 0x6f85e84a\n"
        "add    a1, %[c_ptr], 64\n"
        "vse32.v    v17, (a1)\n"
        ".word 0x6f85e872\n"
        "add    a1, %[c_ptr], 80\n"
        "vse32.v    v25, (a1)\n"
        ".word 0x6f85e89a\n"
        "add    a1, %[c_ptr], 96\n"
        "vse32.v    v10, (a1)\n"

        ".word 0x6fa5e84b\n"
        "add    a1, %[c_ptr], 112\n"
        "vse32.v    v18, (a1)\n"
        ".word 0x6fa5e873\n"
        "add    a1, %[c_ptr], 128\n"
        "vse32.v    v26, (a1)\n"
        ".word 0x6fa5e89b\n"
        "add    a1, %[c_ptr], 144\n"
        "vse32.v    v11, (a1)\n"

        ".word 0x6f86e04c\n"
        "add    a1, %[c_ptr], 160\n"
        "vse32.v    v19, (a1)\n"
        ".word 0x6f86e074\n"
        "add    a1, %[c_ptr], 176\n"
        "vse32.v    v27, (a1)\n"
        ".word 0x6f86e09c\n"
        "add    a1, %[c_ptr], 192\n"
        "vse32.v    v12, (a1)\n"

        ".word 0x6fa6e04d\n"
        "add    a1, %[c_ptr], 208\n"
        "vse32.v    v20, (a1)\n"
        ".word 0x6fa6e075\n"
        "add    a1, %[c_ptr], 224\n"
        "vse32.v    v28, (a1)\n"
        ".word 0x6fa6e09d\n"
        "add    a1, %[c_ptr], 240\n"
        "vse32.v    v13, (a1)\n"

        ".word 0x6f86e84e\n"
        "add    a1, %[c_ptr], 256\n"
        "vse32.v    v21, (a1)\n"
        ".word 0x6f86e876\n"
        "add    a1, %[c_ptr], 272\n"
        "vse32.v    v29, (a1)\n"
        ".word 0x6f86e89e\n"
        "add    a1, %[c_ptr], 288\n"
        "vse32.v    v14, (a1)\n"

        ".word 0x6fa6e84f\n"
        "add    a1, %[c_ptr], 304\n"
        "vse32.v    v22, (a1)\n"
        ".word 0x6fa6e877\n"
        "add    a1, %[c_ptr], 320\n"
        "vse32.v    v30, (a1)\n"
        ".word 0x6fa6e89f\n"
        "add    a1, %[c_ptr], 336\n"
        "vse32.v    v15, (a1)\n"

        "j      3f\n"

        // Detached final iteration (odd K)
        "2:\n"
        ".word 0x6f80e048\n"
        "add    a1, %[b_ptr], 32\n"
        "vle32.v    v4, (a1)\n"
        ".word 0x6f80e070\n"
        ".word 0x6fa0e049\n"
        "vse32.v    v8, (%[c_ptr])\n"
        ".word 0x6fa0e071\n"
        "add    a1, %[c_ptr], 16\n"
        "vse32.v    v16, (a1)\n"
        ".word 0x6f80e098\n"
        "add    %[b_ptr], %[b_ptr], 48\n"
        "add    %[a_ptr], %[a_ptr], 32\n"
        "add    a1, %[c_ptr], 32\n"
        "vse32.v    v24, (a1)\n"
        ".word 0x6fa0e099\n"
        "add    a1, %[c_ptr], 48\n"
        "vse32.v    v9, (a1)\n"

        ".word 0x6f80e84a\n"
        "add    a1, %[c_ptr], 64\n"
        "vse32.v    v17, (a1)\n"
        ".word 0x6f80e872\n"
        "add    a1, %[c_ptr], 80\n"
        "vse32.v    v25, (a1)\n"
        ".word 0x6f80e89a\n"
        "add    a1, %[c_ptr], 96\n"
        "vse32.v    v10, (a1)\n"

        ".word 0x6fa0e84b\n"
        "add    a1, %[c_ptr], 112\n"
        "vse32.v    v18, (a1)\n"
        ".word 0x6fa0e873\n"
        "add    a1, %[c_ptr], 128\n"
        "vse32.v    v26, (a1)\n"
        ".word 0x6fa0e89b\n"
        "add    a1, %[c_ptr], 144\n"
        "vse32.v    v11, (a1)\n"

        ".word 0x6f81e04c\n"
        "add    a1, %[c_ptr], 160\n"
        "vse32.v    v19, (a1)\n"
        ".word 0x6f81e074\n"
        "add    a1, %[c_ptr], 176\n"
        "vse32.v    v27, (a1)\n"
        ".word 0x6f81e09c\n"
        "add    a1, %[c_ptr], 192\n"
        "vse32.v    v12, (a1)\n"

        ".word 0x6fa1e04d\n"
        "add    a1, %[c_ptr], 208\n"
        "vse32.v    v20, (a1)\n"
        ".word 0x6fa1e075\n"
        "add    a1, %[c_ptr], 224\n"
        "vse32.v    v28, (a1)\n"
        ".word 0x6fa1e09d\n"
        "add    a1, %[c_ptr], 240\n"
        "vse32.v    v13, (a1)\n"

        ".word 0x6f81e84e\n"
        "add    a1, %[c_ptr], 256\n"
        "vse32.v    v21, (a1)\n"
        ".word 0x6f81e876\n"
        "add    a1, %[c_ptr], 272\n"
        "vse32.v    v29, (a1)\n"
        ".word 0x6f81e89e\n"
        "add    a1, %[c_ptr], 288\n"
        "vse32.v    v14, (a1)\n"

        ".word 0x6fa1e84f\n"
        "add    a1, %[c_ptr], 304\n"
        "vse32.v    v22, (a1)\n"
        ".word 0x6fa1e877\n"
        "add    a1, %[c_ptr], 320\n"
        "vse32.v    v30, (a1)\n"
        ".word 0x6fa1e89f\n"
        "add    a1, %[c_ptr], 336\n"
        "vse32.v    v15, (a1)\n"

        // Common tail
        "3:\n"
        "add    a1, %[c_ptr], 352\n"
        "vse32.v    v23, (a1)\n"
        "add    a1, %[c_ptr], 368\n"
        "vse32.v    v31, (a1)\n"
        "add    %[c_ptr], %[c_ptr], 384\n"

        : [a_ptr] "+r" (a_ptr), [b_ptr] "+r" (b_ptr), [c_ptr] "+r" (c_ptr), [k] "+r" (k)
        : [oddk] "r" (oddk)
        : "v1", "v2", "v3", "v4", "v5", "v6", "v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15", "v16", "v17", "v18", "v19",
		  "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31", "t0", "a0", "a1"
        );
        }
    }
}

} // namespace arm_gemm

#endif
