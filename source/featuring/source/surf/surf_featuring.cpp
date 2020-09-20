#include "../include/stitching/featuring/surf/surf_featuring.h"

#include <stitching/core/factory.h>

#include <exception>

using stitching::core::IFeaturing;
using stitching::core::IFeaturingPtr;
REGISTER_TYPE(IFeaturing, SurfFeaturing, [](const std::string&) -> IFeaturingPtr {
  return std::make_shared<stitching::featuring::SurfFeaturing>();
});

namespace stitching::featuring {

core::FeaturesUPtr SurfFeaturing::exec(const cv::Mat& img) const {
  if (img.empty())
    throw std::invalid_argument("Empty image.");

  auto result = std::make_unique<core::Features>();

  detector->detectAndCompute(img, cv::noArray(), result->keyPoints, result->descriptors);

  return result;
}

void SurfFeaturing::init() {
  detector =
      cv::xfeatures2d::SURF::create(hessianThreshold, nOctaves, nOctaveLayers, extended, upright);
}

void SurfFeaturing::free() { detector = nullptr; }

void SurfFeaturing::setHessianThreshold(double val) { hessianThreshold = val; }
void SurfFeaturing::setNOctaves(int val) { nOctaves = val; }
void SurfFeaturing::setNOctaveLayers(int val) { nOctaveLayers = val; }
void SurfFeaturing::setExtended(bool val) { extended = val; }
void SurfFeaturing::setUpright(bool val) { upright = val; }

}  // namespace stitching::featuring
