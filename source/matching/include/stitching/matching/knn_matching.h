#pragma once

#include <opencv2/core/types.hpp>
#include "opencv2/features2d.hpp"

#include <vector>

#include <.../.../.../.../core/include/stitching/core/istitcher.h>

namespace stitching::matching {

class KnnMatching : public core::IMatcher {
 public:
  void init() override;

  std::vector<cv::DMatch> getMatches(cv::Ptr<core::IFeatures>, cv::Ptr<core::IFeatures>, int) const override;

  void free() override;

  void setMatcherType(cv::DescriptorMatcher::MatcherType matcherType);

  void setRatio(float ratio);

 private:
  cv::Ptr<cv::DescriptorMatcher>     matcher;
  cv::DescriptorMatcher::MatcherType matcherType;
  float                              ratio;
};

}  // namespace stitching::matching



