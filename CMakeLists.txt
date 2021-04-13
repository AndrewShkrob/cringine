cmake_minimum_required(VERSION 3.0)
project(cringine)

set(CMAKE_CXX_STANDARD 20)

set(RESOURCES_PATH ${CMAKE_CURRENT_LIST_DIR}/resources/)

add_subdirectory(third_party)
add_subdirectory(libs)
add_subdirectory(examples)
add_subdirectory(study)