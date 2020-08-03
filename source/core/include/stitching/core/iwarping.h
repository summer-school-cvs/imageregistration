#pragma once

#include <opencv2/core/mat.hpp>


namespace stitching::core {
	
class IWarping {
 public:
 
	virtual ~IWarping() = default;
 
	virtual void init() = 0;
	 
	 
	virtual cv::Mat exec( const cv::Mat &img1,
						  const cv::Mat &img2,
						  const cv::Mat &homography) const = 0;
								 
	virtual void free() = 0;						 
};

}
