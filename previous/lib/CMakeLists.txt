cmake_minimum_required(VERSION 3.14)

project(imgreg)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
        PUBLIC
        src/imgreg/registration.cpp
        src/imgreg/registration.h
        src/imgreg/homography/homography.cpp
        src/imgreg/homography/homography.h
        src/imgreg/matching/matching.h
        src/imgreg/matching/knn/knn_matching.cpp
        src/imgreg/matching/knn/knn_matching.h
        src/imgreg/features/features.cpp
        src/imgreg/features/features.h
        src/imgreg/featuring/orb/orb_featuring.cpp
        src/imgreg/featuring/orb/orb_featuring.h
        src/imgreg/featuring/surf/surf_featuring.cpp
        src/imgreg/featuring/surf/surf_featuring.h
        src/imgreg/featuring/featuring.h
        src/imgreg/warping/warping.h
        src/imgreg/warping/perspective/perspective_warping.h
        src/imgreg/warping/perspective/perspective_warping.cpp
        src/imgreg/pipeline/pipeline.h
        src/imgreg/pipeline/pipeline.cpp)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}
        gtest_main)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

add_test(NAME all_tests COMMAND ${PROJECT_NAME})
