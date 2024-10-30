#include "ray.h"

Ray::Ray()
{
}

Ray::Ray(const Vector3& P, const Vector3& u)
{
    this->P = P;
    this->u = u;
    this->u.normalize();
}
