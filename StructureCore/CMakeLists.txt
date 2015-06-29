set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(structureCore Structure.cpp)
add_subdirectory(unit_test)