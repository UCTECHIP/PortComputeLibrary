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

void a64_gemm_u16_asimd_12x8(const uint16_t *Apanel, const uint16_t *Bpanel, uint32_t *Cpanel, int ablocks, int bblocks, int K)
{
  const uint16_t *a_ptr = Apanel;
  uint32_t *c_ptr = Cpanel;

  for (int yb = 0; yb < ablocks; yb++)
  {
    const uint16_t *a_ptr0 = a_ptr;
    const uint16_t *b_ptr = Bpanel;

    for (int xb = 0; xb < bblocks; xb++)
    {
      a_ptr = a_ptr0;
      const bool odd_k = K & 0x1;
      int k = (K+1)/2 - 1;

      unsigned short s0[8] = {0,0,0,0,0,0,0,0};
      unsigned short *s = s0;
      __asm__ __volatile__(
                  "li  a0, 8\n"
                  "li  a2, 4\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "vle16.v v0, (%[a_ptr])\n"  // Load A[A].lower
                  "vmv.v.i v5, 0\n"
                  "vmv.v.i v6, 0\n"
                  "vle16.v v2, (%[b_ptr])\n"  // Load B[0].lower
                  "vmv.v.i v7, 0\n"

                  "vmv.v.i v8, 0\n"

                  "vmv.v.i v9, 0\n"

                  "vmv.v.i v10, 0\n"
                  "add  a1, %[b_ptr], 0x10\n"
                  "vle16.v v3, (a1)\n"  // Load B[1].lower
                  "vmv.v.i v11, 0\n"

                  "vmv.v.i v12, 0\n"
                  "vmv.v.i v13, 0\n"

                  "vmv.v.i v14, 0\n"
                  "vmv.v.i v15, 0\n"

                  "vmv.v.i v16, 0\n"
                  "vmv.v.i v17, 0\n"

                  "vmv.v.i v18, 0\n"
                  "vmv.v.i v19, 0\n"
                  "vmv.v.i v20, 0\n"
                  "vmv.v.i v21, 0\n"

                  "vmv.v.i v22, 0\n"
                  "vmv.v.i v23, 0\n"

                  "vmv.v.i v24, 0\n"
                  "add %[a_ptr], %[a_ptr], 0x10\n"
                  "vmv.v.i v25, 0\n"

                  "vmv.v.i v26, 0\n"
                  "add %[b_ptr], %[b_ptr], 0x18\n"
                  "vmv.v.i v27, 0\n"
                  "vmv.v.i v28, 0\n"
                  "vmv.v.i v29, 0\n"

                  // Skip loop if we are doing zero iterations of it.
                  "beqz %[k], 2f\n"

                  "1:\n"// Main loop
                  // First unroll

                  "vse16.v          v0, (%[s])\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v6, a3, v2\n"   //0
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v8, a3, v2\n"   //1
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v10, a3, v2\n"  //2
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v12, a3, v2\n"  //3
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v14, a3, v2\n"  //4
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v16, a3, v2\n"  //5
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v18, a3, v2\n"  //6
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v20, a3, v2\n"       //7
                  "vle16.v          v1, (%[a_ptr])\n"  // Load A[B].lower
                  "add            a1, %[b_ptr], 0x8\n"
                  "vle16.v          v4, (a1)\n"  // Load B[2].lower
                  "add            a1, %[b_ptr], 0x18\n"
                  "vle16.v          v2, (a1)\n"  // Load B[0].lower

                  "vse16.v          v0, (%[s])\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v22, a3, v3\n"   //0

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //1
                  "vsetvli  t0, a2, e32, m1\n"
                  "vmv.v.i v23, 0\n"
                  "vadd.vv        v23, v23, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v24, a3, v3\n"  //2
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"  //3
                  "vsetvli  t0, a2, e32, m1\n"
                  "vmv.v.i v25, 0\n"
                  "vadd.vv        v25, v25, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v26, a3, v3\n"  //4
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"  //5
                  "vsetvli  t0, a2, e32, m1\n"
                  "vmv.v.i v27, 0\n"
                  "vadd.vv        v27, v27, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v28, a3, v3\n"  //6
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"  //7
                  "vsetvli  t0, a2, e32, m1\n"
                  "vmv.v.i v29, 0\n"
                  "vadd.vv        v29, v29, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  // Second unroll
                  "vse16.v          v1, (%[s])\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //0
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v6, v6, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //1
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v8, v8, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //2
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v10, v10, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //3
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v12, v12, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //4
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v14, v14, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //5
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v16, v16, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //6
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v18, v18, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //7
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v20, v20, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "add            a1, %[a_ptr], 0x10\n"
                  "vle16.v          v0, (a1)\n"  // Load A[A].lower
                  "add %[a_ptr], %[a_ptr], 0x20\n"

                  "vse16.v          v1, (%[s])\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v4, a3\n"   //0
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v7, v7, v30\n"
                  "vadd.vv        v22, v22, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v4, a3\n"   //1
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v9, v9, v30\n"
                  "vadd.vv        v23, v23, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v4, a3\n"   //2
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v11, v11, v30\n"
                  "vadd.vv        v24, v24, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v4, a3\n"   //3
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v13, v13, v30\n"
                  "vadd.vv        v25, v25, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v4, a3\n"   //4
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v15, v15, v30\n"
                  "vadd.vv        v26, v26, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v4, a3\n"   //5
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v17, v17, v30\n"
                  "vadd.vv        v27, v27, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v4, a3\n"   //6
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v19, v19, v30\n"
                  "vadd.vv        v28, v28, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v4, a3\n"   //7
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v21, v21, v30\n"
                  "vadd.vv        v29, v29, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[k], %[k], -0x1\n"
                  "add            a1, %[b_ptr], 0x28\n"
                  "vle16.v          v3, (a1)\n"  // Load B[1].lower
                  "add            %[b_ptr], %[b_ptr], 0x30\n"
                  "bnez           %[k],1b\n"


                  "2:\n"  // Even tail
                  "bnez           %[odd_k],3f\n"

                  "vse16.v          v0, (%[s])\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v6, a3, v2\n"   //0
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v8, a3, v2\n"   //1
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v10, a3, v2\n"  //2
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v12, a3, v2\n"  //3
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v14, a3, v2\n"  //4
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v16, a3, v2\n"  //5
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v18, a3, v2\n"  //6
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v20, a3, v2\n"       //7

                  "vle16.v          v1, (%[a_ptr])\n"  // Load A[B].lower
                  "add            a1, %[b_ptr], 0x8\n"
                  "vle16.v          v4, (a1)\n"  // Load B[2].lower
                  "add            %[a_ptr], %[a_ptr], 0x10\n"
                  "add            %[b_ptr], %[b_ptr], 0x18\n"

                  "vmv.v.v        v5, v23\n"
                  "vse16.v          v0, (%[s])\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v22, a3, v3\n"   //0
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //1
                  "vsetvli  t0, a2, e32, m1\n"
                  "vmv.v.i        v23, 0\n"
                  "vadd.vv        v23, v5, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "vmv.v.v        v5, v25\n"
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v24, a3, v3\n"  //2
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"  //3
                  "vsetvli  t0, a2, e32, m1\n"
                  "vmv.v.i        v25, 0\n"
                  "vadd.vv        v25, v5, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "vmv.v.v        v5, v27\n"
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v26, a3, v3\n"  //4
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"  //5
                  "vsetvli  t0, a2, e32, m1\n"
                  "vmv.v.i        v27, 0\n"
                  "vadd.vv        v27, v5, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "vmv.v.v        v5, v29\n"
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v28, a3, v3\n"  //6
                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"  //7
                  "vsetvli  t0, a2, e32, m1\n"
                  "vmv.v.i        v29, 0\n"
                  "vadd.vv        v29, v5, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "vse16.v          v1, (%[s])\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //0
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v6, v6, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"
                  "vwmulu.vx       v30, v4, a3\n"   //0
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v7, v7, v30\n"
                  "vadd.vv        v22, v22, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //1
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v8, v8, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"
                  "vwmulu.vx       v30, v4, a3\n"   //1
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v9, v9, v30\n"
                  "vadd.vv        v23, v23, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //2
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v10, v10, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"
                  "vwmulu.vx       v30, v4, a3\n"   //2
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v11, v11, v30\n"
                  "vadd.vv        v24, v24, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //3
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v12, v12, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"
                  "vwmulu.vx       v30, v4, a3\n"   //3
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v13, v13, v30\n"
                  "vadd.vv        v25, v25, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //4
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v14, v14, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"
                  "vwmulu.vx       v30, v4, a3\n"   //4
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v15, v15, v30\n"
                  "vadd.vv        v26, v26, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //5
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v16, v16, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"
                  "vwmulu.vx       v30, v4, a3\n"   //5
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v17, v17, v30\n"
                  "vadd.vv        v27, v27, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //6
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v18, v18, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"
                  "vwmulu.vx       v30, v4, a3\n"   //6
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v19, v19, v30\n"
                  "vadd.vv        v28, v28, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmulu.vx       v30, v3, a3\n"   //7
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v20, v20, v31\n"
                  "vsetvli  t0, a0, e16, m1\n"
                  "vwmulu.vx       v30, v4, a3\n"   //7
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v21, v21, v30\n"
                  "vadd.vv        v29, v29, v31\n"

                  "vse32.v          v6, (%[c_ptr])\n"
                  "add            a1, %[c_ptr], 0x10\n"
                  "vse32.v          v7, (a1)\n"
                  "add            a1, %[c_ptr], 0x20\n"
                  "vse32.v          v22, (a1)\n"
                  "add            a1, %[c_ptr], 0x30\n"
                  "vse32.v          v8, (a1)\n"
                  "add            a1, %[c_ptr], 0x40\n"
                  "vse32.v          v9, (a1)\n"
                  "add            a1, %[c_ptr], 0x50\n"
                  "vse32.v          v23, (a1)\n"
                  "add            a1, %[c_ptr], 0x60\n"
                  "vse32.v          v10, (a1)\n"
                  "add            a1, %[c_ptr], 0x70\n"
                  "vse32.v          v11, (a1)\n"
                  "add            a1, %[c_ptr], 0x80\n"
                  "vse32.v          v24, (a1)\n"
                  "add            a1, %[c_ptr], 0x90\n"
                  "vse32.v          v12, (a1)\n"
                  "add            a1, %[c_ptr], 0xa0\n"
                  "vse32.v          v13, (a1)\n"
                  "add            a1, %[c_ptr], 0xb0\n"
                  "vse32.v          v25, (a1)\n"
                  "add            a1, %[c_ptr], 0xc0\n"
                  "vse32.v          v14, (a1)\n"
                  "add            a1, %[c_ptr], 0xd0\n"
                  "vse32.v          v15, (a1)\n"
                  "add            a1, %[c_ptr], 0xe0\n"
                  "vse32.v          v26, (a1)\n"
                  "add            a1, %[c_ptr], 0xf0\n"
                  "vse32.v          v16, (a1)\n"
                  "add            a1, %[c_ptr], 0x100\n"
                  "vse32.v          v17, (a1)\n"
                  "add            a1, %[c_ptr], 0x110\n"
                  "vse32.v          v27, (a1)\n"
                  "add            a1, %[c_ptr], 0x120\n"
                  "vse32.v          v18, (a1)\n"
                  "add            a1, %[c_ptr], 0x130\n"
                  "vse32.v          v19, (a1)\n"
                  "vsetvli  t0, a0, e16, m1\n"
                  "j              4f\n"  // Complete write out

                  "3:\n"  // Odd tail

                  "vse16.v          v0, (%[s])\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v6, a3, v2\n"   //0
                  "vwmulu.vx       v30, v3, a3\n"   //0
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v22, v22, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v8, a3, v2\n"   //1
                  "vwmulu.vx       v30, v3, a3\n"
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v23, v23, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"


                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v10, a3, v2\n"  //2
                  "vwmulu.vx       v30, v3, a3\n"
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v24, v24, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v12, a3, v2\n"  //3
                  "vwmulu.vx       v30, v3, a3\n"
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v25, v25, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v14, a3, v2\n"  //4
                  "vwmulu.vx       v30, v3, a3\n"
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v26, v26, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v16, a3, v2\n"  //5
                  "vwmulu.vx       v30, v3, a3\n"
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v27, v27, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v18, a3, v2\n"  //6
                  "vwmulu.vx       v30, v3, a3\n"
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v28, v28, v30\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "addi           %[s], %[s], 2\n"
                  "lhu             a3, (%[s])\n"
                  "vwmaccu.vx      v20, a3, v2\n"       //7
                  "vwmulu.vx       v30, v3, a3\n"
                  "vsetvli  t0, a2, e32, m1\n"
                  "vadd.vv        v29, v29, v30\n"

                  "vse32.v          v6, (%[c_ptr])\n"
                  "add            a1, %[c_ptr], 0x10\n"
                  "vse32.v          v7, (a1)\n"
                  "add            a1, %[c_ptr], 0x20\n"
                  "vse32.v          v22, (a1)\n"
                  "add            a1, %[c_ptr], 0x30\n"
                  "vse32.v          v8, (a1)\n"
                  "add            a1, %[c_ptr], 0x40\n"
                  "vse32.v          v9, (a1)\n"
                  "add            a1, %[c_ptr], 0x50\n"
                  "vse32.v          v23, (a1)\n"
                  "add            a1, %[c_ptr], 0x60\n"
                  "vse32.v          v10, (a1)\n"
                  "add            a1, %[c_ptr], 0x70\n"
                  "vse32.v          v11, (a1)\n"
                  "add            a1, %[c_ptr], 0x80\n"
                  "vse32.v          v24, (a1)\n"
                  "add            a1, %[c_ptr], 0x90\n"
                  "vse32.v          v12, (a1)\n"
                  "add            a1, %[c_ptr], 0xa0\n"
                  "vse32.v          v13, (a1)\n"
                  "add            a1, %[c_ptr], 0xb0\n"
                  "vse32.v          v25, (a1)\n"
                  "add            a1, %[c_ptr], 0xc0\n"
                  "vse32.v          v14, (a1)\n"
                  "add            a1, %[c_ptr], 0xd0\n"
                  "vse32.v          v15, (a1)\n"
                  "add            a1, %[c_ptr], 0xe0\n"
                  "vse32.v          v26, (a1)\n"
                  "add            a1, %[c_ptr], 0xf0\n"
                  "vse32.v          v16, (a1)\n"
                  "add            a1, %[c_ptr], 0x100\n"
                  "vse32.v          v17, (a1)\n"
                  "add            a1, %[c_ptr], 0x110\n"
                  "vse32.v          v27, (a1)\n"
                  "add            a1, %[c_ptr], 0x120\n"
                  "vse32.v          v18, (a1)\n"
                  "vsetvli  t0, a0, e16, m1\n"

                  "4:\n"  // End of function
                  "vsetvli  t0, a0, e32, m1\n"
                  "add            a1, %[c_ptr], 0x130\n"
                  "vse32.v          v19, (a1)\n"
                  "add            a1, %[c_ptr], 0x140\n"
                  "vse32.v          v28, (a1)\n"
                  "add            a1, %[c_ptr], 0x150\n"
                  "vse32.v          v20, (a1)\n"
                  "add            a1, %[c_ptr], 0x160\n"
                  "vse32.v          v21, (a1)\n"
                  "add            a1, %[c_ptr], 0x170\n"
                  "vse32.v          v29, (a1)\n"
                  "add            %[c_ptr], %[c_ptr], 0x180\n"

                  : [a_ptr] "+r" (a_ptr), [b_ptr] "+r" (b_ptr), [c_ptr] "+r" (c_ptr), [k] "+r" (k), [s] "+r" (s)
                  : [odd_k] "r" (odd_k)
                  : "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15", "v16", "v17",
					"v18", "v19", "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31",
					"t0", "t1", "a0", "a1", "a2", "a3"
          );
    }
  }
}

} // namespace arm_gemm

#endif
