#include "TriangleFactory.h"

#include "../../scene/objects/Object.h"
#include "../../scene/objects/Triangle.h"
#include "../../math/vector.h"

Object* TriangleFactory::setupObject(stringstream& iss)
{
    double values[9];
    iss >> values[0] >> values[1] >> values[2] >> values[3] >> values[4] >> values[5] >> values[6] >> values[7] >> values[8];

    return new Triangle(
        Vector3(values+0),
        Vector3(values+3),
        Vector3(values+6)
    );
}
