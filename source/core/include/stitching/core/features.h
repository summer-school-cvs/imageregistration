#pragma once

#include <memory>
#include <opencv2/core/mat.hpp>

namespace stitching::core {

struct Features {
  std::vector<cv::KeyPoint> keyPoints;
  cv::Mat                   descriptors;
};

using FeaturesPtr  = std::shared_ptr<Features>;
using FeaturesUPtr = std::unique_ptr<Features>;

}  // namespace stitching::core
