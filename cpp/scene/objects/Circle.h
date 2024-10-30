#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include <string>
#include "../../math/vector.h"
#include "../../ray.h"
#include "Object.h"
#include "Plane.h"

class Circle : public Object
{
private:
    Vector3 center;
    double radius;
    Plane* plane;

public:
    Circle(Vector3, Vector3, double);
    virtual ~Circle();

    RayResponse intersectsWith(Ray& ray);
    Vector3 getCenter();
    string getGeometryName();
};

#endif // __CIRCLE_H__
