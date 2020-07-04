#include "features.h"

#include <utility>

Features::Features(std::vector<cv::KeyPoint> keyPoints, cv::Mat descriptors)
    : keyPoints(std::move(keyPoints))
    , descriptors(std::move(descriptors)) {}
