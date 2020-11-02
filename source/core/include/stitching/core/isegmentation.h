#pragma once


#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>
#include <stitching/core/hypothesis.h>

namespace stitching::core {

class ISegmentation {
 public:
  virtual ~ISegmentation() = default;

  

  virtual void init()                             = 0;
  
  virtual void exec(cv::Mat &,
                    std::vector<HypothesisPtr> &,
                    std::vector<cv::Mat> &) const = 0;
  
  virtual void free()                             = 0;
};

using ISegmentationPtr = std::shared_ptr<ISegmentation>;

}  // namespace stitching::core
