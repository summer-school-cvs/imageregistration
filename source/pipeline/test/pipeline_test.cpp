#include <include/stitching/pipeline/pipeline.h>
#include <source/pipeline/test/class_test_pipeline.cpp>

#include <gtest/gtest.h>


#include <filesystem>
#include <opencv2/core/cvstd_wrapper.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

using ::testing::TestWithParam;
using ::testing::Values;

TEST_P(class_test_pipeline, OutputsSomething) {
	
  
 
  auto pipeline = cv::makePtr<Pipeline>();

  auto imageCompositions = pipeline->runPipeline(img1, img2);

  ASSERT_GT(imageCompositions.size(), 0);
  
  EXPECT_TRUE (imageCompositions, img1, img2);

  for (auto i = 0ul; i < imageCompositions.size(); ++i)
    cv::imwrite("pipeline_res_" + std::to_string(i) + ".png", imageCompositions[i]);
}