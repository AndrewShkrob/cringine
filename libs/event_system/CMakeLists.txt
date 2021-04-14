include(CMakeSources.txt)

set(CRINGINE_LIB_NAME cringine_event_system)

add_library(${CRINGINE_LIB_NAME} STATIC ${CRINGINE_EVENT_SYSTEM_SOURCES})
target_include_directories(${CRINGINE_LIB_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${CRINGINE_LIB_NAME}
    PUBLIC cringine_utils
    PRIVATE glfw
)
