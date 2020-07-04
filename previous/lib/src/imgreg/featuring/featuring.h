#pragma once

#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <vector>

#include "../features/features.h"

class Featuring {
 public:
  virtual cv::Ptr<Features> getFeatures(const cv::Mat &) const = 0;

  virtual void init() = 0;

  virtual void free() = 0;
};
