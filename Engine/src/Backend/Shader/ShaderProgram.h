#pragma once

#include "Shader.h"
#include "ShaderUniformTable.h"

struct ShaderProgramHandle {
    unsigned int ID;
    std::vector<ShaderType> attachments;
    ShaderUniformTable table;
};

class ShaderProgram
{
public:
    static ShaderProgramHandle Generate();
    static void Destroy(const ShaderProgramHandle &handle);

    static void Bind(const ShaderProgramHandle &handle);
    static void Unbind();

    static void AttachShader(ShaderProgramHandle &handle, const ShaderHandle &shader);

    static void Compile(const ShaderProgramHandle &handle);

    static void SetBool(ShaderProgramHandle &handle, const std::string &name, bool value);
    static void SetInt(ShaderProgramHandle &handle, const std::string &name, int value);
    static void SetFloat(ShaderProgramHandle &handle, const std::string &name, float value);
    static void SetVec2(ShaderProgramHandle &handle, const std::string &name, const glm::vec2 &value);
    static void SetVec2(ShaderProgramHandle &handle, const std::string &name, float x, float y);
    static void SetVec3(ShaderProgramHandle &handle, const std::string &name, const glm::vec3 &value);
    static void SetVec3(ShaderProgramHandle &handle, const std::string &name, float x, float y, float z);
    static void SetVec4(ShaderProgramHandle &handle, const std::string &name, const glm::vec4 &value);
    static void SetVec4(ShaderProgramHandle &handle, const std::string &name, float x, float y, float z, float w);
    static void SetMat2(ShaderProgramHandle &handle, const std::string &name, const glm::mat2 &mat);
    static void SetMat3(ShaderProgramHandle &handle, const std::string &name, const glm::mat3 &mat); 
    static void SetMat4(ShaderProgramHandle &handle, const std::string &name, const glm::mat4 &mat); 

private:
    static void CheckLinkErrors(const ShaderProgramHandle &handle);
};