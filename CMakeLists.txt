cmake_minimum_required(VERSION 3.7)

project(BigFloat CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(BigFloat src/BigInteger)

option(BUILD_PYTHON "Build Python SWIG module" ON)

if (BUILD_PYTHON)
    add_subdirectory(python)
endif()

# Setup testing
include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)
enable_testing()
add_subdirectory(tests)
