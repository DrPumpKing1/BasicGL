#pragma once

#include <vector>
#include <glad/gl.h>

struct AttributeData {
    unsigned int components;
    unsigned int divisor;
};

struct MeshData {
    std::vector<AttributeData> attributes;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
};

struct DrawInfo {
    unsigned int indicesCount;
};

struct MeshHandle {
    unsigned int VBO, VAO, EBO;
    DrawInfo drawInfo;
};

class Mesh
{
public:
    static MeshHandle Generate(const MeshData &mesh);
    static void Destroy(const MeshHandle &handle);

    static void Bind(const MeshHandle &handle);
    static void Unbind();
};