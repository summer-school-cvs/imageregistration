#pragma once

#include <boost/property_tree/ptree.hpp>
#include <memory>
#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

namespace stitching::core {

class IHomography {
 public:
  virtual ~IHomography() = default;

  virtual void configure(const boost::property_tree::ptree &) {}

  virtual void init()                             = 0;
  virtual void exec(std::vector<cv::Point2f> &,
                    std::vector<cv::Point2f> &,
                    std::vector<cv::Mat> &) const = 0;
  virtual void free()                             = 0;
};

using IHomographyPtr = std::shared_ptr<IHomography>;

}  // namespace stitching::core
