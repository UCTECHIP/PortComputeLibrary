/*
 * Copyright (c) 2017-2020 ARM Limited.
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
#ifndef ARM_COMPUTE_CLREDUCTIONOPERATION_H
#define ARM_COMPUTE_CLREDUCTIONOPERATION_H

#include "arm_compute/core/CL/kernels/CLFillBorderKernel.h"
#include "arm_compute/core/CL/kernels/CLReductionOperationKernel.h"
#include "arm_compute/core/CL/kernels/CLReshapeLayerKernel.h"
#include "arm_compute/core/Types.h"
#include "arm_compute/runtime/CL/CLTensor.h"
#include "arm_compute/runtime/IFunction.h"
#include "arm_compute/runtime/IMemoryManager.h"
#include "arm_compute/runtime/MemoryGroup.h"

#include <cstdint>
#include <memory>
#include <vector>

namespace arm_compute
{
class ICLTensor;

/** Perform reduction operation.
 */
class CLReductionOperation : public IFunction
{
public:
    /** Default Constructor.
     *
     * @param[in] memory_manager (Optional) Memory manager.
     */
    CLReductionOperation(std::shared_ptr<IMemoryManager> memory_manager = nullptr);

    /** Set the input and output tensors.
     *
     * @param[in]  input     Source tensor. Data types supported: QASYMM8/QASYMM8_SIGNED/F16/F32.
     * @param[out] output    Destination tensor. Data types and data layouts supported: Same as @p input.
     * @param[in]  axis      Axis along which to reduce. Supported reduction axis : 0, 1, 2, 3
     * @param[in]  op        Reduction operation to perform. Operations supported: MEAN_SUM, PROD, SUM_SQUARE, SUM, MIN, MAX
     * @param[in]  keep_dims (Optional) Whether to keep the reduced dimension after the operation. Defaults to true.
     */
    void configure(ICLTensor *input, ICLTensor *output, unsigned int axis, ReductionOperation op, bool keep_dims = true);
    /** Set the input and output tensors.
     *
     * @param[in]  compile_context The compile context to be used.
     * @param[in]  input           Source tensor. Data types supported: QASYMM8/QASYMM8_SIGNED/F16/F32.
     * @param[out] output          Destination tensor. Data types and data layouts supported: Same as @p input.
     * @param[in]  axis            Axis along which to reduce. Supported reduction axis : 0, 1, 2, 3
     * @param[in]  op              Reduction operation to perform. Operations supported: MEAN_SUM, PROD, SUM_SQUARE, SUM, MIN, MAX
     * @param[in]  keep_dims       (Optional) Whether to keep the reduced dimension after the operation. Defaults to true.
     */
    void configure(const CLCompileContext &compile_context, ICLTensor *input, ICLTensor *output, unsigned int axis, ReductionOperation op, bool keep_dims = true);

    /** Static function to check if given info will lead to a valid configuration of @ref CLReductionOperation.
     *
     * @param[in] input     Source tensor info. Data types supported: QASYMM8/QASYMM8_SIGNED/F16/F32.
     * @param[in] output    Destination tensor info. Data types and data layouts supported: Same as @p input.
     * @param[in] axis      Axis along which to reduce. Supported reduction axis : 0, 1, 2, 3
     * @param[in] op        Reduction operation to perform. Operations supported: MEAN_SUM, PROD, SUM_SQUARE, SUM, MIN, MAX
     * @param[in] keep_dims (Optional) Whether to keep the reduced dimension after the operation. Defaults to true.
     *
     * @return a status
     */
    static Status validate(const ITensorInfo *input, const ITensorInfo *output, unsigned int axis, ReductionOperation op, bool keep_dims = true);

    // Inherited methods overridden:
    void run() override;

private:
    ICLTensor *configure_intermediate_result_vector(ICLTensor *input, ICLTensor *output);

    MemoryGroup                             _memory_group;
    std::vector<CLTensor>                   _results_vector;
    std::vector<CLReductionOperationKernel> _reduction_kernels_vector;
    std::vector<CLFillBorderKernel>         _border_handlers_vector;
    CLReshapeLayerKernel                    _reshape_kernel;
    ReductionOperation                      _op;
    unsigned int                            _num_of_stages;
    unsigned int                            _reduction_axis;
    bool                                    _is_serial;
    bool                                    _is_reshape_required;
};
} // namespace arm_compute
#endif /* ARM_COMPUTE_CLREDUCTIONOPERATION_H */