#include "../include/stitching/featuring/orb/orb_featuring.h"

#include <stitching/core/factory.h>

#include <exception>

using stitching::core::IFeaturing;
using stitching::core::IFeaturingPtr;
REGISTER_TYPE(IFeaturing, OrbFeaturing, [](const std::string&) -> IFeaturingPtr {
  return std::make_shared<stitching::featuring::OrbFeaturing>();
});

namespace stitching::featuring {

void OrbFeaturing::init() {
  detector = cv::ORB::create(nfeatures, scaleFactor, nlevels, edgeThreshold, firstLevel, WTA_K,
                             scoreType, patchSize, fastThreshold);
}

core::FeaturesUPtr OrbFeaturing::exec(const cv::Mat& img) const {
  if (img.empty())
    throw std::invalid_argument("Empty image");

  auto result = std::make_unique<core::Features>();

  detector->detectAndCompute(img, cv::noArray(), result->keyPoints, result->descriptors);

  return result;
}

void OrbFeaturing::free() { detector = nullptr; }

void OrbFeaturing::setNFeatures(int n_features) { nfeatures = n_features; }

void OrbFeaturing::setScaleFactor(double scale_Factor) { scaleFactor = scale_Factor; }

void OrbFeaturing::setNLevels(int n_levels) { nlevels = n_levels; }

void OrbFeaturing::setEdgeThreshold(int edge_threshold) { edgeThreshold = edge_threshold; }

void OrbFeaturing::setFirstLevel(int first_level) { firstLevel = first_level; }

void OrbFeaturing::setWTA_K(int wta_k) { WTA_K = wta_k; }

void OrbFeaturing::setScoreType(cv::ORB::ScoreType score_type) { scoreType = score_type; }

void OrbFeaturing::setPatchSize(int patch_size) { patchSize = patch_size; }

void OrbFeaturing::setFastThreshold(int fast_threshold) { fastThreshold = fast_threshold; }

}  // namespace stitching::featuring
