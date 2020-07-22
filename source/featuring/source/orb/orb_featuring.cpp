#include <iostream>

#include "orb_featuring.h"


using cv::Mat;

void OrbFeaturing::init() {detector = cv::ORB::create(nfeatures, scaleFactor, nlevels, edgeThreshold, firstLevel, WTA_K, scoreType, patchSize, fastThreshold);}

cv::Ptr<Features> OrbFeaturing::exec(const cv::Mat &img) const {

    if (img.empty()) {
        std::cout << "Could not open or find the image!\n" << std::endl;
        return {};
    }

    std::vector<cv::KeyPoint> keyPoints;
    Mat                  descriptors;

    detector->detectAndCompute(img, cv::noArray(), keyPoints, descriptors);

    return cv::makePtr<Features>(keyPoints, descriptors);
}

void OrbFeaturing::free() { detector = nullptr; }



void OrbFeaturing::setNFeatures(int n_features) { nfeatures = n_features; }

void OrbFeaturing::setScaleFactor(float scale_Factor) { scaleFactor = scale_Factor; }

void OrbFeaturing::setNLevels(int n_levels) { nlevels = n_levels; }

void OrbFeaturing::setEdgeThreshold(int edge_threshold) { edgeThreshold = edge_threshold;}

void OrbFeaturing::setFirstLevel(int first_level) { firstLevel = first_level; }

void OrbFeaturing::setWTA_K(int wta_k) { WTA_K = wta_k; }

void OrbFeaturing::setScoreType(cv::ORB::ScoreType score_type) { scoreType = score_type; }

void OrbFeaturing::setPatchSize(int patch_size) { patchSize = patch_size; }

void OrbFeaturing::setFastThreshold(int fast_threshold) { fastThreshold = fast_threshold; }
