set(KOOLPLOT "../../cpplib/koolplot1_2"
    CACHE PATH "The path to the KOOLPLOT test framework.")
add_subdirectory(${KOOLPLOT} ${CMAKE_BINARY_DIR}/koolplot)
include_directories(SYSTEM ${KOOLPLOT})