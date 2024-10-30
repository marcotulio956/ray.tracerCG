#include "Triangle.h"
#include <limits>

Triangle::Triangle(Vector3 A, Vector3 B, Vector3 C) : Object::Object()
{
    //ctor
    this->A = A;
    this->B = B;
    this->C = C;

    this->AB = B.diff(A);
    this->AC = C.diff(A);

    this->plane = new Plane(A, AB.cross(AC).normalized());
}

Triangle::~Triangle()
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
RayResponse Triangle::intersectsWith(Ray& ray)
{
    RayResponse response =
    {
        false
    };

    return response;
}

Vector3 Triangle::getCenter()
{
    return this->A.add(this->B).add(this->C).mult(1/3.0);
}

string Triangle::getGeometryName()
{
    return "triangle";
}
