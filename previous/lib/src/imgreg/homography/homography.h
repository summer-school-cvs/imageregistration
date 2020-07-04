#pragma once

#include <opencv2/opencv.hpp>

class Homography {
 public:
  Homography() = default;

  ~Homography() = default;

  std::vector<cv::Mat> getHomographies(std::vector<cv::Point2f> &keyPoints_1,
                                       std::vector<cv::Point2f> &keyPoints_2) const;

  void setThreshold(size_t threshold);

  void setRansacReprojThreshold(double ransacReprojThreshold);

 private:
  double ransacReprojThreshold;
  size_t threshold;
};
