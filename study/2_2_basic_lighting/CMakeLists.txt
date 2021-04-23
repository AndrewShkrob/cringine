add_executable(study_2_2_basic_lighting main.cpp)
target_link_libraries(study_2_2_basic_lighting
    cringine_core
    libglew_static
    glm
)
add_custom_command(
    TARGET study_2_2_basic_lighting PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/shaders
        ${CMAKE_CURRENT_BINARY_DIR}/shaders
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/shaders
)
