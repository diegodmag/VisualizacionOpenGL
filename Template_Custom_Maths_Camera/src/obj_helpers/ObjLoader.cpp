#include "obj_helpers/ObjLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>


int resolveIndex(int idx, int size) {
    if (idx > 0) {
        return idx - 1; 
    } else {
        return size + idx; 
    }
}

ObjLoader::ObjLoader() {}

void ObjLoader::parseOBJ(const char *filePath) {
    float x, y, z;
    std::ifstream fileStream(filePath, std::ios::in);
    if (!fileStream) {
        std::cerr << "PROBLEM OPENING THE OBJ FILE" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(fileStream, line)) {
        if (line.compare(0, 2, "v ") == 0) { // vértices
            std::stringstream ss(line.erase(0, 2)); //Se borra el "v " y 
            // los únicos datos restantes son los numeros
            ss >> x >> y >> z; // Lee los numeros como floats consecutivos 
            // De la string ss extraemos el primer numero y lo almacenamos en x 
            // el siguiente numero y se almacena en y .. 
            vertVals.push_back(x);
            vertVals.push_back(y);
            vertVals.push_back(z);
        }
        else if (line.compare(0, 3, "vt ") == 0) { // coordenadas de textura
            std::stringstream ss(line.erase(0, 3));
            ss >> x >> y;
            stVals.push_back(x);
            stVals.push_back(y);
        }
        else if (line.compare(0, 3, "vn ") == 0) { // normales
            std::stringstream ss(line.erase(0, 3));
            ss >> x >> y >> z;
            normVals.push_back(x);
            normVals.push_back(y);
            normVals.push_back(z);
        }
        else if (line.compare(0, 2, "f ") == 0) { // caras
            std::stringstream ss(line.erase(0, 2));
            std::string oneCorner, v, t, n;

            // Este while se va a ejecutar 3 veces 
            while (std::getline(ss, oneCorner, ' ')) { //Se leela linea hasta que se encuentra espacio
                if (oneCorner.empty()) continue;

                // Por qué funciona ? 
                // std::getline tiene un puntero interno que recuerda dónde se quedó la última vez que leyó la cadena

                std::stringstream oneCornerSS(oneCorner);
                std::getline(oneCornerSS, v, '/'); // guarda en v 
                std::getline(oneCornerSS, t, '/'); // guarda en t
                std::getline(oneCornerSS, n, '/');

                // v = 2; t=1 n= 1 <- No esta en formato c++     

                // índices (pueden ser negativos) por lo que se usa la funcion resolveIndex
                int vIndex = resolveIndex(std::stoi(v), vertVals.size() / 3);
                int tIndex = (!t.empty()) ? resolveIndex(std::stoi(t), stVals.size() / 2) : -1;
                int nIndex = (!n.empty()) ? resolveIndex(std::stoi(n), normVals.size() / 3) : -1;


                
                // agregar vértices
                triangleVerts.push_back(vertVals[vIndex * 3]);
                triangleVerts.push_back(vertVals[vIndex * 3 + 1]);
                triangleVerts.push_back(vertVals[vIndex * 3 + 2]);
                    //vect vertices
                    //vect textcoords
                    //vect normales
                // agregar texcoords si existen
                if (tIndex >= 0) {
                    textureCoords.push_back(stVals[tIndex * 2]);
                    textureCoords.push_back(stVals[tIndex * 2 + 1]);
                } else {
                    textureCoords.push_back(0.0f);
                    textureCoords.push_back(0.0f);
                }

                // agregar normales si existen
                if (nIndex >= 0) {
                    normals.push_back(normVals[nIndex * 3]);
                    normals.push_back(normVals[nIndex * 3 + 1]);
                    normals.push_back(normVals[nIndex * 3 + 2]);
                } else {
                    normals.push_back(0.0f);
                    normals.push_back(0.0f);
                    normals.push_back(0.0f);
                }
            }
        }
    }
}

// getters
int ObjLoader::getNumVertices() { return (triangleVerts.size() / 3); }
std::vector<float> ObjLoader::getVertices() { return triangleVerts; }
std::vector<float> ObjLoader::getTextureCoordinates() { return textureCoords; }
std::vector<float> ObjLoader::getNormals() { return normals; }
