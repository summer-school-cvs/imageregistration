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

  SPDLOG_LOGGER_INFO(logger, "Featuring...");
  std::vector<std::vector<cv::Point2f>> points;
  std::vector<FeaturesPtr>              features;
  std::size_t                           img_counter = 0;
  for (auto i : images) {
    features.push_back(m->feature_finder->exec(i));

    points.emplace_back();
    cv::KeyPoint::convert(features.back()->keyPoints, points.back());

    SPDLOG_LOGGER_DEBUG(logger, "Image {}. Features {}.", img_counter,
                        features.back()->keyPoints.size());

    ++img_counter;
  }

  std::map<std::pair<std::size_t, std::size_t>, std::list<HypothesisUPtr>> hypotheses;
  for (auto first = 0ul; first < features.size(); ++first) {
    for (auto second = first + 1; second < features.size(); ++second) {
      auto matches = m->matcher->exec(features[first], features[second]);

      SPDLOG_LOGGER_DEBUG(logger, "Images {}-{}. Matches {}.", first, second, matches.size());

      std::vector<cv::Point2f> points_1;
      std::vector<cv::Point2f> points_2;

      for (auto e : matches) {
        auto idx1 = e.queryIdx;
        auto idx2 = e.trainIdx;
        points_1.push_back(points[first][idx1]);
        points_2.push_back(points[second][idx2]);
      }

      auto hypothesis = m->homo_finder->exec(points_1, points_2);
      SPDLOG_LOGGER_DEBUG(logger, "Images {}-{}. Hypotheses {}.", first, second, hypothesis.size());
      hypotheses[std::make_pair(first, second)] = std::move(hypothesis);
    }
  }

  return {};
}

void SimpleStitcher::free() {
  SPDLOG_LOGGER_DEBUG(logger, "Get free...");
  SPDLOG_LOGGER_DEBUG(logger, "Free.");
}

}  // namespace stitching::stitcher
