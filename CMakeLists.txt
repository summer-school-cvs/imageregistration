cmake_minimum_required(VERSION 3.16)

project(ImageRegistration)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(TO_NATIVE_PATH "${CMAKE_CURRENT_LIST_DIR}/data" TEST_DATA_DIR)
add_compile_definitions(TEST_DATA_DIR="${TEST_DATA_DIR}")

message(STATUS "Test data dir: ${TEST_DATA_DIR}")

add_subdirectory(thirdparty/googletest googletest)

add_subdirectory(source/core)
add_subdirectory(source/multiregistration)
add_subdirectory(source/featuring)
add_subdirectory(source/matching)
add_subdirectory(source/homography)
add_subdirectory(source/warping)

enable_testing()
