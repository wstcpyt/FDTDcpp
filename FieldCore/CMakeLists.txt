set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(fieldCore EMField.cpp EMField.h)
add_subdirectory(unit_test)