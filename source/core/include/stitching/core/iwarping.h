#pragma once

#include <boost/property_tree/ptree.hpp>
#include <memory>
#include <opencv2/core/mat.hpp>

namespace stitching::core {

class IWarping {
 public:
  virtual ~IWarping() = default;

  virtual void configure(const boost::property_tree::ptree &) {}

  virtual void init() = 0;
  virtual void free() = 0;

  virtual cv::Mat exec(const cv::Mat &img1,
                       const cv::Mat &img2,
                       const cv::Mat &homography) const = 0;
};

using IWarpingPtr = std::shared_ptr<IWarping>;

}  // namespace stitching::core
