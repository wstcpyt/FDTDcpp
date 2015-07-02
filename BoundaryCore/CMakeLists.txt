set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(boundaryCore Boundary.cpp TFSFTMz.cpp)
target_link_libraries(boundaryCore structureCore)
add_subdirectory(unit_test)