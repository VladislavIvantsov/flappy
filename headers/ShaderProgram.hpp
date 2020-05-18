#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

#include "AbstractShader.hpp"

class ShaderProgram {
private:
    GLchar infoLog[512]{};
    GLuint program{};

public:
    ShaderProgram() {
        this->program = glCreateProgram();
    };

    ~ShaderProgram() = default;

    bool link() {
        GLint success;
        glLinkProgram(this->program);
        glGetProgramiv(this->program, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(this->program, 512, NULL, infoLog);
            return false;
        }
        return true;
    }

    std::string getErrorMessage() const {
        std::ostringstream output;
        output << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << this->infoLog << std::endl;
        return output.str();
    }

    void attachShader(AbstractShader *shader) {
        glAttachShader(this->program, shader->getId());
    }

    void use() {
        glUseProgram(this->program);
    }

    GLint getUniformLocation(const GLchar *uniformName) const {
        return glGetUniformLocation(this->program, uniformName);
    }
};