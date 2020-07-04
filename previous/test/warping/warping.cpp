#include "../../lib/src/imgreg/warping/warping.h"

#include <gtest/gtest.h>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

#include "../../lib/src/imgreg/warping/perspective/perspective_warping.h"

TEST(Warping, Warps) {
  auto img  = cv::imread(cv::samples::findFile("../../test/pics/img2_1.jpg"));
  auto img2 = cv::imread(cv::samples::findFile("../../test/pics/img2_2.jpg"));

  auto nFeatures = 10;

  auto detector = cv::ORB::create(nFeatures, 1.5f, 8, 25, 0, 4, cv::ORB::HARRIS_SCORE, 31, 20);

  std::vector<cv::KeyPoint> keyPoints_1, keyPoints_2;
  cv::Mat                   descriptors_1, descriptors_2;

  detector->detectAndCompute(img, cv::noArray(), keyPoints_1, descriptors_1);
  detector->detectAndCompute(img2, cv::noArray(), keyPoints_2, descriptors_2);

  std::vector<cv::Point2f> convertedPoints_1;
  std::vector<cv::Point2f> convertedPoints_2;

  cv::KeyPoint::convert(keyPoints_1, convertedPoints_1);
  cv::KeyPoint::convert(keyPoints_2, convertedPoints_2);

  auto homography =
      cv::findHomography(convertedPoints_1, convertedPoints_2, cv::noArray(), cv::RANSAC, 5);

  auto warping = cv::makePtr<PerspectiveWarping>();

  warping->setInterpAlgo(cv::InterpolationFlags::INTER_LINEAR);
  warping->setBorderType(cv::BorderTypes::BORDER_DEFAULT);
  warping->setBorderValue(0);

  auto warp = warping->getWarping(img, img2, homography);

  cv::imshow("Window", warp);

  cv::waitKey(0);

  ASSERT_GT(warp.rows, 0);
}
