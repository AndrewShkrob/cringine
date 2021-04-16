#include "load_from_file.hpp"

#include <fstream>
#include <iostream>

using namespace cringine;

std::vector<std::string> cringine::utils::load_from_file(const std::string& file_path)
{
    std::vector<std::string> result;

    std::ifstream file;
    file.exceptions(std::ifstream::badbit);
    std::string line;
    try {
        while (std::getline(file, line)) {
            result.push_back(std::move(line));
        }
    } catch (std::ifstream::failure& /* unused */) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << file_path << std::endl;
    }

    return std::move(result);
}
