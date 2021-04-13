include(CMakeSources.txt)

set(CRINGINE_LIB_NAME cringine_window)

add_library(${CRINGINE_LIB_NAME} STATIC ${CRINGINE_WINDOW_SOURCES})
target_include_directories(${CRINGINE_LIB_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${CRINGINE_LIB_NAME}
    cringine_event_system
    glfw
)