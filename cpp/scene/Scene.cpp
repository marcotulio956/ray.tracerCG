#include "Scene.h"
#include <string>
#include <iostream>

using namespace std;

void Scene::printDebugInfo()
{
    cout << "Informacoes sobre a cena:" << endl;
    cout << "\tCamera:\n\t\teye: " << this->camera.eye.printDebugInfo()
         << "\n\t\ttarget: " << this->camera.target.printDebugInfo()
         << "\n\t\tup: " << this->camera.up.printDebugInfo()
         << "\n\t\tfovY: " << this->camera.getFovy()
         << endl;
    cout << "\n\tLuzes: " << this->numLights << "\n";
    for (int c = 0; c < this->numLights; c++)
    {
        cout << "\t\tposition: " << this->lights[c].position.printDebugInfo() << "\n";
        cout << "\t\tcolor: " << this->lights[c].color.printDebugInfo() << "\n";
        cout << "\t\tatenuacoes: " << this->lights[c].constantAttenuation << ", " << this->lights[c].linearAttenuation << ", " << this->lights[c].quadraticAttenuation << "\n\n";
    }
    cout << "\n\tPigmentos: " << this->numPygments << "\n";
    for (int c = 0; c < this->numPygments; c++)
    {
        cout << "\t\ttype: " << this->pygments[c]->getPygmentName() << "\n";
    }
    cout << "\n\tMateriais: " << this->numMaterials << "\n";
    for (int c = 0; c < this->numMaterials; c++)
    {
        cout << "\t\tambiente: " << this->materials[c].ambientCoefficient << "\n";
        cout << "\t\tdifuso: " << this->materials[c].diffuseCoefficient << "\n";
        cout << "\t\tespecular: " << this->materials[c].specularCoefficient << "\n";
        cout << "\t\texpoente espec.: " << this->materials[c].specularExponent << "\n";
        cout << "\t\tindice reflex.: " << this->materials[c].reflectionCoefficient << "\n";
        cout << "\t\tindice refrac.: " << this->materials[c].transmissionCoefficient << "\n";
        cout << "\t\tsnell: " << this->materials[c].snellCoefficient << "\n";
    }
    cout << "\n\tObjetos: " << this->numObjs << "\n";
    for (int c = 0; c < this->numObjs; c++)
    {
        cout << "\t\ttype: " << this->objects[c]->getGeometryName() << "\n";
        cout << "\t\tposition: " << this->objects[c]->getCenter().printDebugInfo() << "\n\n";
    }
}

// MÉTODO calcula a base ortonormal da câmera considerando:
//   1. Vetor eye (posição do olho)
//   2. Vetor target (pra onde está olhando)
//   3. Vetor up (vetor "pra cima")
void Camera::calculateBase()
{
    Vector3 targetVector = (this->target - this->eye).normalized() * -1;

    this->cameraBaseZ = Vector3(targetVector);
    this->cameraBaseX = Vector3(this->up.cross(this->cameraBaseZ)).normalized();
    this->cameraBaseY = Vector3(this->cameraBaseZ.cross(this->cameraBaseX));
}

void Camera::setFovy(double inDegrees)
{
    this->fovy = inDegrees * M_PI / 180;
}

double Camera::getFovy()
{
    return this->fovy;
}
