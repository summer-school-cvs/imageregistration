#pragma once

#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <vector>

struct Features {
  Features(std::vector<cv::KeyPoint> keyPoints, cv::Mat descriptors);

  ~Features() = default;

  std::vector<cv::KeyPoint> keyPoints;
  cv::Mat                   descriptors;
};
