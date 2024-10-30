#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>
#include "../math/vector.h"
#include "../ray.h"
#include "Light.h"
#include "pygments/Pygment.h"
#include "Material.h"
#include "objects/Object.h"

using namespace std;

struct Camera
{
    Vector3 eye;
    Vector3 target;
    Vector3 up;

    // MÉTODO que calcula a base ortornomal da câmera
    // Ele preenche os vetores cameraBase{X,Y,Z} de acordo com os vetores eye, target e up.
    void calculateBase();

    // base ortonormal da câmera (sistema de coords.)
    Vector3 cameraBaseX;
    Vector3 cameraBaseY;
    Vector3 cameraBaseZ;

    void setFovy(double inDegrees);

    double getFovy();

private:
    double fovy;
};


// A classe Scene contém informações sobre:
//	1. A câmera
//	2. Luzes
//	3. Pigmentos (texturas)
//	4. Acabamentos (materiais)
//	5. Objetos
class Scene
{
public:
    Camera camera;

    int numLights;
    Light* lights;

    int numPygments;
    Pygment** pygments;

    int numMaterials;
    Material* materials;

    int numObjs;
    Object** objects;

    void printDebugInfo();
};

#endif
