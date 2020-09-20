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

DEFINE_TYPE(IFeaturing, SurfFeaturing);
DEFINE_TYPE(IFeaturing, OrbFeaturing);
DEFINE_TYPE(IHomography, Homography);
DEFINE_TYPE(IMatcher, KnnMatcher);
DEFINE_TYPE(IWarping, Warping);

namespace {

TEST(FactoryTest, create) {
  auto surf       = stitching::core::Factory::create<IFeaturing>(SurfFeaturingKey);
  auto orb        = stitching::core::Factory::create<IFeaturing>(OrbFeaturingKey);
  auto homography = stitching::core::Factory::create<IHomography>(HomographyKey);
  auto matcher    = stitching::core::Factory::create<IMatcher>(KnnMatcherKey);
  auto warping    = stitching::core::Factory::create<IWarping>(WarpingKey);

  EXPECT_NE(nullptr, surf);
  EXPECT_NE(nullptr, orb);
  EXPECT_NE(nullptr, homography);
  EXPECT_NE(nullptr, matcher);
  EXPECT_NE(nullptr, warping);
}

}  // namespace

#include <stitching/featuring/orb/orb_featuring.h>
#include <stitching/featuring/surf/surf_featuring.h>
#include <stitching/homography/homography.h>
#include <stitching/matching/knn_matching.h>
#include <stitching/warping/warping.h>

using namespace stitching;

namespace {

TEST(FactoryTest, create_check_types) {
  auto surf       = stitching::core::Factory::create<IFeaturing>(SurfFeaturingKey);
  auto orb        = stitching::core::Factory::create<IFeaturing>(OrbFeaturingKey);
  auto homography = stitching::core::Factory::create<IHomography>(HomographyKey);
  auto matcher    = stitching::core::Factory::create<IMatcher>(KnnMatcherKey);
  auto warping    = stitching::core::Factory::create<IWarping>(WarpingKey);

  EXPECT_NE(nullptr, std::dynamic_pointer_cast<featuring::SurfFeaturing>(surf));
  EXPECT_NE(nullptr, std::dynamic_pointer_cast<featuring::OrbFeaturing>(orb));
  EXPECT_NE(nullptr, std::dynamic_pointer_cast<homography::Homography>(homography));
  EXPECT_NE(nullptr, std::dynamic_pointer_cast<matching::KnnMatching>(matcher));
  EXPECT_NE(nullptr, std::dynamic_pointer_cast<warping::Warping>(warping));
}

}  // namespace
