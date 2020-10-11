#pragma once

#include <spdlog/fmt/fmt.h>
#include <spdlog/spdlog.h>

#include <opencv2/core/types.hpp>
#include <string_view>

namespace stitching::core {

using LoggerPtr = std::shared_ptr<spdlog::logger>;

void initLoggers(int argc, char** argv);

LoggerPtr getLogger(std::string_view name);

std::string saveLogImage(const cv::Mat&);

}  // namespace stitching::core

template <typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_same<std::remove_cv_t<T>, cv::Mat>::value, char>>
    : fmt::formatter<std::string> {
  template <typename FormatCtx>
  auto format(const cv::Mat& img, FormatCtx& ctx) {
    auto name = "[" + stitching::core::saveLogImage(img) + "]";
    return fmt::formatter<std::string>::format(name, ctx);
  }
};
