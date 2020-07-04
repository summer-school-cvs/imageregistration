#pragma once

#include <opencv2/core/mat.hpp>

class Pipeline {
 public:
  Pipeline() = default;

  ~Pipeline() = default;

  std::vector<cv::Mat> runPipeline(const cv::Mat &img, const cv::Mat &img2) const;
};
