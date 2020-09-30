#include "../include/stitching/warping/warping.h"

#include <stitching/core/factory.h>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <utility>

using stitching::core::IWarping;
using stitching::core::IWarpingPtr;
REGISTER_TYPE(IWarping, Warping, [](const std::string &) -> IWarpingPtr {
  return std::make_shared<stitching::warping::Warping>();
});

namespace stitching::warping {

void Warping::init() {}
void Warping::free() {}

cv::Mat Warping::exec(const cv::Mat &img1, const cv::Mat &img2, const cv::Mat &homography) const {
  if (img1.empty())
    throw std::invalid_argument("Invalid first image.");
  if (img2.empty())
    throw std::invalid_argument("Invalid second image.");
  if (homography.empty())
    throw std::invalid_argument("Invalid homography.");

  cv::Mat output;

  cv::warpPerspective(img1, output, homography, img2.size(), interpAlgo_, borderType_,
                      borderValue_);

  return output;
}

void Warping::setInterpAlgo(cv::InterpolationFlags interpAlgo) {
  Warping::interpAlgo_ = interpAlgo;
}

void Warping::setBorderType(cv::BorderTypes borderType) { borderType_ = borderType; }

void Warping::setBorderValue(cv::Scalar borderValue) { borderValue_ = std::move(borderValue); }

}  // namespace stitching::warping
