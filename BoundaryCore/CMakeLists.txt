set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(boundaryCore Boundary.cpp TFSFTMz.cpp)
target_link_libraries(boundaryCore structureCore)
target_link_libraries(boundaryCore fieldCore)
target_link_libraries(boundaryCore sourceCore)
add_subdirectory(unit_test)