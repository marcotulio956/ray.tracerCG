#include "ObjectBuilder.h"
#include "SphereFactory.h"
#include "PlaneFactory.h"
#include "CircleFactory.h"
#include "TriangleFactory.h"
#include "CylinderFactory.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

ObjectBuilder* ObjectBuilder::instance = nullptr;

ObjectBuilder::ObjectBuilder()
{
    this->factories = map<string, ObjectFactory*>();
    this->factories["sphere"] = new SphereFactory();
    this->factories["plane"] = new PlaneFactory();
    this->factories["circle"] = new CircleFactory();
    this->factories["triangle"] = new TriangleFactory();
    this->factories["cylinder"] = new CylinderFactory();
}

ObjectBuilder* ObjectBuilder::getInstance()
{
    if (instance == 0)
    {
        instance= new ObjectBuilder();
    }
    return instance;
}

Object* ObjectBuilder::buildFromDescription(ifstream& sceneFile, Scene* scene)
{
    string line;
    stringstream iss;
    string type;
    getline(sceneFile, line);
    iss << line;
    int pygmentIndex;
    int materialIndex;
    iss >> pygmentIndex >> materialIndex;
    iss >> type;

    // determina qual fábrica de objetos usar, dado o tipo escrito
    // no arquivo texto. Depois o constrói, deixando-o consumir os
    // parâmetros daquela linha conforme sua fábrica precisa
    // eg, esfera precisa de x, y, z e raio
    // eg, cilindro precisa x, y, z (do centro), altura e raio
    // eg, triângulo precisa de x, y, z de cada vértice
    ObjectFactory* factory = factories[type];
    Object* object = factory->setupObject(iss);

    // propriedades comuns a todos os objetos
    object->pygment = scene->pygments[pygmentIndex];
    object->material = &scene->materials[materialIndex];

    return object;
}
