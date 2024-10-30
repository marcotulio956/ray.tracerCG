#include "SphereFactory.h"

#include "../../scene/objects/Object.h"
#include "../../scene/objects/Sphere.h"
#include "../../math/vector.h"

Object* SphereFactory::setupObject(stringstream& iss)
{
    double values[4];
    iss >> values[0] >> values[1] >> values[2] >> values[3];

    return new Sphere(Vector3(values), values[3]);
}
