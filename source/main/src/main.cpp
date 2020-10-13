#include <stitching/core/factory.h>
#include <stitching/core/istitcher.h>
#include <stitching/core/logging.h>

#include <boost/program_options.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <filesystem>
#include <iostream>
#include <opencv2/imgcodecs.hpp>

namespace po = boost::program_options;
namespace pt = boost::property_tree;

int main(int argc, char* argv[]) {
  stitching::core::initLoggers(argc, argv);

  try {
    std::string config_path;

    {
      po::variables_map       vm;
      po::options_description opts("Options");
      opts.add_options()  //
          ("config,c", po::value<std::string>(&config_path)->default_value(CONFIG_FILE),
           "configuration file path")            //
          ("version,v", "print version string")  //
          ("help,h", "produce help message");

      po::store(po::command_line_parser(argc, argv).options(opts).run(), vm);
      po::notify(vm);

      if (vm.count("help")) {
        std::cout << PROJECT_DESCRIPTION << std::endl;
        std::cout << opts << std::endl;
        std::exit(0);
      }

      if (vm.count("version")) {
        std::cout << "Version: " << PROJECT_VERSION << std::endl;
        std::exit(0);
      }
    }

    if (!std::filesystem::exists(config_path))
      throw std::invalid_argument("Configuration file \"" + config_path + "\" does not exist.");

    pt::ptree config;
    pt::read_json(config_path, config);

    auto& stitcher_conf = config.get_child("Stitcher");
    auto  stitcher_type = stitcher_conf.get<std::string>("type", "default");

    auto stitcher =
        stitching::core::Factory::create<stitching::core::IStitcher,
                                         const boost::property_tree::ptree&>(stitcher_type, config);

    if (!stitcher)
      throw std::runtime_error("Can't create \"" + stitcher_type + "\".");

    stitcher->configure(stitcher_conf);
    stitcher->init();
    auto pano = stitcher->exec({});
    stitcher->free();
  }
  catch (std::exception& e) {
    SPDLOG_ERROR("{}", e.what());
    return 1;
  }

  return 0;
}
