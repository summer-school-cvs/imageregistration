#include <gtest/gtest.h>
#include <stitching/core/factory.h>
#include <stitching/core/istitcher.h>

#include <boost/property_tree/json_parser.hpp>
#include <filesystem>
#include <opencv2/imgcodecs.hpp>

namespace bpt = boost::property_tree;
namespace fs  = std::filesystem;

using namespace stitching::core;

DEFINE_TYPE(IStitcher, SimpleStitcher);
DEFINE_TYPE(IFeaturing, OrbFeaturing);
DEFINE_TYPE(IFeaturing, SurfFeaturing);
DEFINE_TYPE(IMatcher, KnnMatcher);
DEFINE_TYPE(IHomography, Homography);
DEFINE_TYPE(IWarping, Warping);

namespace {

std::list<fs::path> test_dirs() {
  std::list<fs::path> result;

  fs::path test_root = TEST_DATA_DIR;
  for (auto& p : fs::directory_iterator(test_root)) {
    for (auto& p : fs::directory_iterator(p.path()))
      result.push_back(p.path());
  }

  return result;
}

class SimpleStitcherTest : public testing::TestWithParam<fs::path> {};

TEST_P(SimpleStitcherTest, pipeline) {
  std::list<cv::Mat> images;
  for (auto& p : fs::directory_iterator(GetParam())) {
    images.push_back(cv::imread(p.path().string()));
  }

  bpt::ptree config;
  bpt::read_json(CONFIG_FILE, config);
  auto stitcher = Factory::create<IStitcher, const bpt::ptree&>(IStitcherSimpleStitcherKey, config);

  stitcher->init();
  auto result = stitcher->exec(std::move(images));
  stitcher->free();
}

INSTANTIATE_TEST_SUITE_P(InstantiationName, SimpleStitcherTest, testing::ValuesIn(test_dirs()));

}  // namespace
