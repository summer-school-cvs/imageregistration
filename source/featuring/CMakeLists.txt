cmake_minimum_required(VERSION 3.16)

project(featuring)

find_package(OpenCV REQUIRED)

macro(add_featuring_lib)
    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs SRC LIBS)
    cmake_parse_arguments(ARG_VAL "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN})

    add_library(${ARG_VAL_TARGET})
    target_sources(${ARG_VAL_TARGET} PRIVATE ${ARG_VAL_SRC})
    target_include_directories(${ARG_VAL_TARGET} PUBLIC include)
    target_link_libraries(${ARG_VAL_TARGET} ${ARG_VAL_LIBS})
endmacro()

add_featuring_lib(TARGET orbfeaturing
    SRC
        include/stitching/featuring/orb/orb_featuring.h
        source/orb/orb_featuring.cpp
    LIBS
        core
        ${OpenCV_LIBS}
    )

add_featuring_lib(TARGET surffeaturing
    SRC
        include/stitching/featuring/surf/surf_featuring.h
        source/surf/surf_featuring.cpp
    LIBS
        core
        ${OpenCV_LIBS}
    )

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME}
    INTERFACE
        surffeaturing
        orbfeaturing
    )

add_subdirectory(tests)
