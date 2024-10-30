#ifndef __SOLIDPYGMENT_H__
#define __SOLIDPYGMENT_H__

#include "Pygment.h"
#include "../../math/vector.h"

/**
 * O pigmento sólido é como se fosse um baldinho de tinta de uma cor.
 * @author fegemo
 */
class SolidPygment : public Pygment {
private:
    Vector3 color;

public:
    SolidPygment(Vector3);
    virtual ~SolidPygment();    

    virtual Vector3 getColorAt(Vector3);
    virtual string getPygmentName();
};

#endif //__SOLIDPYGMENT_H__