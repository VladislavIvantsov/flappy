#include "AbstractShader.hpp"


class DefaultFragment : public AbstractShader {
protected:
    virtual const GLchar *getSource() const {
        return "#version 330 core\n"
               "in vec3 ourColor;\n"
               "in vec2 TexCoord;\n"
               "out vec4 color;\n"
               "uniform sampler2D ourTexture;\n"
               "void main()\n"
               "{\n"
               "color = vec4(ourTexture, TexCoord);\n"
               "}\0";
    }

    virtual ShaderType getType() const {
        return ShaderType::FRAGMENT;
    };
};