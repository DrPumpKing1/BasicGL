#include "MeshGeneration.h"

MeshHandle MeshGeneration::Generate(const MeshData& mesh) {
    unsigned int VBO, VAO, EBO;
    // Buffers Generation
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    // Vertex Buffer Object
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(float), mesh.vertices.data(), GL_STATIC_DRAW);

    // Element Buffer Object
    if(!mesh.indices.empty()) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(unsigned int), mesh.indices.data(), GL_STATIC_DRAW);
    }

    // Vertex Array Object
    unsigned int stride {0}, offset {0};
    for(const auto &attribute : mesh.attributes) {
        stride += attribute.components;
    }
    size_t i {0};
    for(const auto &attribute : mesh.attributes) {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, attribute.components, GL_FLOAT, GL_FALSE, sizeof(float) * stride, (void *)(offset * sizeof(float)));
        glVertexAttribDivisor(i, attribute.divisor);

        offset += attribute.components;
        i++;
    }

    // Unbinding
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return MeshHandle { VBO, VAO, EBO };
}

void MeshGeneration::Destroy(const MeshHandle& handle) {
    glDeleteVertexArrays(1, &handle.VAO);
    glDeleteBuffers(1, &handle.VBO);
    glDeleteBuffers(1, &handle.EBO);
}