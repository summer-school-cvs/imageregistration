cmake_minimum_required(VERSION 3.16)

project(libstests)

find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
        PRIVATE
            factory_test.cpp
        )

target_link_libraries(${PROJECT_NAME}
            featuring
            Matching
            Homography
            Warping
            gtest_main
        )

add_test(NAME featuring_test COMMAND ${PROJECT_NAME})

