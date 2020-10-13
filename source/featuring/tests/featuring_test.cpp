#include <gtest/gtest.h>
#include <stitching/featuring/orb/orb_featuring.h>
#include <stitching/featuring/surf/surf_featuring.h>

#include <filesystem>
#include <opencv2/imgcodecs.hpp>

using namespace stitching::featuring;

namespace {

template <class T>
class FeaturingTest : public testing::Test {
 protected:
  void SetUp() override { featuring.init(); }
  void TearDown() override { featuring.free(); }

  T                           featuring;
  const std::filesystem::path test_dir = TEST_DATA_DIR;
};

using Implementations = testing::Types<OrbFeaturing, SurfFeaturing>;

TYPED_TEST_SUITE(FeaturingTest, Implementations);

TYPED_TEST(FeaturingTest, without_image) {
  EXPECT_THROW(this->featuring.exec(cv::Mat{}), std::invalid_argument);
}

TYPED_TEST(FeaturingTest, with_image) {
  auto image = cv::imread((this->test_dir / "indoors-close" / "0" / "0.jpg").string());

  auto features = this->featuring.exec(image);

  EXPECT_FALSE(features->keyPoints.empty());
}

}  // namespace
