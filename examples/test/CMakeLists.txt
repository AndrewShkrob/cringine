add_executable(example_test main.cpp)
target_link_libraries(example_test
    cringine_core
)
target_compile_definitions(example_test
    PUBLIC RESOURCES="${RESOURCES_PATH}"
)
