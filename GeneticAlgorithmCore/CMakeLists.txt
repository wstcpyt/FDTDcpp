cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(GenericAlgorithm)



list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)



include(gmock)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
enable_testing()


add_subdirectory(PopulationCore)
set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")
