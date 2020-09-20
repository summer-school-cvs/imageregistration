#include "../include/stitching/homography/homography.h"

namespace stitching::homography {

void Homography::exec(std::vector<cv::Point2f> &keyPoints_1,
                      std::vector<cv::Point2f> &keyPoints_2,
                      std::vector<cv::Mat> &    foundHomographies) const {
  std::vector<cv::Point2f> outliers_1;
  std::vector<cv::Point2f> outliers_2;

  outliers_1.reserve(keyPoints_1.size());
  outliers_2.reserve(keyPoints_2.size());

  std::vector<uchar> mask;
  cv::Mat            fHomography;
  unsigned int       outliers_count = 0;

  do {
    fHomography = findHomography(keyPoints_1, keyPoints_2, mask, cv::RANSAC, ransacReprojThreshold);
    foundHomographies.emplace_back(fHomography);

    for (unsigned int i = 0; i < mask.size(); ++i)
      if (!mask[i]) {
        ++outliers_count;
        outliers_1.push_back(keyPoints_1[i]);
        outliers_2.push_back(keyPoints_2[i]);
      }

    swap(outliers_1, keyPoints_1);
    swap(outliers_2, keyPoints_2);

  } while (outliers_count < threshold);
}

void Homography::setThreshold(const unsigned int &_threshold) {
  Homography::threshold = _threshold;
}

void Homography::setRansacReprojThreshold(const double &_ransacReprojThreshold) {
  Homography::ransacReprojThreshold = _ransacReprojThreshold;
}

void Homography::init() {}

void Homography::free() {}

}  // namespace stitching::homography
