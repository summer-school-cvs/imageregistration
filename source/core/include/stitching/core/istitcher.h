#pragma once

#include <opencv2/core/mat.hpp>

#include<list>

namespace stitching::core {

class IStitcher {
 public:
  virtual ~IStitcher() = default;

  virtual void init() = 0;
  virtual cv::Mat exec(std::list<cv::Mat>) = 0;
  virtual void free() = 0;
};

}
