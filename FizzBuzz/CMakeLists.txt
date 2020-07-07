cmake_minimum_required (VERSION 3.8)
project(FizzBuzz)

set(CMAKE_CXX_STANDARD 17)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(googletest)
include_directories(googletest/googletest/include googletest/googletest)
include_directories(googletest/googlemock/include googletest/googlemock)

set(FIZZ_BUZZ_SOURCES  "fizz_buzz.cpp" "fizz_buzz.h")
set(FIZZ_BUZZ_MAIN "fizz_buzz_main.cpp")
set(FIZZ_BUZZ_TEST "fizz_buzz_test.cpp")

# Add source to this project's executable.
add_executable (FizzBuzz ${FIZZ_BUZZ_SOURCES} ${FIZZ_BUZZ_MAIN})

enable_testing()

add_executable(FizzBuzzTest ${FIZZ_BUZZ_SOURCES} ${FIZZ_BUZZ_TEST})
target_link_libraries(FizzBuzzTest gmock gmock_main)