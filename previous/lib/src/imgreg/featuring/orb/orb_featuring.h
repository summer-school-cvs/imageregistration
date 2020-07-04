#pragma once

#include <opencv2/features2d.hpp>

#include "../../features/features.h"
#include "../featuring.h"

class OrbFeaturing : public Featuring {
 public:
  OrbFeaturing() = default;

  ~OrbFeaturing() = default;

  void init() override;

  cv::Ptr<Features> getFeatures(const cv::Mat &) const override;

  void free() override;

  void setNFeatures(int nFeatures);

  void setScaleFactor(float scaleFactor);

  void setNLevels(int nLevels);

  void setEdgeThreshold(int edgeThreshold);

  void setFirstLevel(int firstLevel);

  void setWtaK(int wtaK);

  void setScoreType(cv::ORB::ScoreType scoreType);

  void setPatchSize(int patchSize);

  void setFastThreshold(int fastThreshold);

 private:
  cv::Ptr<cv::ORB> detector;

  int                nFeatures{500};
  float              scaleFactor{1.2f};
  int                nLevels{8};
  int                edgeThreshold{31};
  int                firstLevel{0};
  int                WTA_K{2};
  cv::ORB::ScoreType scoreType{cv::ORB::HARRIS_SCORE};
  int                patchSize{31};
  int                fastThreshold{20};
};
