#pragma once

#include <opencv2/core/types.hpp>
#include "opencv2/features2d.hpp"

#include <vector>

#include <stitching/core/imatching.h>

namespace stitching::matching {

class KnnMatching : public core::IMatcher {
 public:
  void init() override;

  std::vector<cv::DMatch> exec(cv::Ptr<core::IFeatures>, cv::Ptr<core::IFeatures>, int) const override;

  void free() override;

  void setMatcherType(cv::DescriptorMatcher::MatcherType matcherType);

  void setRatio(const float & ratio);

 private:
  cv::Ptr<cv::DescriptorMatcher>     matcher;
  cv::DescriptorMatcher::MatcherType matcherType;
  float                              ratio;
};

}  // namespace stitching::matching



