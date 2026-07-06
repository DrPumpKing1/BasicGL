#include "Shader.h"

ShaderHandle Shader::Generate(const std::string &path, ShaderType type) {
    ShaderHandle handle;
    handle.type = type;

    const char* source = FileReader::ReadFile(path).c_str();
    handle.ID = glCreateShader(ShaderTypeToGL(type));
    glShaderSource(handle.ID, 1, &source, nullptr);
    glCompileShader(handle.ID);
    CheckCompileErrors(handle);

    return handle;
}

void Shader::CheckCompileErrors(const ShaderHandle &shader) {
    int success;
    char infoLog[SHADER_INFO_LOG_SIZE];
    glGetShaderiv(shader.ID, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader.ID, SHADER_INFO_LOG_SIZE, nullptr, infoLog);
        std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << ShaderTypeToString(shader.type) << "\n" << infoLog << "\n -- --------------------------------------------------- --";
    }
}

std::string Shader::ShaderTypeToString(ShaderType type)
{
    switch (type)
    {
        case ShaderType::COMPUTE:
            return "COMPUTE";
        case ShaderType::VERTEX:
            return "VERTEX";
        case ShaderType::TESS_CONTROL:
            return "TESSELATION CONTROL";
        case ShaderType::TESS_EVALUATION:
            return "TESSELATION EVALUATION";
        case ShaderType::GEOMETRY:
            return "GEOMETRY";
        case ShaderType::FRAGMENT:
            return "FRAGMENT";
        default:
            return "UNKNOWN";
    }
}

GLenum Shader::ShaderTypeToGL(ShaderType type)
{
    switch (type)
    {
        case ShaderType::COMPUTE:
            return GL_COMPUTE_SHADER;
        case ShaderType::VERTEX:
            return GL_VERTEX_SHADER;
        case ShaderType::TESS_CONTROL:
            return GL_TESS_CONTROL_SHADER;
        case ShaderType::TESS_EVALUATION:
            return GL_TESS_EVALUATION_SHADER;
        case ShaderType::GEOMETRY:
            return GL_GEOMETRY_SHADER;
        case ShaderType::FRAGMENT:
            return GL_FRAGMENT_SHADER;
        default:
            throw std::invalid_argument("Unknown shader type");
    }
}