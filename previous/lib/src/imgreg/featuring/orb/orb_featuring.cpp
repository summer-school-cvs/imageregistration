#include "orb_featuring.h"

#include <iostream>

#include "opencv2/features2d.hpp"

using cv::Mat;
using std::vector;

void OrbFeaturing::init() {
  detector = cv::ORB::create(nFeatures, scaleFactor, nLevels, edgeThreshold, firstLevel, WTA_K,
                             scoreType, patchSize, fastThreshold);
}

cv::Ptr<Features> OrbFeaturing::getFeatures(const cv::Mat &img) const {
  if (img.empty()) {
    std::cout << "Could not open or find the image!\n" << std::endl;
    return {};
  }

  vector<cv::KeyPoint> keyPoints;
  Mat                  descriptors;

  detector->detectAndCompute(img, cv::noArray(), keyPoints, descriptors);

  return cv::makePtr<Features>(keyPoints, descriptors);
}

void OrbFeaturing::free() { detector = nullptr; }

void OrbFeaturing::setNFeatures(int n_features) { OrbFeaturing::nFeatures = n_features; }

void OrbFeaturing::setScaleFactor(float scale_Factor) { OrbFeaturing::scaleFactor = scale_Factor; }

void OrbFeaturing::setNLevels(int n_levels) { OrbFeaturing::nLevels = n_levels; }

void OrbFeaturing::setEdgeThreshold(int edge_threshold) {
  OrbFeaturing::edgeThreshold = edge_threshold;
}

void OrbFeaturing::setFirstLevel(int first_level) { OrbFeaturing::firstLevel = first_level; }

void OrbFeaturing::setWtaK(int wtaK) { WTA_K = wtaK; }

void OrbFeaturing::setScoreType(cv::ORB::ScoreType score_type) {
  OrbFeaturing::scoreType = score_type;
}

void OrbFeaturing::setPatchSize(int patch_size) { OrbFeaturing::patchSize = patch_size; }

void OrbFeaturing::setFastThreshold(int fast_threshold) {
  OrbFeaturing::fastThreshold = fast_threshold;
}
