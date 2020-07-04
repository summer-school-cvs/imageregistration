#include "../../lib/src/imgreg/homography/homography.h"

#include <gtest/gtest.h>

#include <opencv2/core/types.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgcodecs.hpp>

namespace {

TEST(homographyTest, outputsSomeHomographies) {
  auto img1 = cv::imread(cv::samples::findFile("../../test/pics/img1_1.png"));
  auto img2 = cv::imread(cv::samples::findFile("../../test/pics/img1_2.png"));

  auto nFeatures = 30;

  auto detector = cv::ORB::create(nFeatures);

  std::vector<cv::KeyPoint> keyPoints_1, keyPoints_2;
  cv::Mat                   descriptors_1, descriptors_2;

  detector->detectAndCompute(img1, cv::noArray(), keyPoints_1, descriptors_1);
  detector->detectAndCompute(img2, cv::noArray(), keyPoints_2, descriptors_2);

  std::vector<cv::Point2f> convertedPoints_1;
  std::vector<cv::Point2f> convertedPoints_2;

  cv::KeyPoint::convert(keyPoints_1, convertedPoints_1);
  cv::KeyPoint::convert(keyPoints_2, convertedPoints_2);

  auto homography = cv::makePtr<Homography>();

  homography->setThreshold(24);
  homography->setRansacReprojThreshold(5);

  auto homographies = homography->getHomographies(convertedPoints_1, convertedPoints_2);

  std::cout << homographies.size() << std::endl;

  ASSERT_GT(homographies.size(), 0);
}
}  // namespace
