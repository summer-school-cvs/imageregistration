#pragma once

#include <opencv2/core/mat.hpp>

class Warping {
 public:
  virtual cv::Mat getWarping(const cv::Mat &img1,
                             const cv::Mat &img2,
                             const cv::Mat &homography) const = 0;
};
