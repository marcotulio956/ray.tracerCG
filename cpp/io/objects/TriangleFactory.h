#ifndef __TRIANGLEFACTORY_H__
#define __TRIANGLEFACTORY_H__

#include "ObjectFactory.h"
#include <sstream>

class TriangleFactory : public ObjectFactory
{
public:
    Object* setupObject(stringstream& scanner);
};

#endif // __TRIANGLEFACTORY_H__
