#include <gtest/gtest.h>

#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

#include "../../lib/src/imgreg/matching/knn/knn_matching.h"

TEST(KnnMatching, Matches) {
  auto img  = cv::imread(cv::samples::findFile("../../test/pics/img2_1.jpg"));
  auto img2 = cv::imread(cv::samples::findFile("../../test/pics/img2_2.jpg"));

  auto detector = cv::ORB::create();

  std::vector<cv::KeyPoint> img_keyPoints;
  std::vector<cv::KeyPoint> img2_keyPoints;

  cv::Mat descriptors;
  cv::Mat descriptors2;

  detector->detectAndCompute(img, cv::noArray(), img_keyPoints, descriptors);
  detector->detectAndCompute(img2, cv::noArray(), img2_keyPoints, descriptors2);

  auto firstFeatures  = cv::makePtr<Features>(img_keyPoints, descriptors);
  auto secondFeatures = cv::makePtr<Features>(img2_keyPoints, descriptors2);

  auto matching = cv::makePtr<KnnMatching>();

  matching->setMatcherType(cv::DescriptorMatcher::BRUTEFORCE);
  matching->setRatio(0.7);

  matching->init();

  auto k       = 4;
  auto matches = matching->getMatches(firstFeatures, secondFeatures, k);

  cv::Mat img_matches;
  cv::drawMatches(img, firstFeatures->keyPoints, img2, secondFeatures->keyPoints, matches,
                  img_matches);

  cv::imshow("Good matches", img_matches);
  cv::waitKey();

  ASSERT_GT(matches.size(), 0);
};
