include(CMakeSources.txt)

set(CRINGINE_LIB_NAME cringine_shaders)

add_library(${CRINGINE_LIB_NAME} STATIC ${CRINGINE_SHADERS_SOURCES})
target_include_directories(${CRINGINE_LIB_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${CRINGINE_LIB_NAME}
    PRIVATE cringine_utils
    PRIVATE libglew_static
)
