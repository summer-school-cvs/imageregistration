#pragma once

#include <stitching/core/features.h>

#include <boost/property_tree/ptree.hpp>
#include <memory>
#include <opencv2/core/mat.hpp>

namespace stitching::core {

class IFeaturing {
 public:
  virtual ~IFeaturing() = default;

  virtual void configure(const boost::property_tree::ptree &) {}

  virtual void init() = 0;
  virtual void free() = 0;

  virtual FeaturesUPtr exec(const cv::Mat &) const = 0;
};

using IFeaturingPtr = std::shared_ptr<IFeaturing>;

}  // namespace stitching::core
