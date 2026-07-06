#pragma once

#include "Shader.h"
#include "ShaderUniformTable.h"

struct ShaderProgramHandle {
    unsigned int ID;
    std::vector<ShaderType> &attachments;
    ShaderUniformTable& table;
};

class ShaderProgram
{
public:
    static ShaderProgramHandle Generate();
    static void Destroy(const ShaderProgramHandle &handle);

    static void Bind(const ShaderProgramHandle &handle);
    static void Unbind();

    static void AttachShader(const ShaderProgramHandle &handle, const ShaderHandle &shader);

    static void Compile(const ShaderProgramHandle &handle);

    static void SetBool(const ShaderProgramHandle &handle, const std::string &name, bool value);
    static void SetInt(const ShaderProgramHandle &handle, const std::string &name, int value);
    static void SetFloat(const ShaderProgramHandle &handle, const std::string &name, float value);
    static void SetVec2(const ShaderProgramHandle &handle, const std::string &name, const glm::vec2 &value);
    static void SetVec2(const ShaderProgramHandle &handle, const std::string &name, float x, float y);
    static void SetVec3(const ShaderProgramHandle &handle, const std::string &name, const glm::vec3 &value);
    static void SetVec3(const ShaderProgramHandle &handle, const std::string &name, float x, float y, float z);
    static void SetVec4(const ShaderProgramHandle &handle, const std::string &name, const glm::vec4 &value);
    static void SetVec4(const ShaderProgramHandle &handle, const std::string &name, float x, float y, float z, float w);
    static void SetMat2(const ShaderProgramHandle &handle, const std::string &name, const glm::mat2 &mat);
    static void SetMat3(const ShaderProgramHandle &handle, const std::string &name, const glm::mat3 &mat); 
    static void SetMat4(const ShaderProgramHandle &handle, const std::string &name, const glm::mat4 &mat); 

private:
    static void CheckLinkErrors(const ShaderProgramHandle &handle);
};