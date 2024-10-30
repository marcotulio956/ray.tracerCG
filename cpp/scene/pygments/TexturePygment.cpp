#include "TexturePygment.h"
#include "../../lib/lodepng.h"

TexturePygment::TexturePygment(string texturePath, Vector4 u, Vector4 v) {
    // ctor
    this->u = u;
    this->v = v;
    lodepng::decode(this->image, this->imageWidth, this->imageHeight, texturePath);
}

TexturePygment::~TexturePygment() {
    // dtor
}

Vector3 TexturePygment::getColorAt(Vector3 position) {
    Vector4 positionHomogeneous = Vector4(position, 1);
    double s = u.dot(positionHomogeneous);
    double t = v.dot(positionHomogeneous);
    int sInt = ((int)(floor(s * this->imageWidth) + 1000000000 * this->imageWidth) % this->imageWidth);
    int tInt = ((int)(floor(t * this->imageHeight) + 1000000000 * this->imageHeight) % this->imageHeight);

    unsigned char r =  image[4 * tInt * this->imageWidth + 4 * sInt + 0]; 
    unsigned char g =  image[4 * tInt * this->imageWidth + 4 * sInt + 1]; 
    unsigned char b =  image[4 * tInt * this->imageWidth + 4 * sInt + 2]; 
    
    return Vector3(r, g, b).mult(1.0/255);
}

string TexturePygment::getPygmentName() {
    return "texture";
}