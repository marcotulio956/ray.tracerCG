#ifndef __SPHEREFACTORY_H__
#define __SPHEREFACTORY_H__

#include "ObjectFactory.h"
#include <sstream>

class SphereFactory : public ObjectFactory
{
public:
    Object* setupObject(stringstream& scanner);
};

#endif // __SPHEREFACTORY_H__
