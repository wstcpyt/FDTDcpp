cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(GenericAlgorithm)
set(SOURCE_FILES GeneticAlgorithm.cpp)
add_executable(GeneticAlgorithm ${SOURCE_FILES})


list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)
include(gmock)


add_subdirectory(unit_test)