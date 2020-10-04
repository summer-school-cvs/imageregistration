#pragma once

#include <spdlog/spdlog.h>

#include <string_view>

namespace stitching::core {

using LoggerPtr = std::shared_ptr<spdlog::logger>;

void initLoggers(int argc, char **argv);

LoggerPtr getLogger(std::string_view name);

}  // namespace stitching::core
