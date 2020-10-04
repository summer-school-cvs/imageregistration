cmake_minimum_required(VERSION 3.16)

project(core)

option(LOG_IN_STDOUT_ENABLE "" ON)
option(LOG_IN_SYSTEMD_ENABLE "" ON)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        include/stitching/core/factory.h
        include/stitching/core/features.h
        include/stitching/core/ifeaturing.h
        include/stitching/core/ihomography.h
        include/stitching/core/imatching.h
        include/stitching/core/istitcher.h
        include/stitching/core/iwarping.h
        include/stitching/core/logging.h


        src/logging.cpp
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    )

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        $<$<BOOL:${LOG_IN_STDOUT_ENABLE}>:LOG_IN_STDOUT_ENABLE>
        $<$<BOOL:${LOG_IN_SYSTEMD_ENABLE}>:LOG_IN_SYSTEMD_ENABLE>
    )

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${OpenCV_LIBS}
        Boost::headers
        spdlog::spdlog
        systemd
    )
