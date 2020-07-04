#include "homography.h"

std::vector<cv::Mat> Homography::getHomographies(std::vector<cv::Point2f> &keyPoints_1,
                                                 std::vector<cv::Point2f> &keyPoints_2) const {
  std::vector<cv::Mat>     foundHomographies;
  cv::Mat                  homography;
  size_t                   outliers_count = 0;
  std::vector<cv::Point2f> outliers_1;
  std::vector<cv::Point2f> outliers_2;
  outliers_1.reserve(keyPoints_1.size());
  outliers_2.reserve(keyPoints_2.size());

  std::vector<char> mask;

  do {
    homography = findHomography(keyPoints_1, keyPoints_2, mask, cv::RANSAC, ransacReprojThreshold);
    foundHomographies.emplace_back(homography);

    for (auto i = 0; i < mask.size(); ++i) {
      if (!mask[i]) {
        outliers_count++;
        outliers_1.push_back(keyPoints_1[i]);
        outliers_2.push_back(keyPoints_2[i]);
      }
    }

    swap(outliers_1, keyPoints_1);
    swap(outliers_2, keyPoints_2);

  } while (outliers_count < threshold);

  return foundHomographies;
}

void Homography::setThreshold(size_t threshold_) { Homography::threshold = threshold_; }

void Homography::setRansacReprojThreshold(double ransacReprojThreshold_) {
  Homography::ransacReprojThreshold = ransacReprojThreshold_;
}
