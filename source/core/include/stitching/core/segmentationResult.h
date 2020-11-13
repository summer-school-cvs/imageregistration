#pragma once

#include <memory>
#include <opencv2/core/mat.hpp>
#include <vector>
#include <stitching/core/hypothesis.h>
#include <stitching/core/image.h>

namespace stitching::core
{

    struct Result
    {
        std::vector<Image> masks;
        std::vector<HypothesisPtr> const myHypoteses;
    };

    using ResultPtr  = std::shared_ptr<Result>;
    using ResultUPtr = std::unique_ptr<Result>;

}  // namespace stitching::core
