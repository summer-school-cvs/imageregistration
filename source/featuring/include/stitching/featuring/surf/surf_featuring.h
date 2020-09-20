#pragma once

#include <stitching/core/ifeaturing.h>

#include <opencv2/xfeatures2d/nonfree.hpp>

namespace stitching::featuring {

class SurfFeaturing : public core::IFeaturing {
 public:
  SurfFeaturing() = default;

  ~SurfFeaturing() = default;

  void init() override;

  core::FeaturesUPtr exec(const cv::Mat&) const override;

  void free() override;

  void setHessianThreshold(double);
  void setNOctaves(int);
  void setNOctaveLayers(int);
  void setExtended(bool);
  void setUpright(bool);

 private:
  cv::Ptr<cv::xfeatures2d::SURF> detector;

  double hessianThreshold = 100;
  int    nOctaves         = 4;
  int    nOctaveLayers    = 3;
  bool   extended         = false;
  bool   upright          = false;
};

}  // namespace stitching::featuring
