cmake_minimum_required(VERSION 3.0)
project(cringine)

set(CMAKE_CXX_STANDARD 20)

set(RESOURCES_PATH ${CMAKE_CURRENT_LIST_DIR}/resources/)

set(ASSIMP_BUILD_ZLIB ON)
set(BUILD_SHARED_LIBS OFF)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
set(ASSIMP_BUILD_TESTS OFF)
set(INJECT_DEBUG_POSTFIX OFF)

add_subdirectory(third_party)
add_subdirectory(libs)
add_subdirectory(examples)
add_subdirectory(study)
