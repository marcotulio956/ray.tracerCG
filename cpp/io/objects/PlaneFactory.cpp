#include "PlaneFactory.h"

#include "../../scene/objects/Object.h"
#include "../../scene/objects/Plane.h"
#include "../../math/vector.h"

Object* PlaneFactory::setupObject(stringstream& iss)
{
    double values[6];
    iss >> values[0] >> values[1] >> values[2] >> values[3] >> values[4] >> values[5];

    return new Plane(
        Vector3(values+0),
        Vector3(values+3)
    );
}
