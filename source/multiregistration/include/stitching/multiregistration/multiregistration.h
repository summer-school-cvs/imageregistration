#pragma once

#include <stitching/core/istitcher.h>

namespace stitching::multiregistration {

class MultiRegistration : public core::IStitcher {
 public:
  MultiRegistration();

  void    init() override;
  cv::Mat exec(std::list<cv::Mat>) override;
  void    free() override;
};

}  // namespace stitching::multiregistration
