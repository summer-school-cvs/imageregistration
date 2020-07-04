#include "surf_featuring.h"

#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

Ptr<Features> SurfFeaturing::getFeatures(const cv::Mat& img) const {
  if (img.empty()) {
    cout << "Could not open or find the image!\n" << endl;
    return {};
  }

  vector<KeyPoint> keyPoints;
  Mat              descriptors;

  detector->detectAndCompute(img, noArray(), keyPoints, descriptors);

  return cv::makePtr<Features>(keyPoints, descriptors);
}

void SurfFeaturing::init() {
  detector = SURF::create(hessianThreshold, nOctaves, nOctaveLayers, extended, upright);
}

void SurfFeaturing::free() { detector = nullptr; }

void SurfFeaturing::setHessianThreshold(double val) { hessianThreshold = val; }
void SurfFeaturing::setNOctaves(int val) { nOctaves = val; }
void SurfFeaturing::setNOctaveLayers(int val) { nOctaveLayers = val; }
void SurfFeaturing::setExtended(bool val) { extended = val; }
void SurfFeaturing::setUpright(bool val) { upright = val; }
