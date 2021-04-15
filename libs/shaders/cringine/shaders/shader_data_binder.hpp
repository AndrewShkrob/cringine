#pragma once

#include <cringine/shaders/shader.hpp>

#include <string>

namespace cringine::shaders
{
    class shader_data_binder
    {
    public:
        template<class... T>
        void set_uniform(std::string uniform_name, T... args);

        template<class T>
        void set_uniform(std::string uniform_name, int count, const T value);

    private:
        //        std::unordered_map<std::string, std::unique_ptr<shader_data_holder>> m_uniform_data;
    };
} // namespace cringine::shaders