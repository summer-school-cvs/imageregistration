#pragma once

#include <memory>
#include <opencv2/core/types.hpp>
#include <vector>

namespace stitching::core {

struct Hypothesis {
  std::vector<cv::Point2f> first;
  std::vector<cv::Point2f> second;
  std::vector<cv::Mat>     homography;
};

using HypothesisPtr  = std::shared_ptr<Hypothesis>;
using HypothesisUPtr = std::unique_ptr<Hypothesis>;

}  // namespace stitching::core
