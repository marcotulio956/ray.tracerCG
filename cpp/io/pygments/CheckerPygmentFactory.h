#ifndef __CHECKERPYGMENTFACTORY_H__
#define __CHECKERPYGMENTFACTORY_H__

#include "PygmentFactory.h"
#include <sstream>

class CheckerPygmentFactory : public PygmentFactory
{
public:
    Pygment* setupPygment(stringstream& scanner);
};

#endif // __CHECKERPYGMENTFACTORY_H__
