#pragma once

#include <stitching/core/isegmentation.h>

namespace stitching::segmentation {

class Segmentation : public core::ISegmentation {
 public:
 
 Segmentation(){}

  void init() override {}
  void free() override {}

  stitching::core::Result & exec(std::vector<stitching::core::Image> const &,
                      std::vector<stitching::core::HypothesisPtr> const &) const override
  {
      auto ans = stitching::core::Result();
      return ans;
  }
  
};

}  // namespace stitching::segmentation
