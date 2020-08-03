#include "include/stitching/warping/warping.h"

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <utility>

namespace stitching::warping {
	

cv::Mat Warping::exec(const cv::Mat &img1,
                                 const cv::Mat &img2,
                                 const cv::Mat &homography) const {
  cv::Mat output;

  cv::warpPerspective(img1, output, homography, img2.size(), interpAlgo_, borderType_,
                      borderValue_);

  return output;
}

void Warping::setInterpAlgo(cv::InterpolationFlags interpAlgo) {
  Warping::interpAlgo_ = interpAlgo;
}

void Warping::setBorderType(cv::BorderTypes borderType) { borderType_ = borderType; }

void Warping::setBorderValue(cv::Scalar borderValue) {
  borderValue_ = std::move(borderValue);
}

}