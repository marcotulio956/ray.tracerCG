#include "SolidPygmentFactory.h"

#include "../../scene/pygments/SolidPygment.h"
#include "../../math/vector.h"

Pygment* SolidPygmentFactory::setupPygment(stringstream& iss)
{
    double values[3];
    iss >> values[0] >> values[1] >> values[2];

    return new SolidPygment(Vector3(values));
}
