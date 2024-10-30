#include "SolidPygment.h"

SolidPygment::SolidPygment(Vector3 color) {
    // ctor
    this->color = color;
}

SolidPygment::~SolidPygment() {
    // dtor
}

Vector3 SolidPygment::getColorAt(Vector3 position) {
    return this->color;
}

string SolidPygment::getPygmentName() {
    return "solid";
}