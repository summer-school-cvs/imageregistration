cmake_minimum_required(VERSION 3.16)

project(main)

find_package(Boost REQUIRED COMPONENTS program_options)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    )

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        core Boost::program_options
        spdlog::spdlog
    )
