#pragma once

#include <stitching/core/imatching.h>

#include <opencv2/core/types.hpp>
#include <opencv2/features2d.hpp>
#include <vector>

namespace stitching::matching {

class KnnMatching : public core::IMatcher {
 public:
  void init() override;

  std::vector<cv::DMatch> exec(const core::FeaturesPtr&, const core::FeaturesPtr&) const override;

  void free() override;

  void setMatcherType(cv::DescriptorMatcher::MatcherType matcherType);

  void setRatio(const float& ratio);
  void setCountBestMatches(int);

 private:
  cv::Ptr<cv::DescriptorMatcher>     matcher;
  cv::DescriptorMatcher::MatcherType matcherType = cv::DescriptorMatcher::MatcherType::BRUTEFORCE;
  float                              ratio       = 0.7f;
  int                                k           = 2;
};

}  // namespace stitching::matching
