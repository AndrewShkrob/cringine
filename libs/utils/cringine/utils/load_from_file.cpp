#include "load_from_file.hpp"

#include <GL/glew.h>

#include <stb_image.h>
#include <fstream>
#include <iostream>

using namespace cringine;

std::vector<std::string> cringine::utils::shader_from_file(const std::string& file_path)
{
    std::vector<std::string> result;

    std::ifstream file(file_path);
    file.exceptions(std::ifstream::badbit);
    std::string line;
    try {
        while (std::getline(file, line)) {
            line += '\n';
            result.push_back(std::move(line));
        }
    } catch (std::ifstream::failure& /* unused */) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << file_path << std::endl;
    }

    return std::move(result);
}

unsigned int cringine::utils::texture_from_file(const std::string& file_path)
{
    stbi_set_flip_vertically_on_load(1);
    unsigned int texture_id{};
    glGenTextures(1, &texture_id);

    int width{};
    int height{};
    int nrComponents{};
    unsigned char* data = stbi_load(file_path.c_str(), &width, &height, &nrComponents, 0);
    if (data != nullptr) {
        GLenum format{};
        if (nrComponents == 1) {
            format = GL_RED;
        } else if (nrComponents == 3) {
            format = GL_RGB;
        } else if (nrComponents == 4) {
            format = GL_RGBA;
        }

        glBindTexture(GL_TEXTURE_2D, texture_id);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    } else {
        std::cout << "Texture failed to load at path: " << file_path << std::endl;
    }

    stbi_image_free(data);

    return texture_id;
}
