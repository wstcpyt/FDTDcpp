cmake_minimum_required(VERSION 3.2)
project(FDTDcpp)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

enable_testing()

include(gmock)
include(benchmark)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(SourceCore)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(FDTDcpp ${SOURCE_FILES})
target_link_libraries(FDTDcpp sourceCore)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")