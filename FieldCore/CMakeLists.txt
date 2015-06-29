set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(fieldCore EMField.cpp EMField.h EMField_2D_TMz.cpp)
target_link_libraries(fieldCore structureCore)
add_subdirectory(unit_test)