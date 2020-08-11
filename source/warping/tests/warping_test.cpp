#pragma once

#include <../include/stitching/warping/warping.h>

#include <gtest/gtest.h>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

namespace {
	
TEST(Warping_Test, output_Warping_Test) {

  std::vector<cv::Point2f> Points_1;
  std::vector<cv::Point2f> Points_2;

  auto warping = cv::makePtr<stitching::warping::Warping>();

  std::vector<cv::Mat> transformation_matrix;
  
  EXPECT_THROW(warping->exec(Points_1, Points_2, transformation_matrix), std::invalid_argument);
  
}
}  