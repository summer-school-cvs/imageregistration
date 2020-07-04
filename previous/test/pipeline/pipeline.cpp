#include "../../lib/src/imgreg/pipeline/pipeline.h"

#include <gtest/gtest.h>

#include <filesystem>
#include <opencv2/core/cvstd_wrapper.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

TEST(Pipeline, OutputsSomething) {
  auto data_path = std::filesystem::path(TEST_DATA_DIR);

  auto img  = cv::imread(data_path / "img2_1.jpg");
  auto img2 = cv::imread(data_path / "img2_2.jpg");

  auto pipeline = cv::makePtr<Pipeline>();

  auto imageCompositions = pipeline->runPipeline(img, img2);

  ASSERT_GT(imageCompositions.size(), 0);

  for (auto i = 0ul; i < imageCompositions.size(); ++i)
    cv::imwrite("pipeline_res_" + std::to_string(i) + ".png", imageCompositions[i]);
}
