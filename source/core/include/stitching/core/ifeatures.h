#pragma once

#include <opencv2/core/mat.hpp>


struct IFeatures {
  IFeatures(std::vector<cv::KeyPoint> keyPoints, cv::Mat descriptors);

  ~IFeatures() = default;

  std::vector<cv::KeyPoint> keyPoints;
  cv::Mat                   descriptors;
};
