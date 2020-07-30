#pragma once

#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>

#include<vector>

namespace stitching::core {

class IHomography {
 public:
  virtual ~IHomography() = default;

  virtual void init()                             = 0;
  virtual void exec(std::vector<cv::Point2f> &,
                    std::vector<cv::Point2f> &,
                    std::vector<cv::Mat> &) const = 0;
  virtual void free()                             = 0;
};

}  // namespace stitching::core
