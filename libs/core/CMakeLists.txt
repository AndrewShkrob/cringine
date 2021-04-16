include(CMakeSources.txt)

set(CRINGINE_LIB_NAME cringine_core)

add_library(${CRINGINE_LIB_NAME} STATIC ${CRINGINE_CORE_SOURCES})
target_include_directories(${CRINGINE_LIB_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${CRINGINE_LIB_NAME}
    PUBLIC cringine_event_system
    PUBLIC cringine_shaders
    PUBLIC cringine_types
    PUBLIC cringine_utils
    PUBLIC cringine_window
)
