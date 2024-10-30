#ifndef __CHECKERPYGMENT_H__
#define __CHECKERPYGMENT_H__

#include "Pygment.h"
#include "../../math/vector.h"

/**
 * O pigmento sólido é como se fosse um baldinho de tinta de uma cor.
 * @author fegemo
 */
class CheckerPygment : public Pygment {
private:
    Vector3 color1, color2;
    double cubeSize;

public:
    CheckerPygment(Vector3, Vector3, double);
    virtual ~CheckerPygment();    

    virtual Vector3 getColorAt(Vector3);
    virtual string getPygmentName();
};

#endif //__CHECKERPYGMENT_H__