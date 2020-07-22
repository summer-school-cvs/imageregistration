#pragma once

#include <opencv2/features2d.hpp>

#include "features/features.h"
#include "ifeaturing.h"


struct OrbFeaturing : IFeaturing {

  OrbFeaturing() = default;

  ~OrbFeaturing() = default;



  void init() override;

  cv::Ptr<Features> exec(const cv::Mat &) const override;

  void free() override;



  void setNFeatures(int n_features);

  void setScaleFactor(float scale_factor);

  void setNLevels(int n_levels);

  void setEdgeThreshold(int edge_threshold);

  void setFirstLevel(int first_level);

  void setWTA_K(int wta_k);

  void setScoreType(cv::ORB::ScoreType score_type);

  void setPatchSize(int patch_size);

  void setFastThreshold(int fast_threshold);



 private:
  cv::Ptr<cv::ORB> detector;

  int                nfeatures{500};
  float              scaleFactor{1.2f};
  int                nlevels{8};
  int                edgeThreshold{31};
  int                firstLevel{0};
  int                WTA_K{2};
  cv::ORB::ScoreType scoreType{cv::ORB::HARRIS_SCORE};
  int                patchSize{31};
  int                fastThreshold{20};
};
