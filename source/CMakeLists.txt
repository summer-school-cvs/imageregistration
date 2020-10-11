cmake_minimum_required(VERSION 3.16)

add_subdirectory(core)
add_subdirectory(featuring)
add_subdirectory(matching)
add_subdirectory(homography)
add_subdirectory(warping)
add_subdirectory(simplestitcher)
add_subdirectory(main)
add_subdirectory(stitcher)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
