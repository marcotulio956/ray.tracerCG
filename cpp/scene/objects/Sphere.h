#ifndef __SPHERE_H__
#define __SPHERE_H__

#include <string>
#include "../../math/vector.h"
#include "../../ray.h"
#include "Object.h"

class Sphere : public Object
{
private:
    Vector3 center;
    double radius;

public:
    Sphere(Vector3, double);
    virtual ~Sphere();

    RayResponse intersectsWith(Ray& ray);
    Vector3 getCenter();
    string getGeometryName();
};

#endif // __SPHERE_H__
