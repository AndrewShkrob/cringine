#include "shader_data_binder.hpp"

using namespace cringine::shaders;

template<class... T>
void shader_data_binder::set_uniform(std::string uniform_name, T... args)
{
}

template<class T>
void shader_data_binder::set_uniform(std::string uniform_name, int count, const T value)
{
}

template void shader_data_binder::set_uniform<float>(std::string, float...);
template void shader_data_binder::set_uniform<int>(std::string, int...);
template void shader_data_binder::set_uniform<unsigned int>(std::string, unsigned int...);