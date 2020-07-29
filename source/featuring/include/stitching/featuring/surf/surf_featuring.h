#pragma once

#include <opencv2/xfeatures2d/nonfree.hpp>

#include "ifeaturing.h"


struct SurfFeaturing : IFeaturing {

  SurfFeaturing() = default;

  ~SurfFeaturing() = default;

  void init() override;

  cv::Ptr<IFeatures> exec(const cv::Mat&) const override;

  void free() override;

  void setHessianThreshold(const double&);
  void setNOctaves(const int&);
  void setNOctaveLayers(const int&);
  void setExtended(const bool&);
  void setUpright(const bool&);

 private:
  cv::Ptr<cv::xfeatures2d::SURF> detector;

  double hessianThreshold = 100;
  int    nOctaves         =   4;
  int    nOctaveLayers    =   3;
  bool   extended         = false;
  bool   upright          = false;
};
