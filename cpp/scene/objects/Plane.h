#ifndef __PLANE_H__
#define __PLANE_H__

#include <string>
#include "../../math/vector.h"
#include "../../ray.h"
#include "Object.h"

class Plane : public Object
{
private:
    Vector3 samplePoint;
    Vector3 normal;

public:
    Plane(Vector3, Vector3);
    virtual ~Plane();

    RayResponse intersectsWith(Ray& ray);
    Vector3 getCenter();
    string getGeometryName();
};

#endif // __PLANE_H__
