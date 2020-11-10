#pragma once

#include <stitching/core/isegmentation.h>

namespace stitching::segmentation {

class Segmentation : public core::ISegmentation {
 public:
 
 Segmentation(){}

  void init() override {}
  void free() override {}

  ReturnResult & exec(std::vector<std::pair<cv::Mat, int>> const &,
                      std::vector<stitching::core::HypothesisPtr> const &,
                      std::vector<std::pair<int, int>> const &) const override
  {
      auto ans = ReturnResult();
      return ans;
  }
  
};

}  // namespace stitching::segmentation
