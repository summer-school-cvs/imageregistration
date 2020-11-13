#pragma once


#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>
#include <stitching/core/hypothesis.h>
#include <stitching/core/segmentationResult.h>
#include <stitching/core/image.h>
#include <utility>

namespace stitching::core {

class ISegmentation {
 public:
  virtual ~ISegmentation() = default;

  

  virtual void init()                             = 0;

  virtual Result & exec(std::vector<Image> const &,
                    std::vector<HypothesisPtr> const &) const = 0;
  
  virtual void free()                             = 0;
};

using ISegmentationPtr = std::shared_ptr<ISegmentation>;

}  // namespace stitching::core
