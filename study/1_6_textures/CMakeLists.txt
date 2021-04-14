add_executable(study_1_6_textures main.cpp)
target_link_libraries(study_1_6_textures
    cringine_core
    libglew_static
    soil2
)
add_custom_command(
    TARGET study_1_6_textures PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/shaders
        ${CMAKE_CURRENT_BINARY_DIR}/shaders
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/shaders
)
add_custom_command(
    TARGET study_1_6_textures PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/textures
        ${CMAKE_CURRENT_BINARY_DIR}/textures
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/textures
)
