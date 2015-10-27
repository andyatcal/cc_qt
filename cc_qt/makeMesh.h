// 
// @author Andy Wang, UC Berkeley. Copyright 2015 reserve.
// Catmull-Clark subdivision project in order to create sculptures like Eva-Hilds.
// Advised by Prof. Sequin H. Carlos.
// 
//

#ifndef __MAKEMESH_H__
#define __MAKEMESH_H__

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

using namespace glm;
using namespace std;

//////////////////////////////////////////////////////////////////////
// MeshUtils Class -- Utility Functions with Mesh.

void makeCube(Mesh &mesh, float x, float y, float z) {
    mesh.vertList.clear();
    mesh.edgeTable.clear();
    mesh.faceList.clear();
    //make new mesh
    Vertex * v1 = new Vertex;
    Vertex * v2 = new Vertex;
    Vertex * v3 = new Vertex;
    Vertex * v4 = new Vertex;
    Vertex * v5 = new Vertex;
    Vertex * v6 = new Vertex;
    Vertex * v7 = new Vertex;
    Vertex * v8 = new Vertex;

    v1 -> position = vec3(x, y, z);
    v2 -> position = vec3(x, -y, z);
    v3 -> position = vec3(-x, -y, z);
    v4 -> position = vec3(-x, y, z);
    v5 -> position = vec3(x, y, -z);
    v6 -> position = vec3(x, -y, -z);
    v7 -> position = vec3(-x, -y, -z);
    v8 -> position = vec3(-x, y, -z);

    v1 -> ID = 0;
    v2 -> ID = 1;
    v3 -> ID = 2;
    v4 -> ID = 3;
    v5 -> ID = 4;
    v6 -> ID = 5;
    v7 -> ID = 6;
    v8 -> ID = 7;

    //push on all new verts
    mesh.addVertex(v1);
    mesh.addVertex(v2);
    mesh.addVertex(v3);
    mesh.addVertex(v4);
    mesh.addVertex(v5);
    mesh.addVertex(v6);
    mesh.addVertex(v7);
    mesh.addVertex(v8);

    //topFace
    mesh.addQuadFace(v1, v2, v3, v4);
    //bottomFace
    mesh.addQuadFace(v6, v5, v8, v7);
    //leftFace
    mesh.addQuadFace(v3, v2, v6, v7);
    //rightFace
    mesh.addQuadFace(v1, v4, v8, v5);
    //frontFace
    mesh.addQuadFace(v2, v1, v5, v6);
    //baceFace
    mesh.addQuadFace(v4, v3, v7, v8);
    mesh.buildBoundary();
}

#endif // __MAKEMESH_H__
