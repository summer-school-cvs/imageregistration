#include "../include/stitching/core/logging.h"

#include <spdlog/cfg/argv.h>
#include <spdlog/cfg/env.h>
#include <spdlog/common.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/systemd_sink.h>

namespace {

std::vector<spdlog::sink_ptr> createSinks() {
  std::vector<spdlog::sink_ptr> sinks;

#ifdef LOG_IN_STDOUT_ENABLE
  sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
#endif
#ifdef LOG_IN_SYSTEMD_ENABLE
  sinks.push_back(std::make_shared<spdlog::sinks::systemd_sink_st>());
#endif

  return sinks;
}

}  // namespace

namespace stitching::core {

void initLoggers(int argc, char **argv) {
  auto sinks  = createSinks();
  auto logger = std::make_shared<spdlog::logger>("", std::begin(sinks), std::end(sinks));
  spdlog::set_default_logger(std::move(logger));

  spdlog::cfg::load_env_levels();
  spdlog::cfg::load_argv_levels(argc, argv);
}

LoggerPtr getLogger(std::string_view name) {
  std::string name_str(name);
  auto        logger = spdlog::get(name_str);
  if (!logger) {
    auto sinks = createSinks();
    logger =
        std::make_shared<spdlog::logger>(std::move(name_str), std::begin(sinks), std::end(sinks));
    spdlog::register_logger(logger);
  }
  return logger;
}

}  // namespace stitching::core
