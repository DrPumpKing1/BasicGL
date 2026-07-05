#pragma once

#include <glad/gl.h>
#include <vector>

#include "Mesh.h"

class MeshGeneration 
{
public:
    static MeshHandle Generate(const MeshData& mesh);
    static void Destroy(const MeshHandle& handle);
};