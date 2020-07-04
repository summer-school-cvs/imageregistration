#pragma once

#include <opencv2/core/types.hpp>
#include <vector>

class Matching {
 public:
  virtual void init() = 0;

  virtual void free() = 0;

  virtual std::vector<cv::DMatch> getMatches(const cv::Ptr<Features>,
                                             const cv::Ptr<Features>,
                                             int) const = 0;
};
