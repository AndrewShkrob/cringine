#include "load_from_file.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace cringine;

std::string cringine::utils::load_from_file(const std::string& file_path)
{
    std::string result;

    std::ifstream file;
    file.exceptions(std::ifstream::badbit);
    try {
        file.open(file_path);
        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        result = stream.str();
    } catch (std::ifstream::failure& e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << file_path << std::endl;
    }

    return result;
}
