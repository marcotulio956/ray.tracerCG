#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <string>
#include "../../math/vector.h"
#include "../../ray.h"
#include "Object.h"
#include "Plane.h"

class Triangle : public Object
{
private:
    Vector3 A, B, C;
    Vector3 AB, AC;
    Plane* plane;

public:
    Triangle(Vector3, Vector3, Vector3);
    virtual ~Triangle();

    RayResponse intersectsWith(Ray& ray);
    Vector3 getCenter();
    string getGeometryName();
};

#endif // __TRIANGLE_H__
