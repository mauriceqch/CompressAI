#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

class rANSEncoderInterface {
public:
  rANSEncoderInterface() = default;

  rANSEncoderInterface(const rANSEncoderInterface &) = delete;
  rANSEncoderInterface(rANSEncoderInterface &&) = delete;
  rANSEncoderInterface &operator=(const rANSEncoderInterface &) = delete;
  rANSEncoderInterface &operator=(rANSEncoderInterface &&) = delete;

  py::bytes encode_with_indexes(const std::vector<int32_t> &symbols,
                                const std::vector<int32_t> &indexes,
                                const std::vector<std::vector<int32_t>> &cdfs,
                                const std::vector<int32_t> &cdfs_sizes,
                                const std::vector<int32_t> &offsets);
};

class rANSDecoderInterface {
public:
  rANSDecoderInterface() = default;

  rANSDecoderInterface(const rANSDecoderInterface &) = delete;
  rANSDecoderInterface(rANSDecoderInterface &&) = delete;
  rANSDecoderInterface &operator=(const rANSDecoderInterface &) = delete;
  rANSDecoderInterface &operator=(rANSDecoderInterface &&) = delete;

  std::vector<int32_t>
  decode_with_indexes(const std::string &encoded,
                      const std::vector<int32_t> &indexes,
                      const std::vector<std::vector<int32_t>> &cdfs,
                      const std::vector<int32_t> &cdfs_sizes,
                      const std::vector<int32_t> &offsets);
};