#include "../include/stitching/core/logging.h"

#include <spdlog/cfg/argv.h>
#include <spdlog/cfg/env.h>
#include <spdlog/common.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/systemd_sink.h>

#include <atomic>
#include <chrono>
#include <filesystem>
#include <opencv2/imgcodecs.hpp>

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

static auto img_log_path = []() {
  auto path = std::filesystem::temp_directory_path() / "log_img" /
              std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
  if (!std::filesystem::exists(path))
    std::filesystem::create_directories(path);
  return path;
}();

std::string saveLogImage(const cv::Mat &img) {
  static std::atomic_size_t img_counter = {0};

  if (!std::filesystem::exists(img_log_path))
    return "invalid_save_path";

  auto name = (img_log_path / (std::to_string(img_counter++) + ".png")).string();
  cv::imwrite(name, img);
  return name;
}

}  // namespace stitching::core
