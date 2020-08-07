#pragma once

#include <gtest/gtest.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/cvstd.hpp>

#include <../include/stitching/matching/knn_matching.h>

namespace {

	TEST(Matching_Test, output_Matching_Test) {
  
	  cv::Ptr<core::IFeatures> features1;
	  cv::Ptr<core::IFeatures> features2;

	  auto matching = cv::makePtr<stitching::matching::KnnMatching>();

	  EXPECT_THROW(matching->exec(features1, features2, 0), std::invalid_argument);
	}
} 