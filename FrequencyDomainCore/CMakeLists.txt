set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(frequencyDomainCore FrequencyDomain.cpp)
add_subdirectory(unit_test)