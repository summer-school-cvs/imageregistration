#pragma once

#include <opencv2/core/mat.hpp>

#include <list>
#include <vector>

namespace stitching::core {

class IStitcher {
 public:
  virtual ~IStitcher() = default;

  virtual void init() = 0;
  virtual cv::Mat exec(std::list<cv::Mat>) = 0;
  virtual void free() = 0;
};

class IMatcher {
 public:
  virtual ~IMatcher() = default;

  virtual void init() = 0;
  
  virtual std::vector<cv::DMatch> exec(const cv::Ptr<Features>, const cv::Ptr<Features>, int) const = 0;

  virtual void free() = 0;
};

struct IFeatures {
  Features(std::vector<cv::KeyPoint> keyPoints, cv::Mat descriptors);

  ~Features() = default;

  std::vector<cv::KeyPoint> keyPoints;
  cv::Mat                   descriptors;
};


}
