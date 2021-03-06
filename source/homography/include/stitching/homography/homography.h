#pragma once

#include <stitching/core/ihomography.h>

namespace stitching::homography {

class Homography : public core::IHomography {
 public:
  Homography(){};

  void init() override;
  void free() override;

  std::vector<core::HypothesisUPtr> exec(std::vector<cv::Point2f>,
                                         std::vector<cv::Point2f>) const override;

  void exec(std::vector<cv::Point2f> &keyPoints_1,
            std::vector<cv::Point2f> &keyPoints_2,
            std::vector<cv::Mat> &    foundHomographies) const override;

  void setThreshold(const unsigned int &threshold);
  void setRansacReprojThreshold(const double &ransacReprojThreshold);

 private:
  double       ransacReprojThreshold = 3;
  unsigned int threshold             = 0;
};

}  // namespace stitching::homography
