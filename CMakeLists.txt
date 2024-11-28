cmake_minimum_required(VERSION 3.13)  # CMake version check
project(raytracer)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of the project root directory as a source file
# set(SOURCE_FILES main.cc)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(raytracer ./src/main.cc)

# Include target directories to allow include paths without direct paths
target_include_directories(raytracer
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include/primitives
        ${CMAKE_SOURCE_DIR}/include/hittable
)