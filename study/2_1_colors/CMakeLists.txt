add_executable(study_2_1_colors main.cpp)
target_link_libraries(study_2_1_colors
    cringine_core
    libglew_static
    glm
)
add_custom_command(
    TARGET study_2_1_colors PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/shaders
        ${CMAKE_CURRENT_BINARY_DIR}/shaders
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/shaders
)
