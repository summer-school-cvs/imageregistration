#pragma once

#include <opencv2/core/mat.hpp>


struct Features {
  Features(std::vector<cv::KeyPoint> keyPoints, cv::Mat descriptors);

  ~Features() = default;

  std::vector<cv::KeyPoint> keyPoints;
  cv::Mat                   descriptors;
};
