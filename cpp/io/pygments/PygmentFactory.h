#ifndef __PYGMENTFACTORY_H__
#define __PYGMENTFACTORY_H__

#include <sstream>
#include "../../scene/pygments/Pygment.h"

class PygmentFactory {
public:
    virtual Pygment* setupPygment(stringstream&) = 0;
};

#endif // __PYGMENTFACTORY_H__
