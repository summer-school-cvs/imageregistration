#include <iostream>

#include "surf_featuring.h"


using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;


Ptr<IFeatures> SurfFeaturing::exec(const Mat& img) const {

    if (img.empty()) {
        cout << "Could not open or find the image!\n" << endl;
        return {};
    }

  vector<KeyPoint> keyPoints;
  Mat              descriptors;

  detector->detectAndCompute(img, noArray(), keyPoints, descriptors);

  return makePtr<IFeatures>(keyPoints, descriptors);
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

