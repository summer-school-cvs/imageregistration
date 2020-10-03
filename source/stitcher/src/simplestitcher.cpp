#include "../include/stitching/stitcher/simplestitcher.h"

namespace stitching::stitcher {

class SimpleStitcher::Private {
 public:
  core::IFeaturingPtr  feature_finder;
  core::IMatcherPtr    matcher;
  core::IHomographyPtr homo_finder;
  core::IWarpingPtr    warper;
};

}  // namespace stitching::stitcher

namespace stitching::stitcher {

SimpleStitcher::SimpleStitcher()
    : m(std::make_shared<Private>()) {}

void SimpleStitcher::setFeaturing(core::IFeaturingPtr ptr) { m->feature_finder = ptr; }
void SimpleStitcher::setMatching(core::IMatcherPtr ptr) { m->matcher = ptr; }
void SimpleStitcher::setHomography(core::IHomographyPtr ptr) { m->homo_finder = ptr; }
void SimpleStitcher::setWarping(core::IWarpingPtr ptr) { m->warper = ptr; }

void    SimpleStitcher::init() {}
cv::Mat SimpleStitcher::exec(std::list<cv::Mat>) { return {}; }
void    SimpleStitcher::free() {}

}  // namespace stitching::stitcher
