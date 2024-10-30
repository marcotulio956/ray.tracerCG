#ifndef __OBJECTBUILDER_H__
#define __OBJECTBUILDER_H__

#include <map>
#include <string>
#include "ObjectFactory.h"
#include "../../scene/objects/Object.h"
#include "../../scene/Scene.h"

using namespace std;

class ObjectBuilder
{
public:
    static ObjectBuilder* getInstance();
    Object* buildFromDescription(ifstream&, Scene*);

private:
    ObjectBuilder();
    static ObjectBuilder* instance;
    map<string, ObjectFactory*> factories;
};

#endif // __OBJECTBUILDER_H__
