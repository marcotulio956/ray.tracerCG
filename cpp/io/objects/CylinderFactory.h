#ifndef __CYLINDERFACTORY_H__
#define __CYLINDERFACTORY_H__

#include "ObjectFactory.h"
#include <sstream>

class CylinderFactory : public ObjectFactory
{
public:
    Object* setupObject(stringstream& scanner);
};

#endif // __CYLINDERFACTORY_H__
