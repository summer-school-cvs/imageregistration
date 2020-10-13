#include <gtest/gtest.h>
#include <stitching/matching/knn_matching.h>

#include <opencv2/core/cvstd.hpp>
#include <opencv2/opencv.hpp>

namespace {

TEST(Matching_Test, output_Matching_Test) {
  stitching::core::FeaturesPtr features1 = std::make_shared<stitching::core::Features>();
  stitching::core::FeaturesPtr features2 = std::make_shared<stitching::core::Features>();

  auto matching = cv::makePtr<stitching::matching::KnnMatching>();

  EXPECT_THROW(matching->exec(features1, features2), std::invalid_argument);
}

}  // namespace
