add_executable(study_1_5_shaders main.cpp)
target_link_libraries(study_1_5_shaders cringine_window cringine_graphics libglew_static)
add_custom_command(
    TARGET study_1_5_shaders PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/shaders
        ${CMAKE_CURRENT_BINARY_DIR}/shaders
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/shaders
)