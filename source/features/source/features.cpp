#include "features/features.h"

#include <utility>

Features::IFeatures(std::vector<cv::KeyPoint> keyPoints, cv::Mat descriptors)
    : keyPoints(std::move(keyPoints))
    , descriptors(std::move(descriptors)) {}
