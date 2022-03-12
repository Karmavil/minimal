cmake_minimum_required(VERSION 3.13)

# Set the C++ standard we will use
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17") # -pthread")
project(minimal)

set(CMAKE_BUILD_TYPE Debug)

set(BUILD_SHARED_LIBS ON)
set(SYSTEM ${CMAKE_SYSTEM_NAME})
set(ARQUITECTURE ${CMAKE_HOST_SYSTEM_PROCESSOR})
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/godot_project/bin/${SYSTEM}/${ARQUITECTURE}")


include_directories(include)

# Add project executable
add_library(${CMAKE_PROJECT_NAME} SHARED src/_extension.cpp src/bug.cpp src/red_car_panel.cpp src/carbon_car_panel.cpp)


# Dependencies
include_directories(
    godot-cpp/godot-headers
    godot-cpp/include/godot_cpp/core
    godot-cpp/include
    godot-cpp/gen/include
    godot-cpp/gen/include/godot_cpp/classes
    godot-cpp/gen/include/godot_cpp/variant
    godot-cpp/godot-headers/godot
    godot-cpp/include/godot_cpp
)

include(godot_cpp_lib_names.cmake)
find_library(GODOT_CPP godot-cpp    NAMES ${LIB_GODOT_CPP}  PATHS godot-cpp/bin/ NO_DEFAULT_PATH)

if (${GODOT_CPP} STREQUAL GODOT_CPP-NOTFOUND)
    message(FATAL_ERROR "Library godot-cpp NOT found")
else()
    message(STATUS "godot-cpp library found")
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${GODOT_CPP})
