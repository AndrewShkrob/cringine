add_executable(study_1_9_camera main.cpp)
target_link_libraries(study_1_9_camera
    cringine_window
    cringine_graphics
    cringine_types
    libglew_static
    soil2
    glm
)
add_custom_command(
    TARGET study_1_9_camera PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/shaders
        ${CMAKE_CURRENT_BINARY_DIR}/shaders
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/shaders
)
add_custom_command(
    TARGET study_1_9_camera PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/textures
        ${CMAKE_CURRENT_BINARY_DIR}/textures
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/textures
)