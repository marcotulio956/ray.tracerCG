#ifndef __OBJECTFACTORY_H__
#define __OBJECTFACTORY_H__

#include <sstream>
#include "../../scene/objects/Object.h"

class ObjectFactory
{
public:
    virtual Object* setupObject(stringstream&) = 0;
};

#endif // __OBJECTFACTORY_H__
