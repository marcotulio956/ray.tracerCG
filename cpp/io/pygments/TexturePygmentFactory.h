#ifndef __TEXTUREPYGMENTFACTORY_H__
#define __TEXTUREPYGMENTFACTORY_H__

#include "PygmentFactory.h"
#include <sstream>

class TexturePygmentFactory : public PygmentFactory
{
public:
    Pygment* setupPygment(stringstream& scanner);
};

#endif // __TEXTUREPYGMENTFACTORY_H__
