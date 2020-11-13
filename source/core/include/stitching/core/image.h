#pragma once

#include <memory>
#include <opencv2/core/mat.hpp>

namespace stitching::core {

struct Image
{
    cv::Mat matrix;
    int index;
};

using ImagePtr  = std::shared_ptr<Image>;
using ImageUPtr = std::unique_ptr<Image>;

}  // namespace stitching::core
