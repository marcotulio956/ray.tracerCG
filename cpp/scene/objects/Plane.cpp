#include "Plane.h"
#include <limits>

Plane::Plane(Vector3 samplePoint, Vector3 normal) : Object::Object()
{
    //ctor
    this->samplePoint = samplePoint;
    this->normal = normal.normalized();
}

Plane::~Plane()
{
    //dtor
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
RayResponse Plane::intersectsWith(Ray& ray)
{
    RayResponse response =
    {
        false
    };

    return response;
}

Vector3 Plane::getCenter()
{
    return samplePoint;
}

string Plane::getGeometryName()
{
    return "plane";
}
