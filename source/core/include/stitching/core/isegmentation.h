#pragma once


#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>
#include <stitching/core/hypothesis.h>
#include <utility>

namespace stitching::core {

class ISegmentation {
 public:
  virtual ~ISegmentation() = default;

  

  virtual void init()                             = 0;

  struct ReturnResult
  {
    std::vector<std::pair<cv::Mat, int>> masks;
    std::vector<HypothesisPtr> const myHypoteses;
    std::vector<std::pair<int, int>> const hypotesMatch;
  };

  virtual ReturnResult & exec(std::vector<std::pair<cv::Mat, int>> const &,
                    std::vector<HypothesisPtr> const &,
                    std::vector<std::pair<int, int>> const &) const = 0;
  
  virtual void free()                             = 0;
};

using ISegmentationPtr = std::shared_ptr<ISegmentation>;

}  // namespace stitching::core
