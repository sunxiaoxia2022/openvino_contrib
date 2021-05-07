// Copyright (C) 2018-2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "details/ie_no_copy.hpp"

#include "memory_manager/model/cuda_memory_model.hpp"

namespace CUDAPlugin {

/**
 * @brief Allocates and owns continuous memory blob on CUDA device.
 * Uses MemoryModel to determine a size of memory to allocate and
 * to map tensor offsets to device side pointers.
 */
class DeviceMemBlock : protected InferenceEngine::details::no_copy {
public:
  /**
   * @throws InferenceEngineException if device memory block allocation failed.
   */
  DeviceMemBlock(MemoryModel::Ptr model);

  ~DeviceMemBlock();

  /**
   * Provides tensor memory address if any.
   *
   * @param [in] id Tensor identifier.
   * @returns device memory pointer if tensor is located within the blob
   * or nullptr otherwise.
   */
  void* deviceTensorPtr(MemoryModel::TensorID id);

private:
  MemoryModel::Ptr model_;
  void* device_mem_ptr_;
};

}  // namespace CUDAPlugin