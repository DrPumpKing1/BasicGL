#pragma once

#include <glad/gl.h>
#include <glm/glm.hpp>

#include "../FileSystem/FileReader.h"

const unsigned int SHADER_INFO_LOG_SIZE = 1024;

enum class ShaderType {
    COMPUTE,
    VERTEX,
    TESS_CONTROL,
    TESS_EVALUATION,
    GEOMETRY,
    FRAGMENT
};

struct ShaderHandle {
    unsigned int ID;
    ShaderType type;
};

class Shader 
{
public:
    static ShaderHandle Generate(const std::string &path, ShaderType type);

    static std::string ShaderTypeToString(ShaderType type);
    static GLenum ShaderTypeToGL(ShaderType type);
private:
    static void CheckCompileErrors(const ShaderHandle &handle);
};