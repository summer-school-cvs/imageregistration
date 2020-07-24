#pragma once

#include <opencv2/core/mat.hpp>

#include <vector>

namespace stitching::core {

class IMatcher {
 public:
  virtual ~IMatcher() = default;

  virtual void init() = 0;
  
  virtual std::vector<cv::DMatch> exec(const cv::Ptr<Features>, const cv::Ptr<Features>, int) const = 0;

  virtual void free() = 0;
};

}