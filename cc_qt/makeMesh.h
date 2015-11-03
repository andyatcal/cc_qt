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

void makeWithSIF(Mesh &mesh, string inputSIF){
    mesh.vertList.clear();
    mesh.edgeTable.clear();
    mesh.faceList.clear();
    ifstream file(inputSIF);
    if (!file.good()) {
        cout<<"THE PATH OF SIF FILE IS NOT VAILD.";
        exit(1); // exit if file not found
    }
    string nextLine;
    regex anyR(".*(.*).*");
    regex vRegex(".*\(v .*$\).*");
    regex tRegex(".*\(t .*\).*");
    regex lRegex(".*\(loop .*\).*");
    regex shRegex(".*\\(shell.*\).*");
    regex verticesRegex(".*\\(vertices .*\).*");
    int vBeforeMergeCounter = 0;
    int vAfterMergeCounter = 0;
    int IDplusBecauseOfShells = 0;
    vector<vector<int> > boundaries;
    unordered_map<int, int> mapBeforeMergeToAfter;
    int shellNum = 0;
    vector<int> numberOfVerticesInShells;
    while(getline(file, nextLine)){
        nextLine.pop_back();
        if(regex_match(nextLine, vRegex)){
            string temp;
            temp = nextLine.substr(nextLine.find("\("), nextLine.find("\)") - nextLine.find("\("));
            temp = temp.substr(temp.find(" ") + 1);
            float x = stof(temp.substr(0, temp.find(" ")));
            temp = temp.substr(temp.find(" ") + 1);
            float y = stof(temp.substr(0, temp.find(" ")));
            temp = temp.substr(temp.find(" ") + 1);
            float z = stof(temp);
            Vertex * newVert = new Vertex;
            newVert -> position = vec3(x, y, z) * 1.0f; // Can be modifed here to zoom in.
            newVert -> ID = vAfterMergeCounter;
            vector<Vertex*>::iterator vIt;
            bool alreadyAdded = false;
            for (vIt = mesh.vertList.begin(); vIt < mesh.vertList.end(); vIt ++) {
                if(distance(newVert -> position, (*vIt) -> position) < 0.001 ){
                    //cout << "The distance between vertex "<<newVert -> ID<<" and vertex "<<vIt -> second -> ID<<" is: "<<endl;
                    //cout << newVert -> position - (*vIt) -> position<<endl;
                    alreadyAdded = true;
                    mapBeforeMergeToAfter[vBeforeMergeCounter] = (*vIt) -> ID;
                    break;
                }
            }
            //cout<<newVert -> ID<<"Vertex added"<<endl;
            //cout<<"I am mapping "<<vBeforeMergeCounter<<" to "<<vAfterMergeCounter<<endl;
            //mapBeforeMergeToAfter[vBeforeMergeCounter] = vAfterMergeCounter;

            if(!alreadyAdded) {
                newVert -> ID = vAfterMergeCounter;
                mesh.addVertex(newVert);
                mapBeforeMergeToAfter[vBeforeMergeCounter] = vAfterMergeCounter;
                vAfterMergeCounter += 1;
            }
            vBeforeMergeCounter += 1;
        } else if(regex_match(nextLine, tRegex)) {
            string temp;
            temp = nextLine.substr(nextLine.find("\("), nextLine.find("\)") - nextLine.find("\("));
            //cout<<temp<<endl;
            temp = temp.substr(temp.find(" ") + 1);
            int a = stoi(temp.substr(0, temp.find(" ")));
            temp = temp.substr(temp.find(" ") + 1);
            int b = stoi(temp.substr(0, temp.find(" ")));
            temp = temp.substr(temp.find(" ") + 1);
            int c = stoi(temp);
            if(shellNum > 0) {
                vector<int>::iterator vertNumIt;
                IDplusBecauseOfShells = 0;
                for(vertNumIt = numberOfVerticesInShells.begin();
                 vertNumIt < numberOfVerticesInShells.end() - 1; vertNumIt ++) {
                    IDplusBecauseOfShells += *vertNumIt;
                }
            }
            a += IDplusBecauseOfShells;
            b += IDplusBecauseOfShells;
            c += IDplusBecauseOfShells;
            //cout<<"a: "<< a <<" b: "<<b<<" c: "<<c<<endl;
            a = mapBeforeMergeToAfter[a];
            b = mapBeforeMergeToAfter[b];
            c = mapBeforeMergeToAfter[c];
            Vertex * va = mesh.vertList[a];
            Vertex * vb = mesh.vertList[b];
            Vertex * vc = mesh.vertList[c];
            //cout<<va -> ID<<" "<<vb -> ID<<" "<<vc -> ID<<endl;
            mesh.addTriFace(va, vb, vc);
        } else if(regex_match(nextLine, lRegex)){
            vector<int> oneBoundary;
            string temp;
            int nextVert;
            if(shellNum > 1) {
                vector<int>::iterator vertNumIt;
                IDplusBecauseOfShells = 0;
                for(vertNumIt = numberOfVerticesInShells.begin();
                 vertNumIt < numberOfVerticesInShells.end(); vertNumIt ++) {
                    IDplusBecauseOfShells += *vertNumIt;
                }
            }
            temp = nextLine.substr(nextLine.find("\("),
             nextLine.find("\)") - nextLine.find("\("));
            //cout<<temp<<endl;
            temp = temp.substr(temp.find(" ") + 1);
            while(temp.find(" ") != string::npos){
                nextVert = stoi(temp.substr(0, temp.find(" ")));
                oneBoundary.push_back(nextVert + IDplusBecauseOfShells);
                temp = temp.substr(temp.find(" ") + 1);
            }
            nextVert = stoi(temp);
            oneBoundary.push_back(nextVert + IDplusBecauseOfShells);
            boundaries.push_back(oneBoundary);
            //cout<<oneBoundary.size()<<endl;
        } else if(regex_match(nextLine, shRegex)) {
            shellNum += 1;
        } else if(regex_match(nextLine, verticesRegex)){
            string temp;
            temp = nextLine.substr(nextLine.find("\("),
             nextLine.find("\)") - nextLine.find("\("));
            temp = temp.substr(temp.find(" ") + 1);
            int numberOfVerticesInThisShell = stoi(temp);
            numberOfVerticesInShells.push_back(numberOfVerticesInThisShell);
        }
    }
    mesh.buildBoundary();
}

#endif // __MAKEMESH_H__
