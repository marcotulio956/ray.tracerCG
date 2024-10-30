#include "TexturePygmentFactory.h"

#include "../../scene/pygments/TexturePygment.h"
#include "../../math/vector.h"

Pygment* TexturePygmentFactory::setupPygment(stringstream& iss)
{
    string name;
    double values[8];
    iss >> name >> values[0] >> values[1] >> values[2] >> values[3] >> values[4] >> values[5] >> values[6] >> values[7];

    return new TexturePygment(
        name,
        Vector4(values+0),
        Vector4(values+4)
    );
}
