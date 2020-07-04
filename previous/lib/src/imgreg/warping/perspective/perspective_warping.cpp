#include "perspective_warping.h"

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <utility>

cv::Mat PerspectiveWarping::getWarping(const cv::Mat &img1,
                                       const cv::Mat &img2,
                                       const cv::Mat &homography) const {
  cv::Mat output;

  cv::warpPerspective(img1, output, homography, img2.size(), interpAlgo_, borderType_,
                      borderValue_);

  return output;
}

void PerspectiveWarping::setInterpAlgo(cv::InterpolationFlags interpAlgo) {
  PerspectiveWarping::interpAlgo_ = interpAlgo;
}

void PerspectiveWarping::setBorderType(cv::BorderTypes borderType) { borderType_ = borderType; }

void PerspectiveWarping::setBorderValue(cv::Scalar borderValue) {
  borderValue_ = std::move(borderValue);
}
