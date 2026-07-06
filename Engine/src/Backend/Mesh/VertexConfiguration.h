#pragma once

#include <vector>

#include "Mesh.h"

enum class VertexAttributeType {
    POSITION2D,
    POSITION3D,
    TEXCOORD,
    NORMAL,
    TANGENT,
    BITANGENT,
};

using VertexConfig = std::vector<VertexAttributeType>;

const VertexConfig Vertex2D = {
    VertexAttributeType::POSITION2D,
    VertexAttributeType::TEXCOORD,
};

const VertexConfig Vertex3DUnlit = {
    VertexAttributeType::POSITION3D,
    VertexAttributeType::TEXCOORD,
};

const VertexConfig Vertex3DLit = {
    VertexAttributeType::POSITION3D,
    VertexAttributeType::TEXCOORD,
    VertexAttributeType::NORMAL,
};

const VertexConfig Vertex3DTangent = {
    VertexAttributeType::POSITION3D,
    VertexAttributeType::TEXCOORD,
    VertexAttributeType::NORMAL,
    VertexAttributeType::TANGENT,
    VertexAttributeType::BITANGENT,
};

class VertexConfigUtils {
public:
    static void SetAttributeData(std::vector<AttributeData> &attribData, VertexConfig vertexConfig) {
        int length = vertexConfig.size();
        attribData = std::vector<AttributeData>(vertexConfig.size());
        for(int i = 0; i < length; i++) {
            unsigned int components = GetComponentsOfAttributeType(vertexConfig[i]);
            attribData[i] = AttributeData{ components, 0 };
        }
    }
private:
    static unsigned int GetComponentsOfAttributeType(VertexAttributeType attribType) {
        switch (attribType)
        {
        case VertexAttributeType::POSITION3D:
        case VertexAttributeType::NORMAL:
        case VertexAttributeType::TANGENT:
        case VertexAttributeType::BITANGENT:
            return 3;
        case VertexAttributeType::TEXCOORD:
        case VertexAttributeType::POSITION2D:
            return 2;

        default:
            return 0;
        }
    }
}