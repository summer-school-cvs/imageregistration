#pragma once

#include <opencv2/core/mat.hpp>

#include<vector>

namespace stitching::core {

class IPipeline {
 public:
  virtual ~IPipeline() = default;

  virtual void init()                             = 0;
  
  virtual std::vector<cv::Mat> runPipeline(const cv::Mat &img, const cv::Mat &img2) const;
					
  virtual void free()                             = 0;
};

} 