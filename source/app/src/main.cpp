#include <boost/program_options.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>

namespace po = boost::program_options;
namespace pt = boost::property_tree;

int main(int argc, char* argv[]) {
  try {
    std::string config_path;

    {
      po::variables_map       vm;
      po::options_description opts("Options");
      opts.add_options()                                                                 //
          ("config,c", po::value<std::string>(&config_path), "configuration file path")  //
          ("version,v", "print version string")                                          //
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

    pt::ptree config;
    pt::read_json(config_path, config);
  }
  catch (std::exception& e) {
  }

  return 0;
}
