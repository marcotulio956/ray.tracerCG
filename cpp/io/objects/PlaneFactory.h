#ifndef __PLANEFACTORY_H__
#define __PLANEFACTORY_H__

#include "ObjectFactory.h"
#include <sstream>

class PlaneFactory : public ObjectFactory
{
public:
    Object* setupObject(stringstream& scanner);
};

#endif // __PLANEFACTORY_H__
