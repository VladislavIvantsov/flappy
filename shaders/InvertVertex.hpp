#include "AbstractShader.hpp"


class InvertVertex : public AbstractShader {
protected:
    virtual const GLchar *getSource() const{
        return "#version 330 core\n"
               "layout (location = 0) in vec3 position;\n"
               "layout (location = 1) in vec3 color;\n"
               "out vec3 ourColor;\n"
               "void main()\n"
               "{\n"
               "gl_Position = vec4(position.x, -position.y, position.z, 1.0f);\n"
               "ourColor = color;\n"
               "}\0";
    };

    virtual ShaderType getType() const{
        return ShaderType::VERTEX;
    };
};