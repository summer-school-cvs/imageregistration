#include <stitching/core/ifeaturing.h>
#include <stitching/core/ihomography.h>
#include <stitching/core/imatching.h>
#include <stitching/core/istitcher.h>
#include <stitching/core/iwarping.h>

namespace stitching::stitcher {

class SimpleStitcher : public core::IStitcher {
 public:
  SimpleStitcher();

  void setFeaturing(core::IFeaturingPtr);
  void setMatching(core::IMatcherPtr);
  void setHomography(core::IHomographyPtr);
  void setWarping(core::IWarpingPtr);

  void    init() override;
  cv::Mat exec(std::list<cv::Mat>) override;
  void    free() override;

 private:
  class Private;
  std::shared_ptr<Private> m;
};

}  // namespace stitching::stitcher
