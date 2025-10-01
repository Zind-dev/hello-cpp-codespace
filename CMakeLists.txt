cmake_minimum_required(VERSION 3.22)
project(hello_cpp_codespace LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Warnings for GCC/Clang
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)
endif()

# Library (example)
add_library(mylib src/lib.cpp)
target_include_directories(mylib PUBLIC include)

# Tests with Catch2 (via FetchContent)
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.4
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests
  tests/test_sum.cpp
  tests/test_ring_buffer.cpp
)
target_link_libraries(tests PRIVATE mylib Catch2::Catch2WithMain)
include(CTest)
include(Catch)
catch_discover_tests(tests)