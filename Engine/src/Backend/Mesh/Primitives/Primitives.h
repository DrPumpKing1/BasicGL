#pragma once

#include <glm/glm.hpp>
#include <concepts>

#include "../Mesh.h"
#include "../VertexConfiguration.h"

template <typename ShapeT>
concept HasConstructMesh = requires (const ShapeT &shape, const VertexConfig &vertexConfig) {
    { shape.ConstructMesh(vertexConfig) } -> std::same_as<MeshData>;
};

template <typename ShapeT>
requires HasConstructMesh<ShapeT>
MeshHandle InstantiateMesh(const ShapeT &shape, const VertexConfig &vertexConfig) {
    MeshData meshData = shape.ConstructMesh(vertexConfig);
    MeshHandle meshHandle = Mesh::Generate(meshData);
    return meshHandle;
};