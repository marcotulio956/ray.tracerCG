#include "input.h"
#include "objects/ObjectBuilder.h"
#include "pygments/PygmentBuilder.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

Scene loadSceneFromFile(const string& fileName)
{
    cout << "Carregando arquivo: " << fileName << endl;
    Scene* newScene = new Scene();
    ifstream sceneFile(fileName.c_str());

    // variáveis temporárias para leitura de arquivo
    string line;
    double doubleValues[9];
    string temp;
    stringstream iss;

    //-----------------------------------------------------------------
    // lendo a CÂMERA
    getline(sceneFile, line);
    iss << line;
    iss >> doubleValues[0] >> doubleValues[1] >> doubleValues[2];
    newScene->camera.eye = Vector3(doubleValues);
    iss.clear();

    getline(sceneFile, line);
    iss << line;
    iss >> doubleValues[0] >> doubleValues[1] >> doubleValues[2];
    newScene->camera.target = Vector3(doubleValues);
    iss.clear();

    getline(sceneFile, line);
    iss << line;
    iss >> doubleValues[0] >> doubleValues[1] >> doubleValues[2];
    newScene->camera.up = Vector3(doubleValues);
    iss.clear();

    getline(sceneFile, line);
    iss << line;
    iss >> doubleValues[0];
    newScene->camera.setFovy(doubleValues[0]);
    iss.clear();

    //-----------------------------------------------------------------
    // lendo as FONTES DE LUZ
    getline(sceneFile, line);
    iss << line;
    iss >> (newScene->numLights);
    newScene->lights = new Light[newScene->numLights];
    iss.clear();

    for (int i = 0; i < newScene->numLights; i++)
    {
        newScene->lights[i] = Light();
        // posição
        getline(sceneFile, line);
        iss << line;
        iss >> doubleValues[0] >> doubleValues[1] >> doubleValues[2] >> doubleValues[3] >> doubleValues[4] >> doubleValues[5] >> doubleValues[6] >> doubleValues[7] >> doubleValues[8];
        iss.clear();
        newScene->lights[i].position = Vector3(doubleValues[0], doubleValues[1], doubleValues[2]);
        // cor
        newScene->lights[i].color = Vector3(doubleValues[3], doubleValues[4], doubleValues[5]);
        // atenuação
        newScene->lights[i].constantAttenuation = doubleValues[6];
        newScene->lights[i].linearAttenuation = doubleValues[7];
        newScene->lights[i].quadraticAttenuation = doubleValues[8];
    }

    //-----------------------------------------------------------------
    // lendo os PIGMENTOS
    getline(sceneFile, line);
    iss << line;
    iss >> (newScene->numPygments);
    newScene->pygments = new Pygment*[newScene->numPygments];
    iss.clear();

    for(int i = 0; i < newScene->numPygments; i++)
    {
        Pygment* newPygment = PygmentBuilder::getInstance()->buildFromDescription(sceneFile, newScene);
        newScene->pygments[i] = newPygment;
        
        iss.clear();
    }


    //-----------------------------------------------------------------
    // lendo os MATERIAIS
    getline(sceneFile, line);
    iss << line;
    iss >> newScene->numMaterials;
    newScene->materials = new Material[newScene->numMaterials];
    iss.clear();

    for (int i = 0; i < newScene->numMaterials; i++)
    {
        newScene->materials[i] = Material();
        // coeficientes
        getline(sceneFile, line);
        iss << line;
        iss >> doubleValues[0] >> doubleValues[1] >> doubleValues[2] >> doubleValues[3] >> doubleValues[4] >> doubleValues[5] >> doubleValues[6];
        newScene->materials[i].ambientCoefficient = doubleValues[0];
        newScene->materials[i].diffuseCoefficient = doubleValues[1];
        newScene->materials[i].specularCoefficient = doubleValues[2];
        newScene->materials[i].specularExponent = doubleValues[3];
        newScene->materials[i].reflectionCoefficient = doubleValues[4];
        newScene->materials[i].transmissionCoefficient = doubleValues[5];
        newScene->materials[i].snellCoefficient = doubleValues[6];
        iss.clear();
    }


    //-----------------------------------------------------------------
    // lendo os OBJETOS DA CENA
    getline(sceneFile, line);
    iss << line;
    iss >> newScene->numObjs;
    newScene->objects = new Object*[newScene->numObjs];
    iss.clear();

    for (int i = 0; i < newScene->numObjs; i++)
    {
        Object* newObject = ObjectBuilder::getInstance()->buildFromDescription(sceneFile, newScene);
        newScene->objects[i] = newObject;

        iss.clear();
    }


    // Calcula a base ortonormal da câmera
    newScene->camera.calculateBase();


    newScene->printDebugInfo();

    return *newScene;
}

