#pragma once

#include <stitching/core/iwarping.h>

#include <opencv2/imgproc.hpp>

namespace stitching::warping {

class Warping : public core::IWarping {
 public:
  ~Warping() = default;

  void init() override;
  void free() override;

  cv::Mat exec(const cv::Mat &img1, const cv::Mat &img2, const cv::Mat &homography) const override;

  void setInterpAlgo(cv::InterpolationFlags interpAlgo);
  void setBorderType(cv::BorderTypes borderType);
  void setBorderValue(cv::Scalar borderValue);

 private:
  cv::InterpolationFlags interpAlgo_ = cv::InterpolationFlags::INTER_LINEAR;
  cv::BorderTypes        borderType_ = cv::BorderTypes::BORDER_CONSTANT;
  cv::Scalar             borderValue_;
};

}  // namespace stitching::warping
