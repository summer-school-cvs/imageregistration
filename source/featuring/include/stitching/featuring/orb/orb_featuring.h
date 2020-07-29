#pragma once

#include <opencv2/features2d.hpp>

#include "ifeaturing.h"


struct OrbFeaturing : IFeaturing {

  OrbFeaturing() = default;

  ~OrbFeaturing() = default;



  void init() override;

  cv::Ptr<IFeatures> exec(const cv::Mat &) const override;

  void free() override;



  void setNFeatures(const int &n_features);

  void setScaleFactor(const double &scale_factor);

  void setNLevels(const int &n_levels);

  void setEdgeThreshold(const int &edge_threshold);

  void setFirstLevel(const int &first_level);

  void setWTA_K(const int &wta_k);

  void setScoreType(const cv::ORB::ScoreType &score_type);

  void setPatchSize(const int &patch_size);

  void setFastThreshold(const int &fast_threshold);



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
