include(CMakeSources.txt)

set(CRINGINE_LIB_NAME cringine_renderer)

add_library(${CRINGINE_LIB_NAME} STATIC ${CRINGINE_RENDERER_SOURCES})
target_include_directories(${CRINGINE_LIB_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${CRINGINE_LIB_NAME}
    PRIVATE cringine_shaders
    PRIVATE cringine_types
    PRIVATE libglew_static
)
