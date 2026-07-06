#include "ShaderUniformTable.h"

ShaderUniformTable ShaderUniforms::Generate(unsigned int programID) {
    std::unordered_map<std::string, int> uniforms;
    ShaderUniformTable table { programID, uniforms };
    return table;
}

int ShaderUniforms::GetUniformLocation(const ShaderUniformTable &table, const std::string &name){
        auto it = table.uniforms.find(name);
        if(it != table.uniforms.end())
            return it->second;

        int location = glGetUniformLocation(table.programID, name.c_str());
        if(location == -1) {
            std::cout << "WARNING::SHADER_UNIFORM_TABLE doesn't contain uniform with name: " << name << std::endl;
            return;
        }
        table.uniforms[name] = location;
        return location;
}