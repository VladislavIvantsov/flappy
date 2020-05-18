#include "AbstractShader.hpp"


class DefaultVertex : public AbstractShader {
protected:
    virtual const GLchar *getSource() const{
        return "#version 330 core\n"
               "layout (location = 0) in vec3 aPos;\n"
               "layout (location = 1) in vec3 color;\n"
               "layout (location = 2) in vec2 texCoord\n"
               "out vec3 ourColor;\n"
               "out vec2 TexCoord;\n"
               "void main()\n"
               "{\n"
               "gl_Position = vec4(aPos, 1.0f);\n"
               "ourColor = color;\n"
               "TexCoord = texCoord;\n"
               "}\0";
    };

    virtual ShaderType getType() const{
        return ShaderType::VERTEX;
    };
};