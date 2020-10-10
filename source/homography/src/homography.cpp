#include "../include/stitching/homography/homography.h"

#include <stitching/core/factory.h>
#include <stitching/core/logging.h>

using stitching::core::IHomography;
using stitching::core::IHomographyPtr;
REGISTER_TYPE(IHomography, Homography, [](const std::string &) -> IHomographyPtr {
  return std::make_shared<stitching::homography::Homography>();
});

auto logger = stitching::core::getLogger("stitching.homography");

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

std::list<core::HypothesisUPtr> Homography::exec(
    const std::vector<cv::Point2f> &keyPoints_1,
    const std::vector<cv::Point2f> &keyPoints_2) const {
  SPDLOG_LOGGER_DEBUG(logger, "Begin finding hypotheses...");
  std::list<core::HypothesisUPtr> result;

  std::vector<cv::Point2f> outliers_1 = keyPoints_1;
  std::vector<cv::Point2f> outliers_2 = keyPoints_2;

  outliers_1.reserve(keyPoints_1.size());
  outliers_2.reserve(keyPoints_2.size());

  std::vector<uchar> mask;
  cv::Mat            fHomography;
  unsigned int       outliers_count = 0;

  do {
    auto hypothesis = std::make_unique<core::Hypothesis>();

    hypothesis->homography =
        findHomography(outliers_1, outliers_2, mask, cv::RANSAC, ransacReprojThreshold);

    std::vector<cv::Point2f> tmp1;
    std::vector<cv::Point2f> tmp2;
    for (unsigned int i = 0; i < mask.size(); ++i) {
      if (mask[i]) {
        hypothesis->first.push_back(keyPoints_1[i]);
        hypothesis->second.push_back(keyPoints_2[i]);
      } else {
        ++outliers_count;
        tmp1.push_back(keyPoints_1[i]);
        tmp2.push_back(keyPoints_2[i]);
      }
    }

    SPDLOG_LOGGER_DEBUG(logger, "Hypothesis {}. Inliers {}. Outliers {}. ", result.size(),
                        hypothesis->first.size(), tmp1.size());

    outliers_1 = tmp1;
    outliers_2 = tmp2;

    result.push_back(std::move(hypothesis));

  } while (outliers_count < threshold);

  SPDLOG_LOGGER_DEBUG(logger, "Finded {} hypotheses.", result.size());

  return result;
}

}  // namespace stitching::homography
