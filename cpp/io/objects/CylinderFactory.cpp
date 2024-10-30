#include "CylinderFactory.h"

#include "../../scene/objects/Object.h"
#include "../../scene/objects/Cylinder.h"
#include "../../math/vector.h"

Object* CylinderFactory::setupObject(stringstream& iss)
{
    double values[8];
    iss >> values[0] >> values[1] >> values[2] >> values[3] >> values[4] >> values[5] >> values[6] >> values[7];

    return new Cylinder(
        Vector3(values+0),
        Vector3(values+3),
        values[6],
        values[7]
    );
}
