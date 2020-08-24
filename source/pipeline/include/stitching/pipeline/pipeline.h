#pragma once

#include <stitching/core/ipipeline.h>


#include <stitching/core/ifeaturing.h>
#include <stitching/core/ihomography.h>
#include <stitching/core/imatching.h>
#include <stitching/core/iwarping.h>

namespace stitching::pipeline {

class Pipeline : public core::IPipeline {
 public:
  Pipeline(){};

  void init() override;
  void free() override;

  std::vector<cv::Mat> runPipeline(const cv::Mat &img, const cv::Mat &img2) const override;
};

}  
