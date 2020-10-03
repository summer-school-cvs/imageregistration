cmake_minimum_required(VERSION 3.16)

include(cmake/Helpers.cmake)
git_description(GIT_DESCRIPTOR GIT_TAG GIT_COMMIT_COUNT)

if(NOT BUILD_NUMBER)
    set(BUILD_NUMBER "")
else()
    set(BUILD_NUMBER ".${BUILD_NUMBER}")
endif()

project(ImageRegistration
    VERSION 0.0.${GIT_COMMIT_COUNT}${BUILD_NUMBER}
    DESCRIPTION "Image stitching. ${GIT_DESCRIPTOR}"
    )

add_compile_definitions(
PROJECT_VERSION="${PROJECT_VERSION}"
PROJECT_DESCRIPTION="${PROJECT_DESCRIPTION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(TO_NATIVE_PATH "${CMAKE_CURRENT_LIST_DIR}/data" TEST_DATA_DIR)
add_compile_definitions(TEST_DATA_DIR="${TEST_DATA_DIR}")

message(STATUS "Test data dir: ${TEST_DATA_DIR}")

add_subdirectory(thirdparty/googletest googletest)

add_subdirectory(source)

enable_testing()
