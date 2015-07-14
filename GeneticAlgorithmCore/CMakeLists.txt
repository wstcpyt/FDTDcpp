set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(geneticAlgorithm GeneticAlgorithm.cpp)
add_subdirectory(unit_test)