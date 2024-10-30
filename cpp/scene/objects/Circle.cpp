#include "Circle.h"

Circle::Circle(Vector3 center, Vector3 normal, double radius) : Object::Object()
{
    //ctor
    this->center = center;
    this->radius = radius;
    this->plane = new Plane(center, normal);

}

Circle::~Circle()
{
    //dtor
    delete this->plane;
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
RayResponse Circle::intersectsWith(Ray& ray)
{
    RayResponse response =
    {
        false
    };

    return response;
}

Vector3 Circle::getCenter()
{
    return this->center;
}

string Circle::getGeometryName()
{
    return "circle";
}
