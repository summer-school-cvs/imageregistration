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

file(TO_NATIVE_PATH "${CMAKE_CURRENT_LIST_DIR}/config/imageregistration.json" CONFIG_FILE)

add_compile_definitions(
    PROJECT_VERSION="${PROJECT_VERSION}"
    PROJECT_DESCRIPTION="${PROJECT_DESCRIPTION}"
    CONFIG_FILE="${CONFIG_FILE}"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
if(BUILD_TESTING)
    file(TO_NATIVE_PATH "${CMAKE_CURRENT_BINARY_DIR}/Dataset" TEST_DATA_DIR)
    if(NOT EXISTS "${TEST_DATA_DIR}")
        set(FILE_ID 1tBNjlUs4BSCh6ynqmHwJ81jjlyPOadUo)
        file(TO_NATIVE_PATH "${CMAKE_CURRENT_BINARY_DIR}/dataset.zip" DATASET_FILE)
        include(cmake/GDrive.cmake)
        downlad_from_gdrive(ID ${FILE_ID} RESULT ${DATASET_FILE})
        execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${DATASET_FILE} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
    endif()
    add_compile_definitions(TEST_DATA_DIR="${TEST_DATA_DIR}")
    message(STATUS "Test data dir: ${TEST_DATA_DIR}")
endif()

add_subdirectory(thirdparty/googletest googletest)
add_subdirectory(thirdparty/spdlog spdlog)

add_subdirectory(source)

enable_testing()
