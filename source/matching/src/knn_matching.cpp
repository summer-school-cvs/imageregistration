#include "../include/stitching/matching/knn_matching.h"

#include <stitching/core/factory.h>

#include <iostream>
#include <vector>

using stitching::core::IMatcher;
using stitching::core::IMatcherPtr;
REGISTER_TYPE(IMatcher,
              KnnMatcher,
              [](const std::string&, const boost::property_tree::ptree&) -> IMatcherPtr {
                return std::make_shared<stitching::matching::KnnMatching>();
              });

namespace stitching::matching {

void KnnMatching::init() { matcher = cv::DescriptorMatcher::create(matcherType); }

std::vector<cv::DMatch> KnnMatching::exec(const core::FeaturesPtr& features1,
                                          const core::FeaturesPtr& features2) const {
  if (features1->keyPoints.empty() || features2->keyPoints.empty()) {
    throw std::invalid_argument(std::string("Empty features!"));
  }

  std::vector<std::vector<cv::DMatch>> knnMatches;

  matcher->knnMatch(features1->descriptors, features2->descriptors, knnMatches, k);

  if (k == 1)
    return std::move(knnMatches.front());

  std::vector<cv::DMatch> matches;

  for (auto& knnMatch : knnMatches) {
    for (auto i = 1ul; i < knnMatch.size(); ++i) {
      if (knnMatch[0].distance < ratio * knnMatch[i].distance)
        matches.push_back(knnMatch[0]);
    }
  }

  return matches;
}

void KnnMatching::free() { matcher.release(); }

void KnnMatching::setMatcherType(cv::DescriptorMatcher::MatcherType matcherType_) {
  KnnMatching::matcherType = matcherType_;
}

void KnnMatching::setRatio(const float& ratio_) { KnnMatching::ratio = ratio_; }

void KnnMatching::setCountBestMatches(int k_) { k = k_; }

}  // namespace stitching::matching
