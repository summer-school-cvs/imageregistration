#include <gtest/gtest.h>
#include <stitching/core/factory.h>
#include <stitching/core/ifeaturing.h>
#include <stitching/core/ihomography.h>
#include <stitching/core/imatching.h>
#include <stitching/core/iwarping.h>

using stitching::core::IFeaturing;
using stitching::core::IHomography;
using stitching::core::IMatcher;
using stitching::core::IWarping;

namespace bpt = boost::property_tree;

using namespace stitching::core;

DEFINE_TYPE(IFeaturing, SurfFeaturing);
DEFINE_TYPE(IFeaturing, OrbFeaturing);
DEFINE_TYPE(IHomography, Homography);
DEFINE_TYPE(IMatcher, KnnMatcher);
DEFINE_TYPE(IWarping, Warping);

namespace {

TEST(FactoryTest, create) {
  boost::property_tree::ptree config;
  auto surf    = Factory::create<IFeaturing, const bpt::ptree&>(IFeaturingSurfFeaturingKey, config);
  auto orb     = Factory::create<IFeaturing, const bpt::ptree&>(IFeaturingOrbFeaturingKey, config);
  auto homo    = Factory::create<IHomography, const bpt::ptree&>(IHomographyHomographyKey, config);
  auto matcher = Factory::create<IMatcher, const bpt::ptree&>(IMatcherKnnMatcherKey, config);
  auto warping = Factory::create<IWarping, const bpt::ptree&>(IWarpingWarpingKey, config);

  EXPECT_NE(nullptr, surf);
  EXPECT_NE(nullptr, orb);
  EXPECT_NE(nullptr, homo);
  EXPECT_NE(nullptr, matcher);
  EXPECT_NE(nullptr, warping);
}

}  // namespace
