#ifndef __SOLIDPYGMENTFACTORY_H__
#define __SOLIDPYGMENTFACTORY_H__

#include "PygmentFactory.h"
#include <sstream>

class SolidPygmentFactory : public PygmentFactory
{
public:
    Pygment* setupPygment(stringstream& scanner);
};

#endif // __SOLIDPYGMENTFACTORY_H__
