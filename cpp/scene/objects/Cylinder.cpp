#include "Cylinder.h"
#include <limits>
const double TINY = 1E-3;

Cylinder::Cylinder(Vector3 baseCenter, Vector3 direction, double radius, double height) : Object::Object()
{
    //ctor
    this->radius = radius;
    this->baseCenter = baseCenter;
    this->direction = direction.normalized();
    this->topCenter = baseCenter + (this->direction * height);
    this->bottom = new Circle(baseCenter, this->direction * -1, radius);
    this->top = new Circle(topCenter, this->direction, radius);
}

Cylinder::~Cylinder()
{
    //dtor
    delete this->bottom;
    delete this->top;
}

/**
 * *
 * Retorna um objeto do tipo RayResponse com informações sobre uma possível
 * interseção do raio com este objeto (veja o arquivo ray.h com a declaração
 * da struct RayResponse).
 *
 * O objeto response deve preencher os seguintes valores: -
 * response.intersected, true/false indicando se houve interseção ou não -
 * response.t, o valor T do raio (semi-reta) da primeira
 * interseção, caso haja mais que 1 interseção - response.Q,
 * contendo o ponto (x,y,z) de interseção - ray.normal, contendo
 * o vetor normal do objeto no ponto de interseção. A normal deve ser
 * *normalizada* (norma = 1)
 *
 */
RayResponse Cylinder::intersectsWith(Ray& ray)
{
    RayResponse response =
    {
        false
    };

    return response;
}

Vector3 Cylinder::getCenter()
{
    return (this->baseCenter + this->topCenter) * 0.5;
}

string Cylinder::getGeometryName()
{
    return "cylinder";
}
