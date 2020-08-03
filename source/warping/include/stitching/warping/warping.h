#pragma once

#include <opencv2/imgproc.hpp>

#include <stitching/core/iwarping.h>

namespace stitching::warping {

class Warping : IWarping {
 public:
 
  Warping() = default;

  ~Warping() = default;
  
  void init() override;
  void free() override;
  

  void setInterpAlgo(cv::InterpolationFlags interpAlgo);

  void setBorderType(cv::BorderTypes borderType);

  void setBorderValue(cv::Scalar borderValue);

  cv::Mat exec(const cv::Mat &img1,
               const cv::Mat &img2,
               const cv::Mat &homography) const override;

 private:
  cv::InterpolationFlags interpAlgo_;
  cv::BorderTypes        borderType_;
  cv::Scalar             borderValue_;
};

}