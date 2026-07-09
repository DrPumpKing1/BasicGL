#pragma once

#include <glad/gl.h>
#include <iostream>
#include <string>
#include <unordered_map>

struct ShaderUniformTable {
    unsigned int programID;
    std::unordered_map<std::string, int> uniforms;
};

class ShaderUniforms
{
public:
    static ShaderUniformTable Generate(unsigned int programID);
    static int GetUniformLocation(ShaderUniformTable &table, const std::string &name);
};