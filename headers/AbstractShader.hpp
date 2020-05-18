#pragma once

#include <glad/glad.h>
#include <string>
#include <sstream>

enum ShaderType {
    COMPUTE = GL_COMPUTE_SHADER,
    VERTEX = GL_VERTEX_SHADER,
    TESS_CONTROL = GL_TESS_CONTROL_SHADER,
    TESS_EVALUATION = GL_TESS_EVALUATION_SHADER,
    GEOMETRY = GL_GEOMETRY_SHADER,
    FRAGMENT = GL_FRAGMENT_SHADER
};

class AbstractShader {
private:
    GLuint shaderId{};
    GLchar infoLog[512];
    GLint success;

protected:
    virtual const GLchar *getSource() const = 0;

    virtual ShaderType getType() const = 0;

public:
    AbstractShader(AbstractShader const &) = delete;

    AbstractShader &operator=(AbstractShader const &) = delete;

    AbstractShader() = default;

    ~AbstractShader() { glDeleteShader(this->shaderId); }

    bool init() {
        const GLchar *shaderCode = this->getSource();
        this->shaderId = glCreateShader(this->getType());
        glShaderSource(this->shaderId, 1, &shaderCode, NULL);
        glCompileShader(this->shaderId);
        glGetShaderiv(this->shaderId, GL_COMPILE_STATUS, &this->success);
        if (!this->success) {
            glGetShaderInfoLog(this->shaderId, 512, NULL, this->infoLog);
            return false;
        }
        return true;
    }

    GLuint getId() const { return this->shaderId; }

    std::string getErrorMessage() const {
        std::ostringstream output;
        output << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << this->infoLog << std::endl;
        return output.str();
    }
};
