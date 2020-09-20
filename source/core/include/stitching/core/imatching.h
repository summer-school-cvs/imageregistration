#pragma once

#include <stitching/core/features.h>

#include <opencv2/core/mat.hpp>
#include <vector>

namespace stitching::core {

class IMatcher {
 public:
  virtual ~IMatcher() = default;

  virtual std::vector<cv::DMatch> exec(const FeaturesPtr&, const FeaturesPtr&, int) const = 0;

  virtual void init() = 0;
  virtual void free() = 0;
};

}  // namespace stitching::core
