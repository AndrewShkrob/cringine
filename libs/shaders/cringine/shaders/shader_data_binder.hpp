#pragma once

#include <cringine/shaders/shader.hpp>
#include <cringine/shaders/shader_uniform_type.hpp>

#include <string>

namespace cringine::shaders
{
    class shader_data_binder
    {
    public:
        explicit shader_data_binder(shader& shader);

        [[maybe_unused]] void set_uniform_1f(const std::string& uniform_name, float v0) const;
        [[maybe_unused]] void set_uniform_2f(const std::string& uniform_name, float v0, float v1) const;
        [[maybe_unused]] void set_uniform_3f(const std::string& uniform_name, float v0, float v1, float v2) const;
        [[maybe_unused]] void set_uniform_4f(const std::string& uniform_name, float v0, float v1, float v2, int v3) const;

        [[maybe_unused]] void set_uniform_1i(const std::string& uniform_name, int v0) const;
        [[maybe_unused]] void set_uniform_2i(const std::string& uniform_name, int v0, int v1) const;
        [[maybe_unused]] void set_uniform_3i(const std::string& uniform_name, int v0, int v1, int v2) const;
        [[maybe_unused]] void set_uniform_4i(const std::string& uniform_name, int v0, int v1, int v2, int v3) const;

        [[maybe_unused]] void set_uniform_1ui(const std::string& uniform_name, unsigned int v0) const;
        [[maybe_unused]] void set_uniform_2ui(const std::string& uniform_name, unsigned int v0, unsigned int v1) const;
        [[maybe_unused]] void set_uniform_3ui(const std::string& uniform_name, unsigned int v0, unsigned int v1, unsigned int v2) const;
        [[maybe_unused]] void set_uniform_4ui(const std::string& uniform_name, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3) const;

        [[maybe_unused]] void set_uniform_1fv(const std::string& uniform_name, int count, const float* value) const;
        [[maybe_unused]] void set_uniform_2fv(const std::string& uniform_name, int count, const float* value) const;
        [[maybe_unused]] void set_uniform_3fv(const std::string& uniform_name, int count, const float* value) const;
        [[maybe_unused]] void set_uniform_4fv(const std::string& uniform_name, int count, const float* value) const;

        [[maybe_unused]] void set_uniform_1iv(const std::string& uniform_name, int count, const int* value) const;
        [[maybe_unused]] void set_uniform_2iv(const std::string& uniform_name, int count, const int* value) const;
        [[maybe_unused]] void set_uniform_3iv(const std::string& uniform_name, int count, const int* value) const;
        [[maybe_unused]] void set_uniform_4iv(const std::string& uniform_name, int count, const int* value) const;

        [[maybe_unused]] void set_uniform_1uiv(const std::string& uniform_name, int count, const unsigned int* value) const;
        [[maybe_unused]] void set_uniform_2uiv(const std::string& uniform_name, int count, const unsigned int* value) const;
        [[maybe_unused]] void set_uniform_3uiv(const std::string& uniform_name, int count, const unsigned int* value) const;
        [[maybe_unused]] void set_uniform_4uiv(const std::string& uniform_name, int count, const unsigned int* value) const;

        [[maybe_unused]] void set_uniform_matrix2fv(const std::string& uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix3fv(const std::string& uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix4fv(const std::string& uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix2x3fv(const std::string& uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix3x2fv(const std::string& uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix2x4fv(const std::string& uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix4x2fv(const std::string& uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix3x4fv(const std::string& uniform_name, int count, bool transpose, const float* value) const;
        [[maybe_unused]] void set_uniform_matrix4x3fv(const std::string& uniform_name, int count, bool transpose, const float* value) const;

    private:
        [[nodiscard]] int get_uniform_location(const std::string& uniform_name) const;

        shader& m_shader;
    };
} // namespace cringine::shaders