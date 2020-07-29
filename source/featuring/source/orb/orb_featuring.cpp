#include <iostream>

#include "orb_featuring.h"


using cv::Mat;

void OrbFeaturing::init() {detector = cv::ORB::create(nfeatures, scaleFactor, nlevels, edgeThreshold, firstLevel, WTA_K, scoreType, patchSize, fastThreshold);}

cv::Ptr<IFeatures> OrbFeaturing::exec(const cv::Mat &img) const {

    if (img.empty()) {
        std::cout << "Could not open or find the image!\n" << std::endl;
        return {};
    }

    std::vector<cv::KeyPoint> keyPoints;
    Mat                  descriptors;

    detector->detectAndCompute(img, cv::noArray(), keyPoints, descriptors);

    return cv::makePtr<IFeatures>(keyPoints, descriptors);
}

void OrbFeaturing::free() { detector = nullptr; }



void OrbFeaturing::setNFeatures(const int &n_features) { nfeatures = n_features; }

void OrbFeaturing::setScaleFactor(const double &scale_Factor) { scaleFactor = scale_Factor; }

void OrbFeaturing::setNLevels(const int &n_levels) { nlevels = n_levels; }

void OrbFeaturing::setEdgeThreshold(const int &edge_threshold) { edgeThreshold = edge_threshold;}

void OrbFeaturing::setFirstLevel(const int &first_level) { firstLevel = first_level; }

void OrbFeaturing::setWTA_K(const int &wta_k) { WTA_K = wta_k; }

void OrbFeaturing::setScoreType(const cv::ORB::ScoreType &score_type) { scoreType = score_type; }

void OrbFeaturing::setPatchSize(const int &patch_size) { patchSize = patch_size; }

void OrbFeaturing::setFastThreshold(const int &fast_threshold) { fastThreshold = fast_threshold; }
