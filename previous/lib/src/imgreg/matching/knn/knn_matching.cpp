#include "knn_matching.h"

#include <iostream>
#include <vector>

#include "../../features/features.h"

void KnnMatching::init() { matcher = cv::DescriptorMatcher::create(matcherType); }

std::vector<cv::DMatch> KnnMatching::getMatches(cv::Ptr<Features> features1,
                                                cv::Ptr<Features> features2,
                                                int               k) const {
  std::vector<std::vector<cv::DMatch>> knnMatches;

  matcher->knnMatch(features1->descriptors, features2->descriptors, knnMatches, k);

  std::vector<cv::DMatch> matches{};

  for (auto& knnMatch : knnMatches) {
    if (knnMatch[0].distance < ratio * knnMatch[1].distance) {
      matches.push_back(knnMatch[0]);
    }
  }

  return matches;
}

void KnnMatching::free() { matcher = nullptr; }

void KnnMatching::setMatcherType(cv::DescriptorMatcher::MatcherType matcherType_) {
  KnnMatching::matcherType = matcherType_;
}

void KnnMatching::setRatio(float ratio_) { KnnMatching::ratio = ratio_; }
