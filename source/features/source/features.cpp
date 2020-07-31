#include "ifeatures.h"

#include <utility>

IFeatures::IFeatures(std::vector<cv::KeyPoint> keyPoints, cv::Mat descriptors)
    : keyPoints(std::move(keyPoints))
    , descriptors(std::move(descriptors)) {}
