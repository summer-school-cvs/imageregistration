#include "../include/stitching/stitcher/simplestitcher.h"

#include <stitching/core/factory.h>
#include <stitching/core/logging.h>
#include <stitching/stitcher/typedefinitions.h>

namespace bpt = boost::property_tree;
using namespace stitching::core;

template <typename I>
auto createObj(std::string name, const boost::property_tree::ptree& config) {
  auto& type_conf = config.get_child(name);
  auto  type_name = type_conf.get<std::string>("type", "default");
  auto  obj       = Factory::create<I, const bpt::ptree&>(type_name, config);
  obj->configure(type_conf);

  return obj;
}

REGISTER_TYPE(IStitcher,
              SimpleStitcher,
              ([](const std::string&,
                  const boost::property_tree::ptree& config) -> stitching::core::IStitcherPtr {
                auto featuring  = createObj<IFeaturing>("Featuring", config);
                auto matching   = createObj<IMatcher>("Matching", config);
                auto homography = createObj<IHomography>("Homography", config);
                auto warping    = createObj<IWarping>("Warping", config);

                auto stitcher = std::make_shared<stitching::stitcher::SimpleStitcher>();
                stitcher->setFeaturing(featuring);
                stitcher->setMatching(matching);
                stitcher->setHomography(homography);
                stitcher->setWarping(warping);

                return stitcher;
              }));

static auto logger = stitching::core::getLogger("stitching.simplestitcher");

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

void SimpleStitcher::init() {
  SPDLOG_LOGGER_DEBUG(logger, "Initing...");
  SPDLOG_LOGGER_DEBUG(logger, "Inited.");
}
cv::Mat SimpleStitcher::exec(std::list<cv::Mat> images) {
  SPDLOG_LOGGER_DEBUG(logger, "Exec...");

  std::list<FeaturesPtr> features;
  for (auto i : images)
    features.push_back(m->feature_finder->exec(i));

  std::list<std::vector<cv::DMatch>> matches;
  for (auto first = features.begin(); first != features.end(); ++first) {
    for (auto second = std::next(first); second != features.end(); ++second)
      matches.push_back(m->matcher->exec(*first, *second));
  }

  return {};
}

void SimpleStitcher::free() {
  SPDLOG_LOGGER_DEBUG(logger, "Get free...");
  SPDLOG_LOGGER_DEBUG(logger, "Free.");
}

}  // namespace stitching::stitcher
