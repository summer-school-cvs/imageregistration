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
            matching
            homography
            warping
            gtest_main
        )

add_executable(${PROJECT_NAME}2)
target_sources(${PROJECT_NAME}2
        PRIVATE
            factory_test2.cpp
        )

target_link_libraries(${PROJECT_NAME}2
            featuring
            matching
            homography
            warping
            gtest_main
        )

add_executable(stitching_test)
target_sources(stitching_test
        PRIVATE
            stitching_test.cpp
        )

target_link_libraries(stitching_test
            featuring
            matching
            homography
            warping
            simplestitcher
            gtest_main
        )

add_test(NAME factory COMMAND ${PROJECT_NAME})
add_test(NAME factory2 COMMAND ${PROJECT_NAME}2)
add_test(NAME stitching COMMAND stitching_test)
