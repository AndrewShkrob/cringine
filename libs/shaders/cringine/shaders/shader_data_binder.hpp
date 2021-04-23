#pragma once

#include <cringine/shaders/shader.hpp>

#include <string_view>

namespace cringine::shaders
{
    class shader_data_binder
    {
    public:
        explicit shader_data_binder(shader& shader);

        [[maybe_unused]] void set_uniform_1f(std::string_view uniform_name, float v0) const;
        [[maybe_unused]] void set_uniform_2f(std::string_view uniform_name, float v0, float v1) const;
        [[maybe_unused]] void set_uniform_3f(std::string_view uniform_name, float v0, float v1, float v2) const;
        [[maybe_unused]] void set_uniform_4f(std::string_view uniform_name, float v0, float v1, float v2, float v3) const;

        [[maybe_unused]] void set_uniform_1i(std::string_view uniform_name, int v0) const;
        [[maybe_unused]] void set_uniform_2i(std::string_view uniform_name, int v0, int v1) const;
        [[maybe_unused]] void set_uniform_3i(std::string_view uniform_name, int v0, int v1, int v2) const;
        [[maybe_unused]] void set_uniform_4i(std::string_view uniform_name, int v0, int v1, int v2, int v3) const;

        [[maybe_unused]] void set_uniform_1ui(std::string_view uniform_name, unsigned int v0) const;
        [[maybe_unused]] void set_uniform_2ui(std::string_view uniform_name, unsigned int v0, unsigned int v1) const;
        [[maybe_unused]] void set_uniform_3ui(std::string_view uniform_name, unsigned int v0, unsigned int v1, unsigned int v2) const;
        [[maybe_unused]] void set_uniform_4ui(std::string_view uniform_name, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3) const;

        [[maybe_unused]] void set_uniform_1fv(std::string_view uniform_name, int count, const float* value) const;
        [[maybe_unused]] void set_uniform_2fv(std::string_view uniform_name, int count, const float* value) const;
        [[maybe_unused]] void set_uniform_3fv(std::string_view uniform_name, int count, const float* value) const;
        [[maybe_unused]] void set_uniform_4fv(std::string_view uniform_name, int count, const float* value) const;

        [[maybe_unused]] void set_uniform_1iv(std::string_view uniform_name, int count, const int* value) const;
        [[maybe_unused]] void set_uniform_2iv(std::string_view uniform_name, int count, const int* value) const;
        [[maybe_unused]] void set_uniform_3iv(std::string_view uniform_name, int count, const int* value) const;
        [[maybe_unused]] void set_uniform_4iv(std::string_view uniform_name, int count, const int* value) const;

        [[maybe_unused]] void set_uniform_1uiv(std::string_view uniform_name, int count, const unsigned int* value) const;
        [[maybe_unused]] void set_uniform_2uiv(std::string_view uniform_name, int count, const unsigned int* value) const;
        [[maybe_unused]] void set_uniform_3uiv(std::string_view uniform_name, int count, const unsigned int* value) const;
        [[maybe_unused]] void set_uniform_4uiv(std::string_view uniform_name, int count, const unsigned int* value) const;

        [[maybe_unused]] void set_uniform_matrix2fv(std::string_view uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix3fv(std::string_view uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix4fv(std::string_view uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix2x3fv(std::string_view uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix3x2fv(std::string_view uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix2x4fv(std::string_view uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix4x2fv(std::string_view uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix3x4fv(std::string_view uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix4x3fv(std::string_view uniform_name, int count, bool transpose, const float* value) const;

    private:
        [[nodiscard]] int get_uniform_location(std::string_view uniform_name) const;

        shader& m_shader;
    };
} // namespace cringine::shaders
