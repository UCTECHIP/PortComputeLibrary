/*
 * Copyright (c) 2018-2019 ARM Limited.
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
#include "impl_fp32_fp32.hpp"

namespace depthwise
{

using namespace neon_convolution_kernels;
using Conv = DepthwiseConvolution<3, 3, 3, 3, 2, 2, float, float, float>;

//#ifdef __aarch64__
#ifdef __support__	//no support now,__aarch64__ -> __support__
template <>
template <>
void Conv::execute_tile<ActivationFunction::None>(
  int n_channels,
  const void* weight_bias_ptr,
  const float* input,
  const unsigned int input_row_stride,
  const unsigned int input_col_stride,
  float* output,
  const unsigned int output_row_stride,
  const unsigned int output_col_stride
)
{
  __asm __volatile(
    "add x15, %[inptr0], %[input_row_stride]\n"
    "add x26, %[input_col_stride1], %[input_col_stride1]\n"
    "add x21, %[outptr0], %[output_row_stride]\n"
    "add x16, x15, %[input_row_stride]\n"
    "add x27, x26, %[input_col_stride1]\n"
    "add x22, x21, %[output_row_stride]\n"
    "add x17, x16, %[input_row_stride]\n"
    "add x28, x27, %[input_col_stride1]\n"
    "add x23, %[output_col_stride1], %[output_col_stride1]\n"
    "add x9, x17, %[input_row_stride]\n"
    "add x13, x28, %[input_col_stride1]\n"
    "and x24, %[n_channels], #3\n"
    "add x19, x9, %[input_row_stride]\n"
    "add x14, x13, %[input_col_stride1]\n"
    "lsr x25, %[n_channels], #2\n"
    "add x20, x19, %[input_row_stride]\n"
    "cbz x25, 4f\n"
    "1:\n"
    "ldr q27, [%[wbptr]]\n"
    "subs x25, x25, #1\n"
    "mov v17.16b, v27.16b\n"
    "ldr q6, [%[wbptr], #16]\n"
    "mov v16.16b, v27.16b\n"
    "ldr q14, [%[wbptr], #32]\n"
    "mov v15.16b, v27.16b\n"
    "ldr q13, [%[wbptr], #48]\n"
    "mov v2.16b, v27.16b\n"
    "ldr q12, [%[wbptr], #64]\n"
    "mov v4.16b, v27.16b\n"
    "ldr q11, [%[wbptr], #80]\n"
    "mov v5.16b, v27.16b\n"
    "ldr q10, [%[wbptr], #96]\n"
    "mov v1.16b, v27.16b\n"
    "ldr q9, [%[wbptr], #112]\n"
    "mov v3.16b, v27.16b\n"
    "ldr q8, [%[wbptr], #128]\n"
    "mov v0.16b, v27.16b\n"
    "ldr q7, [%[wbptr], #144]\n"
    "ldr q29, [%[inptr0]]\n"
    "ldr q28, [x15]\n"
    "ldr q26, [%[inptr0], %[input_col_stride1]]\n"
    "ldr q22, [x16]\n"
    "ldr q20, [x15, %[input_col_stride1]]\n"
    "ldr q19, [%[inptr0], x26]\n"
    "ldr q30, [x17]\n"
    "ldr q18, [x16, %[input_col_stride1]]\n"
    "beq 3f\n"
    "2:\n"
    "fmla v17.4s, v29.4s, v6.4s\n"
    "ldr q21, [x15, x26]\n"
    "fmla v16.4s, v22.4s, v6.4s\n"
    "ldr q27, [%[inptr0], x27]\n"
    "fmla v15.4s, v19.4s, v6.4s\n"
    "add %[wbptr], %[wbptr], #160\n"
    "fmla v17.4s, v28.4s, v12.4s\n"
    "ldr q25, [x9]\n"
    "fmla v16.4s, v30.4s, v12.4s\n"
    "ldr q24, [x17, %[input_col_stride1]]\n"
    "fmla v15.4s, v21.4s, v12.4s\n"
    "prfm pldl1keep, [%[wbptr], #64]\n"
    "fmla v17.4s, v26.4s, v14.4s\n"
    "ldr q23, [x16, x26]\n"
    "fmla v16.4s, v18.4s, v14.4s\n"
    "subs x25, x25, #1\n"
    "fmla v15.4s, v27.4s, v14.4s\n"
    "ldr q26, [x15, x27]\n"
    "fmla v17.4s, v22.4s, v9.4s\n"
    "ldr q22, [%[inptr0], x28]\n"
    "fmla v16.4s, v25.4s, v9.4s\n"
    "fmla v2.4s, v25.4s, v6.4s\n"
    "fmla v15.4s, v23.4s, v9.4s\n"
    "ldr q30, [x19]\n"
    "fmla v17.4s, v20.4s, v11.4s\n"
    "ldr q29, [x9, %[input_col_stride1]]\n"
    "fmla v16.4s, v24.4s, v11.4s\n"
    "ldr q28, [x17, x26]\n"
    "fmla v4.4s, v23.4s, v6.4s\n"
    "fmla v15.4s, v26.4s, v11.4s\n"
    "fmla v17.4s, v19.4s, v13.4s\n"
    "ldr q24, [x16, x27]\n"
    "fmla v16.4s, v23.4s, v13.4s\n"
    "ldr q25, [x15, x28]\n"
    "fmla v15.4s, v22.4s, v13.4s\n"
    "fmla v5.4s, v22.4s, v6.4s\n"
    "fmla v17.4s, v18.4s, v8.4s\n"
    "ldr q19, [%[inptr0], x13]\n"
    "fmla v2.4s, v30.4s, v12.4s\n"
    "ldr q18, [x20]\n"
    "fmla v16.4s, v29.4s, v8.4s\n"
    "ldr q22, [x19, %[input_col_stride1]]\n"
    "fmla v17.4s, v21.4s, v10.4s\n"
    "ldr q26, [x9, x26]\n"
    "fmla v2.4s, v29.4s, v14.4s\n"
    "ldr q20, [x17, x27]\n"
    "fmla v16.4s, v28.4s, v10.4s\n"
    "fmla v4.4s, v28.4s, v12.4s\n"
    "fmla v17.4s, v23.4s, v7.4s\n"
    "ldr q27, [x16, x28]\n"
    "fmla v15.4s, v24.4s, v8.4s\n"
    "ldr q30, [x15, x13]\n"
    "fmla v4.4s, v24.4s, v14.4s\n"
    "ldr q24, [%[inptr0], x14]\n"
    "str q17, [%[outptr0]]\n"
    "fmla v5.4s, v25.4s, v12.4s\n"
    "fmla v15.4s, v25.4s, v10.4s\n"
    "ldr q28, [x20, %[input_col_stride1]]\n"
    "fmla v2.4s, v18.4s, v9.4s\n"
    "ldr q17, [x19, x26]\n"
    "fmla v5.4s, v19.4s, v14.4s\n"
    "ldr q18, [x9, x27]\n"
    "fmla v16.4s, v26.4s, v7.4s\n"
    "ldr q25, [x17, x28]\n"
    "fmla v2.4s, v22.4s, v11.4s\n"
    "ldr q22, [x16, x13]\n"
    "fmla v4.4s, v26.4s, v9.4s\n"
    "add %[inptr0], %[inptr0], #16\n"
    "str q16, [x21]\n"
    "fmla v1.4s, v26.4s, v6.4s\n"
    "fmla v2.4s, v26.4s, v13.4s\n"
    "ldr q21, [x15, x14]\n"
    "fmla v4.4s, v20.4s, v11.4s\n"
    "ldr q23, [x20, x26]\n"
    "fmla v15.4s, v27.4s, v7.4s\n"
    "ldr q19, [x19, x27]\n"
    "fmla v5.4s, v27.4s, v9.4s\n"
    "add x15, x15, #16\n"
    "fmla v4.4s, v27.4s, v13.4s\n"
    "fmla v3.4s, v27.4s, v6.4s\n"
    "str q15, [%[outptr0], %[output_col_stride1]]\n"
    "fmla v2.4s, v28.4s, v8.4s\n"
    "fmla v5.4s, v30.4s, v11.4s\n"
    "ldr q29, [x9, x28]\n"
    "fmla v1.4s, v17.4s, v12.4s\n"
    "ldr q27, [x17, x13]\n"
    "fmla v2.4s, v17.4s, v10.4s\n"
    "ldr q28, [x16, x14]\n"
    "fmla v5.4s, v24.4s, v13.4s\n"
    "ldr q26, [x20, x27]\n"
    "fmla v4.4s, v18.4s, v8.4s\n"
    "ldr q20, [x19, x28]\n"
    "fmla v1.4s, v18.4s, v14.4s\n"
    "ldr q17, [x9, x13]\n"
    "fmla v3.4s, v25.4s, v12.4s\n"
    "ldr q18, [x17, x14]\n"
    "fmla v4.4s, v25.4s, v10.4s\n"
    "ldr q16, [x20, x28]\n"
    "fmla v5.4s, v22.4s, v8.4s\n"
    "add x16, x16, #16\n"
    "fmla v3.4s, v22.4s, v14.4s\n"
    "ldr q15, [x19, x13]\n"
    "fmla v2.4s, v23.4s, v7.4s\n"
    "add x17, x17, #16\n"
    "fmla v5.4s, v21.4s, v10.4s\n"
    "ldr q21, [x9, x14]\n"
    "fmla v1.4s, v23.4s, v9.4s\n"
    "ldr q23, [x20, x13]\n"
    "str q2, [x22]\n"
    "fmla v4.4s, v29.4s, v7.4s\n"
    "fmla v3.4s, v29.4s, v9.4s\n"
    "ldr q24, [x19, x14]\n"
    "fmla v1.4s, v19.4s, v11.4s\n"
    "ldr q25, [x20, x14]\n"
    "str q4, [x21, %[output_col_stride1]]\n"
    "fmla v0.4s, v29.4s, v6.4s\n"
    "fmla v3.4s, v27.4s, v11.4s\n"
    "ldr q27, [%[wbptr]]\n"
    "fmla v1.4s, v29.4s, v13.4s\n"
    "ldr q29, [%[inptr0]]\n"
    "fmla v5.4s, v28.4s, v7.4s\n"
    "ldr q6, [%[wbptr], #16]\n"
    "fmla v3.4s, v28.4s, v13.4s\n"
    "ldr q28, [x15]\n"
    "fmla v1.4s, v26.4s, v8.4s\n"
    "ldr q26, [%[inptr0], %[input_col_stride1]]\n"
    "str q5, [%[outptr0], x23]\n"
    "fmla v0.4s, v20.4s, v12.4s\n"
    "fmla v3.4s, v17.4s, v8.4s\n"
    "ldr q22, [x16]\n"
    "fmla v1.4s, v20.4s, v10.4s\n"
    "ldr q20, [x15, %[input_col_stride1]]\n"
    "fmla v0.4s, v17.4s, v14.4s\n"
    "ldr q12, [%[wbptr], #64]\n"
    "fmla v3.4s, v18.4s, v10.4s\n"
    "ldr q19, [%[inptr0], x26]\n"
    "fmla v1.4s, v16.4s, v7.4s\n"
    "ldr q30, [x17]\n"
    "fmla v0.4s, v16.4s, v9.4s\n"
    "ldr q14, [%[wbptr], #32]\n"
    "fmla v3.4s, v21.4s, v7.4s\n"
    "ldr q18, [x16, %[input_col_stride1]]\n"
    "str q1, [x22, %[output_col_stride1]]\n"
    "mov v17.16b, v27.16b\n"
    "fmla v0.4s, v15.4s, v11.4s\n"
    "ldr q9, [%[wbptr], #112]\n"
    "str q3, [x21, x23]\n"
    "mov v16.16b, v27.16b\n"
    "mov v15.16b, v27.16b\n"
    "add x9, x9, #16\n"
    "fmla v0.4s, v21.4s, v13.4s\n"
    "ldr q11, [%[wbptr], #80]\n"
    "mov v2.16b, v27.16b\n"
    "add x19, x19, #16\n"
    "mov v4.16b, v27.16b\n"
    "add x20, x20, #16\n"
    "fmla v0.4s, v23.4s, v8.4s\n"
    "ldr q13, [%[wbptr], #48]\n"
    "mov v5.16b, v27.16b\n"
    "add %[outptr0], %[outptr0], #16\n"
    "mov v1.16b, v27.16b\n"
    "add x21, x21, #16\n"
    "fmla v0.4s, v24.4s, v10.4s\n"
    "ldr q8, [%[wbptr], #128]\n"
    "mov v3.16b, v27.16b\n"
    "fmla v0.4s, v25.4s, v7.4s\n"
    "ldr q10, [%[wbptr], #96]\n"
    "str q0, [x22, x23]\n"
    "mov v0.16b, v27.16b\n"
    "ldr q7, [%[wbptr], #144]\n"
    "add x22, x22, #16\n"
    "bne 2b\n"
    "3:\n"
    "fmla v17.4s, v29.4s, v6.4s\n"
    "ldr q21, [x15, x26]\n"
    "fmla v16.4s, v22.4s, v6.4s\n"
    "ldr q27, [%[inptr0], x27]\n"
    "fmla v15.4s, v19.4s, v6.4s\n"
    "add %[wbptr], %[wbptr], #160\n"
    "fmla v17.4s, v28.4s, v12.4s\n"
    "ldr q25, [x9]\n"
    "fmla v16.4s, v30.4s, v12.4s\n"
    "ldr q24, [x17, %[input_col_stride1]]\n"
    "fmla v15.4s, v21.4s, v12.4s\n"
    "prfm pldl1keep, [%[wbptr], #64]\n"
    "fmla v17.4s, v26.4s, v14.4s\n"
    "ldr q23, [x16, x26]\n"
    "fmla v16.4s, v18.4s, v14.4s\n"
    "fmla v2.4s, v25.4s, v6.4s\n"
    "fmla v15.4s, v27.4s, v14.4s\n"
    "ldr q26, [x15, x27]\n"
    "fmla v17.4s, v22.4s, v9.4s\n"
    "ldr q22, [%[inptr0], x28]\n"
    "fmla v16.4s, v25.4s, v9.4s\n"
    "ldr q30, [x19]\n"
    "fmla v15.4s, v23.4s, v9.4s\n"
    "fmla v4.4s, v23.4s, v6.4s\n"
    "fmla v17.4s, v20.4s, v11.4s\n"
    "ldr q29, [x9, %[input_col_stride1]]\n"
    "fmla v16.4s, v24.4s, v11.4s\n"
    "ldr q28, [x17, x26]\n"
    "fmla v15.4s, v26.4s, v11.4s\n"
    "ldr q24, [x16, x27]\n"
    "fmla v17.4s, v19.4s, v13.4s\n"
    "ldr q25, [x15, x28]\n"
    "fmla v16.4s, v23.4s, v13.4s\n"
    "fmla v5.4s, v22.4s, v6.4s\n"
    "fmla v15.4s, v22.4s, v13.4s\n"
    "ldr q19, [%[inptr0], x13]\n"
    "fmla v17.4s, v18.4s, v8.4s\n"
    "ldr q18, [x20]\n"
    "fmla v2.4s, v30.4s, v12.4s\n"
    "ldr q22, [x19, %[input_col_stride1]]\n"
    "fmla v16.4s, v29.4s, v8.4s\n"
    "fmla v4.4s, v28.4s, v12.4s\n"
    "fmla v17.4s, v21.4s, v10.4s\n"
    "ldr q26, [x9, x26]\n"
    "fmla v2.4s, v29.4s, v14.4s\n"
    "ldr q20, [x17, x27]\n"
    "fmla v16.4s, v28.4s, v10.4s\n"
    "ldr q27, [x16, x28]\n"
    "fmla v17.4s, v23.4s, v7.4s\n"
    "ldr q30, [x15, x13]\n"
    "fmla v15.4s, v24.4s, v8.4s\n"
    "fmla v4.4s, v24.4s, v14.4s\n"
    "fmla v5.4s, v25.4s, v12.4s\n"
    "ldr q24, [%[inptr0], x14]\n"
    "str q17, [%[outptr0]]\n"
    "fmla v2.4s, v18.4s, v9.4s\n"
    "fmla v15.4s, v25.4s, v10.4s\n"
    "ldr q28, [x20, %[input_col_stride1]]\n"
    "fmla v5.4s, v19.4s, v14.4s\n"
    "ldr q17, [x19, x26]\n"
    "fmla v2.4s, v22.4s, v11.4s\n"
    "ldr q18, [x9, x27]\n"
    "fmla v16.4s, v26.4s, v7.4s\n"
    "ldr q25, [x17, x28]\n"
    "fmla v4.4s, v26.4s, v9.4s\n"
    "ldr q22, [x16, x13]\n"
    "fmla v2.4s, v26.4s, v13.4s\n"
    "add %[inptr0], %[inptr0], #16\n"
    "str q16, [x21]\n"
    "fmla v1.4s, v26.4s, v6.4s\n"
    "fmla v4.4s, v20.4s, v11.4s\n"
    "ldr q21, [x15, x14]\n"
    "fmla v15.4s, v27.4s, v7.4s\n"
    "ldr q23, [x20, x26]\n"
    "fmla v5.4s, v27.4s, v9.4s\n"
    "ldr q19, [x19, x27]\n"
    "fmla v4.4s, v27.4s, v13.4s\n"
    "add x15, x15, #16\n"
    "str q15, [%[outptr0], %[output_col_stride1]]\n"
    "fmla v3.4s, v27.4s, v6.4s\n"
    "fmla v5.4s, v30.4s, v11.4s\n"
    "ldr q29, [x9, x28]\n"
    "fmla v2.4s, v28.4s, v8.4s\n"
    "ldr q27, [x17, x13]\n"
    "fmla v1.4s, v17.4s, v12.4s\n"
    "ldr q28, [x16, x14]\n"
    "fmla v5.4s, v24.4s, v13.4s\n"
    "ldr q26, [x20, x27]\n"
    "fmla v2.4s, v17.4s, v10.4s\n"
    "ldr q20, [x19, x28]\n"
    "fmla v4.4s, v18.4s, v8.4s\n"
    "ldr q17, [x9, x13]\n"
    "fmla v1.4s, v18.4s, v14.4s\n"
    "ldr q18, [x17, x14]\n"
    "fmla v3.4s, v25.4s, v12.4s\n"
    "add x16, x16, #16\n"
    "fmla v4.4s, v25.4s, v10.4s\n"
    "ldr q16, [x20, x28]\n"
    "fmla v5.4s, v22.4s, v8.4s\n"
    "add x17, x17, #16\n"
    "fmla v3.4s, v22.4s, v14.4s\n"
    "ldr q15, [x19, x13]\n"
    "fmla v2.4s, v23.4s, v7.4s\n"
    "fmla v1.4s, v23.4s, v9.4s\n"
    "fmla v5.4s, v21.4s, v10.4s\n"
    "ldr q21, [x9, x14]\n"
    "fmla v4.4s, v29.4s, v7.4s\n"
    "ldr q23, [x20, x13]\n"
    "str q2, [x22]\n"
    "fmla v1.4s, v19.4s, v11.4s\n"
    "fmla v3.4s, v29.4s, v9.4s\n"
    "ldr q24, [x19, x14]\n"
    "str q4, [x21, %[output_col_stride1]]\n"
    "fmla v0.4s, v29.4s, v6.4s\n"
    "fmla v1.4s, v29.4s, v13.4s\n"
    "ldr q25, [x20, x14]\n"
    "fmla v3.4s, v27.4s, v11.4s\n"
    "add x9, x9, #16\n"
    "fmla v5.4s, v28.4s, v7.4s\n"
    "add x19, x19, #16\n"
    "fmla v1.4s, v26.4s, v8.4s\n"
    "add x20, x20, #16\n"
    "fmla v3.4s, v28.4s, v13.4s\n"
    "fmla v0.4s, v20.4s, v12.4s\n"
    "str q5, [%[outptr0], x23]\n"
    "fmla v1.4s, v20.4s, v10.4s\n"
    "fmla v3.4s, v17.4s, v8.4s\n"
    "add %[outptr0], %[outptr0], #16\n"
    "fmla v0.4s, v17.4s, v14.4s\n"
    "fmla v1.4s, v16.4s, v7.4s\n"
    "fmla v3.4s, v18.4s, v10.4s\n"
    "fmla v0.4s, v16.4s, v9.4s\n"
    "str q1, [x22, %[output_col_stride1]]\n"
    "fmla v3.4s, v21.4s, v7.4s\n"
    "fmla v0.4s, v15.4s, v11.4s\n"
    "str q3, [x21, x23]\n"
    "fmla v0.4s, v21.4s, v13.4s\n"
    "add x21, x21, #16\n"
    "fmla v0.4s, v23.4s, v8.4s\n"
    "fmla v0.4s, v24.4s, v10.4s\n"
    "fmla v0.4s, v25.4s, v7.4s\n"
    "str q0, [x22, x23]\n"
    "add x22, x22, #16\n"
    "4:\n"
    "cbz x24, 7f\n"
    "ldr s27, [%[wbptr]]\n"
    "mov v17.16b, v27.16b\n"
    "ldr s6, [%[wbptr], #4]\n"
    "mov v16.16b, v27.16b\n"
    "ldr s14, [%[wbptr], #8]\n"
    "mov v15.16b, v27.16b\n"
    "ldr s13, [%[wbptr], #12]\n"
    "mov v2.16b, v27.16b\n"
    "ldr s12, [%[wbptr], #16]\n"
    "mov v4.16b, v27.16b\n"
    "ldr s11, [%[wbptr], #20]\n"
    "mov v5.16b, v27.16b\n"
    "ldr s10, [%[wbptr], #24]\n"
    "mov v1.16b, v27.16b\n"
    "ldr s9, [%[wbptr], #28]\n"
    "mov v3.16b, v27.16b\n"
    "ldr s8, [%[wbptr], #32]\n"
    "mov v0.16b, v27.16b\n"
    "ldr s7, [%[wbptr], #36]\n"
    "ldr s29, [%[inptr0]]\n"
    "subs x24, x24, #1\n"
    "ldr s28, [x15]\n"
    "ldr s26, [%[inptr0], %[input_col_stride1]]\n"
    "ldr s22, [x16]\n"
    "ldr s20, [x15, %[input_col_stride1]]\n"
    "ldr s19, [%[inptr0], x26]\n"
    "ldr s30, [x17]\n"
    "ldr s18, [x16, %[input_col_stride1]]\n"
    "beq 6f\n"
    "5:\n"
    "fmla v17.4s, v29.4s, v6.4s\n"
    "ldr s21, [x15, x26]\n"
    "fmla v16.4s, v22.4s, v6.4s\n"
    "ldr s27, [%[inptr0], x27]\n"
    "fmla v15.4s, v19.4s, v6.4s\n"
    "add %[wbptr], %[wbptr], #40\n"
    "fmla v17.4s, v28.4s, v12.4s\n"
    "ldr s25, [x9]\n"
    "fmla v16.4s, v30.4s, v12.4s\n"
    "ldr s24, [x17, %[input_col_stride1]]\n"
    "fmla v15.4s, v21.4s, v12.4s\n"
    "prfm pldl1keep, [%[wbptr], #64]\n"
    "fmla v17.4s, v26.4s, v14.4s\n"
    "ldr s23, [x16, x26]\n"
    "fmla v16.4s, v18.4s, v14.4s\n"
    "subs x24, x24, #1\n"
    "fmla v15.4s, v27.4s, v14.4s\n"
    "ldr s26, [x15, x27]\n"
    "fmla v17.4s, v22.4s, v9.4s\n"
    "ldr s22, [%[inptr0], x28]\n"
    "fmla v16.4s, v25.4s, v9.4s\n"
    "fmla v2.4s, v25.4s, v6.4s\n"
    "fmla v15.4s, v23.4s, v9.4s\n"
    "ldr s30, [x19]\n"
    "fmla v17.4s, v20.4s, v11.4s\n"
    "ldr s29, [x9, %[input_col_stride1]]\n"
    "fmla v16.4s, v24.4s, v11.4s\n"
    "ldr s28, [x17, x26]\n"
    "fmla v4.4s, v23.4s, v6.4s\n"
    "fmla v15.4s, v26.4s, v11.4s\n"
    "fmla v17.4s, v19.4s, v13.4s\n"
    "ldr s24, [x16, x27]\n"
    "fmla v16.4s, v23.4s, v13.4s\n"
    "ldr s25, [x15, x28]\n"
    "fmla v15.4s, v22.4s, v13.4s\n"
    "fmla v5.4s, v22.4s, v6.4s\n"
    "fmla v17.4s, v18.4s, v8.4s\n"
    "ldr s19, [%[inptr0], x13]\n"
    "fmla v2.4s, v30.4s, v12.4s\n"
    "ldr s18, [x20]\n"
    "fmla v16.4s, v29.4s, v8.4s\n"
    "ldr s22, [x19, %[input_col_stride1]]\n"
    "fmla v17.4s, v21.4s, v10.4s\n"
    "ldr s26, [x9, x26]\n"
    "fmla v2.4s, v29.4s, v14.4s\n"
    "ldr s20, [x17, x27]\n"
    "fmla v16.4s, v28.4s, v10.4s\n"
    "fmla v4.4s, v28.4s, v12.4s\n"
    "fmla v17.4s, v23.4s, v7.4s\n"
    "ldr s27, [x16, x28]\n"
    "fmla v15.4s, v24.4s, v8.4s\n"
    "ldr s30, [x15, x13]\n"
    "fmla v4.4s, v24.4s, v14.4s\n"
    "ldr s24, [%[inptr0], x14]\n"
    "str s17, [%[outptr0]]\n"
    "fmla v5.4s, v25.4s, v12.4s\n"
    "fmla v15.4s, v25.4s, v10.4s\n"
    "ldr s28, [x20, %[input_col_stride1]]\n"
    "fmla v2.4s, v18.4s, v9.4s\n"
    "ldr s17, [x19, x26]\n"
    "fmla v5.4s, v19.4s, v14.4s\n"
    "ldr s18, [x9, x27]\n"
    "fmla v16.4s, v26.4s, v7.4s\n"
    "ldr s25, [x17, x28]\n"
    "fmla v2.4s, v22.4s, v11.4s\n"
    "ldr s22, [x16, x13]\n"
    "fmla v4.4s, v26.4s, v9.4s\n"
    "add %[inptr0], %[inptr0], #4\n"
    "str s16, [x21]\n"
    "fmla v1.4s, v26.4s, v6.4s\n"
    "fmla v2.4s, v26.4s, v13.4s\n"
    "ldr s21, [x15, x14]\n"
    "fmla v4.4s, v20.4s, v11.4s\n"
    "ldr s23, [x20, x26]\n"
    "fmla v15.4s, v27.4s, v7.4s\n"
    "ldr s19, [x19, x27]\n"
    "fmla v5.4s, v27.4s, v9.4s\n"
    "add x15, x15, #4\n"
    "fmla v4.4s, v27.4s, v13.4s\n"
    "fmla v3.4s, v27.4s, v6.4s\n"
    "str s15, [%[outptr0], %[output_col_stride1]]\n"
    "fmla v2.4s, v28.4s, v8.4s\n"
    "fmla v5.4s, v30.4s, v11.4s\n"
    "ldr s29, [x9, x28]\n"
    "fmla v1.4s, v17.4s, v12.4s\n"
    "ldr s27, [x17, x13]\n"
    "fmla v2.4s, v17.4s, v10.4s\n"
    "ldr s28, [x16, x14]\n"
    "fmla v5.4s, v24.4s, v13.4s\n"
    "ldr s26, [x20, x27]\n"
    "fmla v4.4s, v18.4s, v8.4s\n"
    "ldr s20, [x19, x28]\n"
    "fmla v1.4s, v18.4s, v14.4s\n"
    "ldr s17, [x9, x13]\n"
    "fmla v3.4s, v25.4s, v12.4s\n"
    "ldr s18, [x17, x14]\n"
    "fmla v4.4s, v25.4s, v10.4s\n"
    "ldr s16, [x20, x28]\n"
    "fmla v5.4s, v22.4s, v8.4s\n"
    "add x16, x16, #4\n"
    "fmla v3.4s, v22.4s, v14.4s\n"
    "ldr s15, [x19, x13]\n"
    "fmla v2.4s, v23.4s, v7.4s\n"
    "add x17, x17, #4\n"
    "fmla v5.4s, v21.4s, v10.4s\n"
    "ldr s21, [x9, x14]\n"
    "fmla v1.4s, v23.4s, v9.4s\n"
    "ldr s23, [x20, x13]\n"
    "str s2, [x22]\n"
    "fmla v4.4s, v29.4s, v7.4s\n"
    "fmla v3.4s, v29.4s, v9.4s\n"
    "ldr s24, [x19, x14]\n"
    "fmla v1.4s, v19.4s, v11.4s\n"
    "ldr s25, [x20, x14]\n"
    "str s4, [x21, %[output_col_stride1]]\n"
    "fmla v0.4s, v29.4s, v6.4s\n"
    "fmla v3.4s, v27.4s, v11.4s\n"
    "ldr s27, [%[wbptr]]\n"
    "fmla v1.4s, v29.4s, v13.4s\n"
    "ldr s29, [%[inptr0]]\n"
    "fmla v5.4s, v28.4s, v7.4s\n"
    "ldr s6, [%[wbptr], #4]\n"
    "fmla v3.4s, v28.4s, v13.4s\n"
    "ldr s28, [x15]\n"
    "fmla v1.4s, v26.4s, v8.4s\n"
    "ldr s26, [%[inptr0], %[input_col_stride1]]\n"
    "str s5, [%[outptr0], x23]\n"
    "fmla v0.4s, v20.4s, v12.4s\n"
    "fmla v3.4s, v17.4s, v8.4s\n"
    "ldr s22, [x16]\n"
    "fmla v1.4s, v20.4s, v10.4s\n"
    "ldr s20, [x15, %[input_col_stride1]]\n"
    "fmla v0.4s, v17.4s, v14.4s\n"
    "ldr s12, [%[wbptr], #16]\n"
    "fmla v3.4s, v18.4s, v10.4s\n"
    "ldr s19, [%[inptr0], x26]\n"
    "fmla v1.4s, v16.4s, v7.4s\n"
    "ldr s30, [x17]\n"
    "fmla v0.4s, v16.4s, v9.4s\n"
    "ldr s14, [%[wbptr], #8]\n"
    "fmla v3.4s, v21.4s, v7.4s\n"
    "ldr s18, [x16, %[input_col_stride1]]\n"
    "str s1, [x22, %[output_col_stride1]]\n"
    "mov v17.16b, v27.16b\n"
    "fmla v0.4s, v15.4s, v11.4s\n"
    "ldr s9, [%[wbptr], #28]\n"
    "str s3, [x21, x23]\n"
    "mov v16.16b, v27.16b\n"
    "mov v15.16b, v27.16b\n"
    "add x9, x9, #4\n"
    "fmla v0.4s, v21.4s, v13.4s\n"
    "ldr s11, [%[wbptr], #20]\n"
    "mov v2.16b, v27.16b\n"
    "add x19, x19, #4\n"
    "mov v4.16b, v27.16b\n"
    "add x20, x20, #4\n"
    "fmla v0.4s, v23.4s, v8.4s\n"
    "ldr s13, [%[wbptr], #12]\n"
    "mov v5.16b, v27.16b\n"
    "add %[outptr0], %[outptr0], #4\n"
    "mov v1.16b, v27.16b\n"
    "add x21, x21, #4\n"
    "fmla v0.4s, v24.4s, v10.4s\n"
    "ldr s8, [%[wbptr], #32]\n"
    "mov v3.16b, v27.16b\n"
    "fmla v0.4s, v25.4s, v7.4s\n"
    "ldr s10, [%[wbptr], #24]\n"
    "str s0, [x22, x23]\n"
    "mov v0.16b, v27.16b\n"
    "ldr s7, [%[wbptr], #36]\n"
    "add x22, x22, #4\n"
    "bne 5b\n"
    "6:\n"
    "fmla v17.4s, v29.4s, v6.4s\n"
    "ldr s21, [x15, x26]\n"
    "fmla v16.4s, v22.4s, v6.4s\n"
    "ldr s27, [%[inptr0], x27]\n"
    "fmla v15.4s, v19.4s, v6.4s\n"
    "add %[wbptr], %[wbptr], #40\n"
    "fmla v17.4s, v28.4s, v12.4s\n"
    "ldr s25, [x9]\n"
    "fmla v16.4s, v30.4s, v12.4s\n"
    "ldr s24, [x17, %[input_col_stride1]]\n"
    "fmla v15.4s, v21.4s, v12.4s\n"
    "prfm pldl1keep, [%[wbptr], #64]\n"
    "fmla v17.4s, v26.4s, v14.4s\n"
    "ldr s23, [x16, x26]\n"
    "fmla v16.4s, v18.4s, v14.4s\n"
    "fmla v2.4s, v25.4s, v6.4s\n"
    "fmla v15.4s, v27.4s, v14.4s\n"
    "ldr s26, [x15, x27]\n"
    "fmla v17.4s, v22.4s, v9.4s\n"
    "ldr s22, [%[inptr0], x28]\n"
    "fmla v16.4s, v25.4s, v9.4s\n"
    "ldr s30, [x19]\n"
    "fmla v15.4s, v23.4s, v9.4s\n"
    "fmla v4.4s, v23.4s, v6.4s\n"
    "fmla v17.4s, v20.4s, v11.4s\n"
    "ldr s29, [x9, %[input_col_stride1]]\n"
    "fmla v16.4s, v24.4s, v11.4s\n"
    "ldr s28, [x17, x26]\n"
    "fmla v15.4s, v26.4s, v11.4s\n"
    "ldr s24, [x16, x27]\n"
    "fmla v17.4s, v19.4s, v13.4s\n"
    "ldr s25, [x15, x28]\n"
    "fmla v16.4s, v23.4s, v13.4s\n"
    "fmla v5.4s, v22.4s, v6.4s\n"
    "fmla v15.4s, v22.4s, v13.4s\n"
    "ldr s19, [%[inptr0], x13]\n"
    "fmla v17.4s, v18.4s, v8.4s\n"
    "ldr s18, [x20]\n"
    "fmla v2.4s, v30.4s, v12.4s\n"
    "ldr s22, [x19, %[input_col_stride1]]\n"
    "fmla v16.4s, v29.4s, v8.4s\n"
    "fmla v4.4s, v28.4s, v12.4s\n"
    "fmla v17.4s, v21.4s, v10.4s\n"
    "ldr s26, [x9, x26]\n"
    "fmla v2.4s, v29.4s, v14.4s\n"
    "ldr s20, [x17, x27]\n"
    "fmla v16.4s, v28.4s, v10.4s\n"
    "ldr s27, [x16, x28]\n"
    "fmla v17.4s, v23.4s, v7.4s\n"
    "ldr s30, [x15, x13]\n"
    "fmla v15.4s, v24.4s, v8.4s\n"
    "fmla v4.4s, v24.4s, v14.4s\n"
    "fmla v5.4s, v25.4s, v12.4s\n"
    "ldr s24, [%[inptr0], x14]\n"
    "str s17, [%[outptr0]]\n"
    "fmla v2.4s, v18.4s, v9.4s\n"
    "fmla v15.4s, v25.4s, v10.4s\n"
    "ldr s28, [x20, %[input_col_stride1]]\n"
    "fmla v5.4s, v19.4s, v14.4s\n"
    "ldr s17, [x19, x26]\n"
    "fmla v2.4s, v22.4s, v11.4s\n"
    "ldr s18, [x9, x27]\n"
    "fmla v16.4s, v26.4s, v7.4s\n"
    "ldr s25, [x17, x28]\n"
    "fmla v4.4s, v26.4s, v9.4s\n"
    "ldr s22, [x16, x13]\n"
    "fmla v2.4s, v26.4s, v13.4s\n"
    "add %[inptr0], %[inptr0], #4\n"
    "str s16, [x21]\n"
    "fmla v1.4s, v26.4s, v6.4s\n"
    "fmla v4.4s, v20.4s, v11.4s\n"
    "ldr s21, [x15, x14]\n"
    "fmla v15.4s, v27.4s, v7.4s\n"
    "ldr s23, [x20, x26]\n"
    "fmla v5.4s, v27.4s, v9.4s\n"
    "ldr s19, [x19, x27]\n"
    "fmla v4.4s, v27.4s, v13.4s\n"
    "add x15, x15, #4\n"
    "str s15, [%[outptr0], %[output_col_stride1]]\n"
    "fmla v3.4s, v27.4s, v6.4s\n"
    "fmla v5.4s, v30.4s, v11.4s\n"
    "ldr s29, [x9, x28]\n"
    "fmla v2.4s, v28.4s, v8.4s\n"
    "ldr s27, [x17, x13]\n"
    "fmla v1.4s, v17.4s, v12.4s\n"
    "ldr s28, [x16, x14]\n"
    "fmla v5.4s, v24.4s, v13.4s\n"
    "ldr s26, [x20, x27]\n"
    "fmla v2.4s, v17.4s, v10.4s\n"
    "ldr s20, [x19, x28]\n"
    "fmla v4.4s, v18.4s, v8.4s\n"
    "ldr s17, [x9, x13]\n"
    "fmla v1.4s, v18.4s, v14.4s\n"
    "ldr s18, [x17, x14]\n"
    "fmla v3.4s, v25.4s, v12.4s\n"
    "add x16, x16, #4\n"
    "fmla v4.4s, v25.4s, v10.4s\n"
    "ldr s16, [x20, x28]\n"
    "fmla v5.4s, v22.4s, v8.4s\n"
    "add x17, x17, #4\n"
    "fmla v3.4s, v22.4s, v14.4s\n"
    "ldr s15, [x19, x13]\n"
    "fmla v2.4s, v23.4s, v7.4s\n"
    "fmla v1.4s, v23.4s, v9.4s\n"
    "fmla v5.4s, v21.4s, v10.4s\n"
    "ldr s21, [x9, x14]\n"
    "fmla v4.4s, v29.4s, v7.4s\n"
    "ldr s23, [x20, x13]\n"
    "str s2, [x22]\n"
    "fmla v1.4s, v19.4s, v11.4s\n"
    "fmla v3.4s, v29.4s, v9.4s\n"
    "ldr s24, [x19, x14]\n"
    "str s4, [x21, %[output_col_stride1]]\n"
    "fmla v0.4s, v29.4s, v6.4s\n"
    "fmla v1.4s, v29.4s, v13.4s\n"
    "ldr s25, [x20, x14]\n"
    "fmla v3.4s, v27.4s, v11.4s\n"
    "add x9, x9, #4\n"
    "fmla v5.4s, v28.4s, v7.4s\n"
    "add x19, x19, #4\n"
    "fmla v1.4s, v26.4s, v8.4s\n"
    "add x20, x20, #4\n"
    "fmla v3.4s, v28.4s, v13.4s\n"
    "fmla v0.4s, v20.4s, v12.4s\n"
    "str s5, [%[outptr0], x23]\n"
    "fmla v1.4s, v20.4s, v10.4s\n"
    "fmla v3.4s, v17.4s, v8.4s\n"
    "add %[outptr0], %[outptr0], #4\n"
    "fmla v0.4s, v17.4s, v14.4s\n"
    "fmla v1.4s, v16.4s, v7.4s\n"
    "fmla v3.4s, v18.4s, v10.4s\n"
    "fmla v0.4s, v16.4s, v9.4s\n"
    "str s1, [x22, %[output_col_stride1]]\n"
    "fmla v3.4s, v21.4s, v7.4s\n"
    "fmla v0.4s, v15.4s, v11.4s\n"
    "str s3, [x21, x23]\n"
    "fmla v0.4s, v21.4s, v13.4s\n"
    "add x21, x21, #4\n"
    "fmla v0.4s, v23.4s, v8.4s\n"
    "fmla v0.4s, v24.4s, v10.4s\n"
    "fmla v0.4s, v25.4s, v7.4s\n"
    "str s0, [x22, x23]\n"
    "add x22, x22, #4\n"
    "7:\n"
    : [wbptr] "+r" (weight_bias_ptr), [inptr0] "+r" (input), [outptr0] "+r" (output)
    : [n_channels] "r" ((long long) n_channels), [output_col_stride1] "r" (output_col_stride * sizeof(float)), [input_row_stride] "r" (input_row_stride * sizeof(float)), [input_col_stride1] "r" (input_col_stride * sizeof(float)), [output_row_stride] "r" (output_row_stride * sizeof(float))
    : "cc", "v0", "v1", "v10", "v11", "v12", "v13", "v14", "v15", "v16", "v17", "v18", "v19", "v2", "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v3", "v30", "v4", "v5", "v6", "v7", "v8", "v9", "x15", "x16", "x17", "x9", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x13", "x14", "memory"
  );
}
#endif  // __aarch64__

template class DepthwiseConvolution<3, 3, 3, 3, 2, 2, float, float, float>;

}  // namespace depthwise
