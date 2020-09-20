#pragma once

#include <stitching/core/features.h>

#include <opencv2/core/mat.hpp>

namespace stitching::core {

class IFeaturing {
 public:
  virtual ~IFeaturing() = default;

  virtual void init() = 0;
  virtual void free() = 0;

  virtual FeaturesUPtr exec(const cv::Mat &) const = 0;
};

}  // namespace stitching::core
