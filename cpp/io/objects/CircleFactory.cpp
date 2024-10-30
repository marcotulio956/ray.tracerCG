#include "CircleFactory.h"

#include "../../scene/objects/Object.h"
#include "../../scene/objects/Circle.h"
#include "../../math/vector.h"

Object* CircleFactory::setupObject(stringstream& iss)
{
    double values[7];
    iss >> values[0] >> values[1] >> values[2] >> values[3] >> values[4] >> values[5] >> values[6];

    return new Circle(
        Vector3(values+0),
        Vector3(values+3),
        values[6]
    );
}
