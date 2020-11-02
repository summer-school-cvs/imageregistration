#pragma once

#include <stitching/core/isegmentation.h>

namespace stitching::segmentation {

class Segmentation : public core::ISegmentation {
 public:
 
 Segmentation(){};

  void init() override;
  void free() override;
  
  void exec(cv::Mat & ,
                std::vector<HypothesisPtr> &,
                std::vector<cv::Mat> &) const override;
  
};

}  // namespace stitching::segmentation
