project(stb-cmake)

add_library(stb-cmake stb_image.h stb_image.cpp)
target_include_directories(stb-cmake PUBLIC ${CMAKE_CURRENT_LIST_DIR})
