#include "PygmentBuilder.h"
#include "SolidPygmentFactory.h"
#include "CheckerPygmentFactory.h"
#include "TexturePygmentFactory.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

PygmentBuilder* PygmentBuilder::instance = nullptr;

PygmentBuilder::PygmentBuilder()
{
    this->factories = map<string, PygmentFactory*>();
    this->factories["solid"] = new SolidPygmentFactory();
    this->factories["checker"] = new CheckerPygmentFactory();
    this->factories["texture"] = new TexturePygmentFactory();
}

PygmentBuilder* PygmentBuilder::getInstance()
{
    if (instance == 0)
    {
        instance = new PygmentBuilder();
    }
    return instance;
}

Pygment* PygmentBuilder::buildFromDescription(ifstream& sceneFile, Scene* scene)
{
    string line;
    stringstream iss;
    string type;
    getline(sceneFile, line);
    iss << line;
    iss >> type;

    // determina qual fábrica de pigmentos usar, dado o tipo escrito
    // no arquivo texto. Depois o constrói, deixando-o consumir os
    // parâmetros daquela linha conforme sua fábrica precisa
    PygmentFactory* factory = factories[type];

    return factory->setupPygment(iss);
}
