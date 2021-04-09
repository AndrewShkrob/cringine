add_executable(study_2_4_texture_maps main.cpp)
target_link_libraries(study_2_4_texture_maps
    cringine_window
    cringine_graphics
    cringine_types
    libglew_static
    soil2
    glm
)
target_compile_definitions(study_2_4_texture_maps
    PUBLIC RESOURCES="${RESOURCES_PATH}"
)