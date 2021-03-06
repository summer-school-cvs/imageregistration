#pragma once

#include <boost/property_tree/ptree.hpp>
#include <list>
#include <opencv2/core/mat.hpp>

namespace stitching::core {

class IStitcher {
 public:
  virtual ~IStitcher() = default;

  virtual void configure(const boost::property_tree::ptree &) {}

  virtual void    init()                     = 0;
  virtual cv::Mat exec(std::vector<cv::Mat>) = 0;
  virtual void    free()                     = 0;
};

using IStitcherPtr = std::shared_ptr<IStitcher>;

}  // namespace stitching::core
