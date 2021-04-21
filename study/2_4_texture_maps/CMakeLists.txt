add_executable(study_2_4_texture_maps main.cpp)
target_link_libraries(study_2_4_texture_maps
    cringine_core
    libglew_static
    glm
)
target_compile_definitions(study_2_4_texture_maps
    PUBLIC RESOURCES="${RESOURCES_PATH}"
)
