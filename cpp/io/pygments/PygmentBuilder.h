#ifndef __PYGMENTBUILDER_H__
#define __PYGMENTBUILDER_H__

#include <map>
#include <string>
#include "PygmentFactory.h"
#include "../../scene/pygments/Pygment.h"
#include "../../scene/Scene.h"

using namespace std;

class PygmentBuilder
{
public:
    static PygmentBuilder* getInstance();
    Pygment* buildFromDescription(ifstream&, Scene*);

private:
    PygmentBuilder();
    static PygmentBuilder* instance;
    map<string, PygmentFactory*> factories;
};

#endif // __PYGMENTBUILDER_H__