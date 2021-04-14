add_executable(study_2_3_materials main.cpp)
target_link_libraries(study_2_3_materials
    cringine_core
    libglew_static
    soil2
    glm
)
add_custom_command(
    TARGET study_2_3_materials PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/shaders
        ${CMAKE_CURRENT_BINARY_DIR}/shaders
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/shaders
)
