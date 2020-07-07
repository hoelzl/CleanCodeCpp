# CMakeList.txt : CMake project for PrimeFactors, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project(PrimeFactors)

set(CMAKE_CXX_STANDARD 17)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(googletest)
include_directories(googletest/googletest/include googletest/googletest)
include_directories(googletest/googlemock/include googletest/googlemock)

set(PRIME_FACTOR_SOURCES  "prime_factors.cpp" "prime_factors.h")
set(PRIME_FACTOR_MAIN "prime_factors_main.cpp")
set(PRIME_FACTOR_TEST "prime_factors_test.cpp")

# Add source to this project's executable.
add_executable (PrimeFactors ${PRIME_FACTOR_SOURCES} ${PRIME_FACTOR_MAIN})

enable_testing()

add_executable(PrimeFactorsTest ${PRIME_FACTOR_SOURCES} ${PRIME_FACTOR_TEST})
target_link_libraries(PrimeFactorsTest gtest gtest_main)