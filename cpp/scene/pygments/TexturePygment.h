#ifndef __TEXTUREPYGMENT_H__
#define __TEXTUREPYGMENT_H__

#include "Pygment.h"
#include "../../math/vector.h"
#include <vector>

using namespace std;

/**
 * O pigmento sólido é como se fosse um baldinho de tinta de uma cor.
 * @author fegemo
 */
class TexturePygment : public Pygment {
private:
    string texturePath;
    Vector4 u, v;
    unsigned int imageWidth, imageHeight;
    vector<unsigned char> image;

public:
    TexturePygment(string, Vector4, Vector4);
    virtual ~TexturePygment();    

    virtual Vector3 getColorAt(Vector3);
    virtual string getPygmentName();
};

#endif //__TEXTUREPYGMENT_H__