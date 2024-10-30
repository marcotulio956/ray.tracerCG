#include "CheckerPygment.h"

CheckerPygment::CheckerPygment(Vector3 color1, Vector3 color2, double cubeSize) {
    // ctor
    this->color1 = color1;
    this->color2 = color2;
    this->cubeSize = cubeSize;
}

CheckerPygment::~CheckerPygment() {
    // dtor
}

Vector3 CheckerPygment::getColorAt(Vector3 position) {
    double x = floor(position.x / cubeSize); 
    double y = floor(position.y / cubeSize); 
    double z = floor(position.z / cubeSize); 
    return ((int)(x+y+z) % 2) == 0 ? color1 : color2;
}

string CheckerPygment::getPygmentName() {
    return "checker";
}