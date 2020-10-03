#pragma once

#include <stitching/core/features.h>

#include <boost/property_tree/ptree.hpp>
#include <memory>
#include <opencv2/core/mat.hpp>
#include <vector>

namespace stitching::core {

class IMatcher {
 public:
  virtual ~IMatcher() = default;

  virtual void configure(const boost::property_tree::ptree &) {}

  virtual std::vector<cv::DMatch> exec(const FeaturesPtr &, const FeaturesPtr &, int) const = 0;

  virtual void init() = 0;
  virtual void free() = 0;
};

using IMatcherPtr = std::shared_ptr<IMatcher>;

}  // namespace stitching::core
