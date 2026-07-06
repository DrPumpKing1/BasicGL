#pragma once

#include <glm/glm.hpp>
#include <concepts>

#include "../Mesh.h"
#include "../VertexConfiguration.h"

template <typename ShapeT>
concept HasConstructMesh = requires (ShapeT shape, VertexConfig vertexConfig) {
    { shape.ConstructMesh(vertexConfig) } -> std::same_as<MeshData>;
};

template <typename ShapeT>
requires HasConstructMesh<ShapeT>
MeshHandle InstantiateMesh(const ShapeT &shape, VertexConfig vertexConfig) {
    MeshData meshData = shape.ConstructMesh(vertexConfig);
    MeshHandle meshHandle = MeshGeneration::Generate(meshData);
    return meshHandle;
};