#include <gtest/gtest.h>
#include <gtest/internal/gtest-type-util.h>

#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>

#include "../../lib/src/imgreg/featuring/featuring.h"
#include "../../lib/src/imgreg/featuring/orb/orb_featuring.h"
#include "../../lib/src/imgreg/featuring/surf/surf_featuring.h"

namespace {

template <class T>
Featuring* CreateFeaturing();

template <>
Featuring* CreateFeaturing<OrbFeaturing>() {
  return new OrbFeaturing();
}

template <>
Featuring* CreateFeaturing<SurfFeaturing>() {
  return new SurfFeaturing();
}

template <class T>
class FeaturingTest : public testing::Test {
 protected:
  FeaturingTest()
      : featuring(CreateFeaturing<T>()) {}

  ~FeaturingTest() override { delete featuring; }

  Featuring* const featuring;
};

template <class T>
class OrbFeaturingTest : public testing::Test {
 protected:
  OrbFeaturingTest()
      : orbFeaturing(dynamic_cast<OrbFeaturing* const>(CreateFeaturing<OrbFeaturing>())) {}

  void SetUp() override {
    orbFeaturing->setWtaK(2);
    orbFeaturing->setScaleFactor(1.2f);
    orbFeaturing->setFastThreshold(20);
    orbFeaturing->setPatchSize(31);
    orbFeaturing->setEdgeThreshold(31);
    orbFeaturing->setFirstLevel(0);
    orbFeaturing->setNLevels(8);
    orbFeaturing->setNFeatures(10);
    orbFeaturing->setScoreType(cv::ORB::FAST_SCORE);
  }

  void TearDown() override { orbFeaturing->free(); }

  OrbFeaturing* const orbFeaturing;
};

template <class T>
class SurfFeaturingTest : public testing::Test {
 protected:
  SurfFeaturingTest()
      : surf(dynamic_cast<SurfFeaturing* const>(CreateFeaturing<SurfFeaturing>())) {}

  void SetUp() override {}

  void TearDown() override { surf->free(); }

  SurfFeaturing* const surf;
};

using Implementations = testing::Types<OrbFeaturing, SurfFeaturing>;

TYPED_TEST_SUITE(FeaturingTest, Implementations);

TYPED_TEST(FeaturingTest, GreaterThanZero) {
  this->featuring->init();

  auto features =
      this->featuring->getFeatures(cv::imread(cv::samples::findFile("../../test/pics/img2_1.jpg")));

  ASSERT_GT(features->descriptors.size().width, 0);
  ASSERT_GT(features->descriptors.size().height, 0);
  ASSERT_GT(features->keyPoints.size(), 0);
}

}  // namespace
