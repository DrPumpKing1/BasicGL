#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include "Primitives.h"

class Sphere
{
private:
    float radius;
    unsigned int segments;
    unsigned int rings;

public:
    Sphere(float radius, unsigned int segments, unsigned int rings) : radius(radius), segments(segments), rings(rings) {}
    MeshData ConstructMesh(const VertexConfig &vertexConfig) const;
};