cmake_minimum_required(VERSION 3.10)

# Set the project name
project(TestCode)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Add the executable
add_executable(TestCode src/main.cpp src/fibonacci.cpp)

# GoogleTest setup
include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_fibonacci tests/test_fibonacci.cpp src/fibonacci.cpp)
target_link_libraries(test_fibonacci gtest_main)

include(GoogleTest)
gtest_discover_tests(test_fibonacci)
