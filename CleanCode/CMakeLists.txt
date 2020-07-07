# CMakeList.txt : CMake project for Point, 
#
cmake_minimum_required (VERSION 3.8)
project(CleanCode)

set(CMAKE_CXX_STANDARD 17)

set(POINT_SOURCES  "clean_code.h" "names.cpp" "complex_function.cpp" "complex_function.h")
set(POINT_MAIN "clean_code.cpp")

# Add source to this project's executable.
add_executable (CleanCode ${POINT_SOURCES} ${POINT_MAIN})
