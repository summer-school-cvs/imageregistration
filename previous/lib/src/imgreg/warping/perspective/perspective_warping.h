#pragma once

#include <opencv2/imgproc.hpp>

#include "../warping.h"

class PerspectiveWarping : Warping {
 public:
  PerspectiveWarping() = default;

  ~PerspectiveWarping() = default;

  void setInterpAlgo(cv::InterpolationFlags interpAlgo);

  void setBorderType(cv::BorderTypes borderType);

  void setBorderValue(cv::Scalar borderValue);

  cv::Mat getWarping(const cv::Mat &img1,
                     const cv::Mat &img2,
                     const cv::Mat &homography) const override;


  void init() override
  {
      std::cout << "initialize PerspectiveWarping" << std::endl;
  }

  void free() override 
  { 
      std::cout << "smth_free" << std::endl;
  }

 private:
  cv::InterpolationFlags interpAlgo_;
  cv::BorderTypes        borderType_;
  cv::Scalar             borderValue_;
};
