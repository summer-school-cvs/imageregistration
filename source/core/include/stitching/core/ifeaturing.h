#pragma once

#include <opencv2/core/mat.hpp>
#include "ifeatures.h"

struct IFeaturing {

    virtual cv::Ptr<IFeatures> exec(const cv::Mat &) const = 0;

    virtual void init() = 0;

    virtual void free() = 0;
};
