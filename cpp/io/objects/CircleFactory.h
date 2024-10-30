#ifndef __CIRCLEFACTORY_H__
#define __CIRCLEFACTORY_H__

#include "ObjectFactory.h"
#include <sstream>

class CircleFactory : public ObjectFactory
{
public:
    Object* setupObject(stringstream& scanner);
};

#endif // __CIRCLEFACTORY_H__
