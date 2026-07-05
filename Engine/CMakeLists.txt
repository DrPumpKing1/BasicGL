CMAKE_MINIMUM_REQUIRED(VERSION 3.25)
CMAKE_POLICY(SET CMP0072 NEW)

PROJECT(Engine VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

SET(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib)

ADD_LIBRARY(STB_IMAGE "src/stb_image.cpp")
ADD_LIBRARY(GLAD "src/gl.c")
FIND_LIBRARY(GLFW NAMES "glfw3" PATHS ${CMAKE_SOURCE_DIR}/lib REQUIRED)
FIND_LIBRARY(GLM NAMES "glm" PATHS ${CMAKE_SOURCE_DIR}/lib REQUIRED)
FIND_LIBRARY(ASSIMP NAMES "assimp-vc143-mtd" PATHS ${CMAKE_SOURCE_DIR}/lib REQUIRED)

SET(FILESYSTEM 
    "src/Backend/FileSystem/FileReader.h"
    "src/Backend/FileSystem/FileReader.cpp"
)

SET(MESH 
    "src/Backend/Mesh/Primitives/Primitives.h"
    "src/Backend/Mesh/Primitives/Sphere.h"
    "src/Backend/Mesh/Primitives/Sphere.cpp"
    "src/Backend/Mesh/Mesh.h"
    "src/Backend/Mesh/MeshGeneration.h"
    "src/Backend/Mesh/MeshGeneration.cpp"
)

SET(SOURCE 
    ${FILESYSTEM}
    ${MESH}
    "src/main.cpp"
)

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE})

SET(LIBS GLAD STB_IMAGE ${GLM} ${ASSIMP} ${GLFW} opengl32)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${LIBS})

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/includes)