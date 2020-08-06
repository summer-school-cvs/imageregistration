#include <../include/stitching/homography/homography.h>

#include <gtest/gtest.h>

#include <opencv2/core/types.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgcodecs.hpp>

namespace {
	
TEST(Homography_Test, output_Homographies_Test) {

  std::vector<cv::Point2f> Points_1;
  std::vector<cv::Point2f> Points_2;

  auto homography = cv::makePtr<stitching::homography::Homography>();

  std::vector<cv::Mat> homographies;
  
  EXPECT_THROW(homography->exec(Points_1, Points_2, homographies), std::invalid_argument);
  
}
}  // namespace
