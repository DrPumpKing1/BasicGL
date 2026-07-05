#pragma once

#include <vector>

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