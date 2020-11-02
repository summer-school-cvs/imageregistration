#include "../include/stitching/segmentation/segmentation.h"

using stitching::core::ISegmentation;
using stitching::core::ISegmentationPtr;
REGISTER_TYPE(ISegmentation,
              Segmentation,
              [](const std::string&, const boost::property_tree::ptree&) -> ISegmentationPtr {
                return std::make_shared<stitching::segmentation::Segmentation>();
              });


namespace stitching::segmentation {



}  // namespace stitching::segmentation
