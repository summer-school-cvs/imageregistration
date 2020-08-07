#include <orb/orb_featuring.h>
#include <surf/surf_featuring.h>

#include <gtest/gtest.h>
#include <gtest/internal/gtest-type-util.h>

#include <filesystem>

#include <opencv2/imgcodecs.hpp>


namespace {

    template <class T>
    class FeaturingTest : public testing::Test {
    protected:
        FeaturingTest(): featuring(dynamic_cast<T* const>(new T())) {};

        ~FeaturingTest() override {featuring->free();};

        T* const featuring;
    };


    using Implementations = testing::Types<OrbFeaturing, SurfFeaturing>;

    TYPED_TEST_SUITE(FeaturingTest, Implementations);

    TYPED_TEST(FeaturingTest, NoFeatures) {

        this->featuring->init();
        auto empty_image = cv::imread(std::string());

        EXPECT_THROW(this->featuring->exec(empty_image), std::invalid_argument);
    }


    TYPED_TEST(FeaturingTest, WithFeatures) {

        this->featuring->init();
        auto data_path = std::filesystem::current_path() ;
        auto image  = cv::imread(data_path / "pics/img2_1.jpg");

        EXPECT_NO_THROW(this->featuring->exec(image));
    }

}  // namespace




