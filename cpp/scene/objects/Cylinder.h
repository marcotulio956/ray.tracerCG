#ifndef __CYLINDER_H__
#define __CYLINDER_H__

#include <string>
#include "../../math/vector.h"
#include "../../ray.h"
#include "Object.h"
#include "Circle.h"

class Cylinder : public Object
{
private:
    Vector3 baseCenter, topCenter;
    Vector3 direction;
    double radius;
    Circle *bottom, *top;

public:
    Cylinder(Vector3, Vector3, double, double);
    virtual ~Cylinder();

    RayResponse intersectsWith(Ray& ray);
    Vector3 getCenter();
    string getGeometryName();
};

#endif // __CYLINDER_H__
