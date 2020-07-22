#pragma once

#include <opencv2/core/mat.hpp>


struct IFeaturing {

    virtual cv::Ptr<Features> exec(const cv::Mat &) const = 0;

    virtual void init() = 0;

    virtual void free() = 0;
};
