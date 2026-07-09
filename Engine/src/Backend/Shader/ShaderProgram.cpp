#include "ShaderProgram.h"

ShaderProgramHandle ShaderProgram::Generate() {
    unsigned int ID { glCreateProgram() };
    std::vector<ShaderType> attachments;
    ShaderUniformTable table = ShaderUniforms::Generate(ID);
    ShaderProgramHandle handle{ ID, attachments, table};
    return handle;
}

void ShaderProgram::Destroy(const ShaderProgramHandle& handle) {
    glDeleteProgram(handle.ID);
}

void ShaderProgram::Bind(const ShaderProgramHandle& handle) {
    glUseProgram(handle.ID);
}

void ShaderProgram::Unbind() {
    glUseProgram(0);
}

void ShaderProgram::AttachShader(ShaderProgramHandle& handle, const ShaderHandle& shader) {
    if(std::find(handle.attachments.begin(), handle.attachments.end(), shader.type) != handle.attachments.end()) {
        std::cerr << "ERROR::SHADER_PROGRAM already has a shader of type: " << Shader::ShaderTypeToString(shader.type) << std::endl;
    }
    handle.attachments.push_back(shader.type);
    glAttachShader(handle.ID, shader.ID);
}

void ShaderProgram::Compile(const ShaderProgramHandle& handle) {
    glLinkProgram(handle.ID);
    CheckLinkErrors(handle);
}

void ShaderProgram::CheckLinkErrors(const ShaderProgramHandle& handle) {
    int success;
    glGetProgramiv(handle.ID, GL_LINK_STATUS, &success);
    char infoLog[SHADER_INFO_LOG_SIZE];
    if(!success) {
        glGetProgramInfoLog(handle.ID, SHADER_INFO_LOG_SIZE, nullptr, infoLog);
        std::cerr << "ERROR::SHADER_PROGRAM linking failed:\n" << infoLog << std::endl;
    }
}

void ShaderProgram::SetBool(ShaderProgramHandle &handle, const std::string &name, bool value) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniform1i(location, (int)value);
}

void ShaderProgram::SetInt(ShaderProgramHandle &handle, const std::string &name, int value) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniform1i(location, value);
}

void ShaderProgram::SetFloat(ShaderProgramHandle &handle, const std::string &name, float value) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniform1f(location, value);
}

void ShaderProgram::SetVec2(ShaderProgramHandle &handle, const std::string &name, const glm::vec2 &value) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniform2fv(location, 1, &value[0]);
}

void ShaderProgram::SetVec2(ShaderProgramHandle &handle, const std::string &name, float x, float y) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniform2f(location, x, y);
}

void ShaderProgram::SetVec3(ShaderProgramHandle &handle, const std::string &name, const glm::vec3 &value) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniform3fv(location, 1, &value[0]);
}

void ShaderProgram::SetVec3(ShaderProgramHandle &handle, const std::string &name, float x, float y, float z) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniform3f(location, x, y, z);
}

void ShaderProgram::SetVec4(ShaderProgramHandle &handle, const std::string &name, const glm::vec4 &value) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniform4fv(location, 1, &value[0]);
}

void ShaderProgram::SetVec4(ShaderProgramHandle &handle, const std::string &name, float x, float y, float z, float w) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniform4f(location, x, y, z, w);
}

void ShaderProgram::SetMat2(ShaderProgramHandle &handle, const std::string &name, const glm::mat2 &mat) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniformMatrix2fv(location, 1, GL_FALSE, &mat[0][0]);
}

void ShaderProgram::SetMat3(ShaderProgramHandle &handle, const std::string &name, const glm::mat3 &mat) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniformMatrix3fv(location, 1, GL_FALSE, &mat[0][0]);
}

void ShaderProgram::SetMat4(ShaderProgramHandle &handle, const std::string &name, const glm::mat4 &mat) {
    int location = ShaderUniforms::GetUniformLocation(handle.table, name);
    glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
}