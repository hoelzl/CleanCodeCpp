cmake_minimum_required (VERSION 3.8)
project(Stack)

set(CMAKE_CXX_STANDARD 17)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(googletest)
include_directories(googletest/googletest/include googletest/googletest)
include_directories(googletest/googlemock/include googletest/googlemock)

set(stack_sources  "stack.cpp" "stack.h")
set(stack_main "stack_main.cpp")
set(stack_test "stack_test.cpp")

# Add source to this project's executable.
add_executable (Stack ${stack_sources} ${stack_main})

enable_testing()

add_executable(StackTest ${stack_sources} ${stack_test})
target_link_libraries(StackTest gmock gmock_main)