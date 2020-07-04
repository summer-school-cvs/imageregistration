#include "pipeline.h"

#include "../featuring/featuring.h"
#include "../featuring/surf/surf_featuring.h"
#include "../homography/homography.h"
#include "../matching/knn/knn_matching.h"
#include "../warping/perspective/perspective_warping.h"
#include "../warping/warping.h"

using cv::Mat;
using std::vector;

vector<Mat> Pipeline::runPipeline(const Mat& img, const Mat& img2) const {
  auto featuring = cv::makePtr<SurfFeaturing>();

  featuring->init();

  auto features1 = featuring->getFeatures(img);
  auto features2 = featuring->getFeatures(img2);

  featuring->free();

  auto matching = cv::makePtr<KnnMatching>();

  matching->setMatcherType(cv::DescriptorMatcher::BRUTEFORCE);
  matching->setRatio(0.7);

  matching->init();

  auto matches = matching->getMatches(features1, features2, 5);

  matching->free();

  vector<cv::Point2f> convertedKeyPoints_1;
  vector<cv::Point2f> convertedKeyPoints_2;

  cv::KeyPoint::convert(features1->keyPoints, convertedKeyPoints_1);
  cv::KeyPoint::convert(features2->keyPoints, convertedKeyPoints_2);

  vector<cv::Point2f> points_1;
  vector<cv::Point2f> points_2;

  for (auto e : matches) {
    auto idx1 = e.queryIdx;
    auto idx2 = e.trainIdx;
    points_1.push_back(convertedKeyPoints_1[idx1]);
    points_2.push_back(convertedKeyPoints_2[idx2]);
  }

  auto homography = cv::makePtr<Homography>();

  homography->setThreshold(24);
  homography->setRansacReprojThreshold(3);

  auto homographies = homography->getHomographies(points_1, points_2);

  auto warping = cv::makePtr<PerspectiveWarping>();

  warping->setInterpAlgo(cv::InterpolationFlags::INTER_LINEAR);
  warping->setBorderType(cv::BorderTypes::BORDER_CONSTANT);
  warping->setBorderValue(cv::Scalar());

  vector<Mat> warpings;

  for (const auto& element : homographies) {
    auto warp = warping->getWarping(img, img2, element);

    warpings.push_back(warp);
  }

  return warpings;
}
