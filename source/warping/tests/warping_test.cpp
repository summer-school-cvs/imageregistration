#include <gtest/gtest.h>
#include <stitching/warping/warping.h>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

namespace {

TEST(Warping_Test, output_Warping_Test) {
  cv::Mat img0;
  cv::Mat img1;
  cv::Mat transformation_matrix;

  stitching::warping::Warping warping;

  warping.init();
  EXPECT_THROW(warping.exec(img0, img1, transformation_matrix), std::invalid_argument);
  warping.free();
}

}  // namespace
