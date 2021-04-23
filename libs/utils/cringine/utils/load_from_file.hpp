#pragma once

#include <string>
#include <vector>

namespace cringine::utils
{
    std::vector<std::string> shader_from_file(const std::string& file_path);

    unsigned int texture_from_file(const std::string& file_path);
}
