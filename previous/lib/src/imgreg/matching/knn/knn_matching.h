#pragma once

#include <opencv2/core/types.hpp>

#include "../../features/features.h"
#include "../matching.h"
#include "opencv2/features2d.hpp"

class KnnMatching : public Matching {
 public:
  void init() override;

  std::vector<cv::DMatch> getMatches(cv::Ptr<Features>, cv::Ptr<Features>, int) const override;

  void free() override;

  void setMatcherType(cv::DescriptorMatcher::MatcherType matcherType);

  void setRatio(float ratio);

 private:
  cv::Ptr<cv::DescriptorMatcher>     matcher;
  cv::DescriptorMatcher::MatcherType matcherType;
  float                              ratio;
};
