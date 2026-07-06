#pragma once

#include <vector>
#include <glad/gl.h>

struct AttributeData {
    unsigned int components;
    unsigned int divisor;
};

struct MeshData {
    const std::vector<AttributeData> &attributes;
    const std::vector<float> &vertices;
    const std::vector<unsigned int> &indices;
};

struct MeshHandle {
    unsigned int VBO, VAO, EBO;
};

class Mesh
{
public:
    static MeshHandle Generate(const MeshData &mesh);
    static void Destroy(const MeshHandle &handle);
};