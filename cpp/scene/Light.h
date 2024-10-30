#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "../math/vector.h"

class Light
{
public:
    Light();
    // Posição da luz (x,y,z)
    Vector3 position;
    // Cor da luz em (r,g,b)
    Vector3 color;

    // Coeficientes de atenuação da luz de acordo com a distância até o objeto
    double constantAttenuation;
    double linearAttenuation;
    double quadraticAttenuation;
};

#endif // __LIGHT_H__
