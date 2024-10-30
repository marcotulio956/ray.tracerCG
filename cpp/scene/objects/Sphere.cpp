#include "Sphere.h"
#include <limits>
const double TINY = 1E-3;

Sphere::Sphere(Vector3 center, double radius) : Object::Object()
{
    //ctor
    this->center = center;
    this->radius = radius;
}

Sphere::~Sphere()
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
RayResponse Sphere::intersectsWith(Ray& ray)
{
    // Inicia uma resposta com um "intersects" falso,
    // indicando que não houve interseção
    RayResponse response =
    {
        false
    };

    // ------------------------------------------------------------------
    // A primeira parte do TP3 (colisão) deve ser feita neste arquivo.
    // Está sempre retornando que não houve colisão, sem sequer resolver a
    //
    // equação de segundo grau que a verifica. Por isso, a imagem gerada 
    // Você deve implementar este método de forma que ele retorne um
    // não tem nada (apenas cor de fundo).
    // objeto do tipo RayResponse contendo a resposta de colisão
    // dependendo se o raio acerta ou não a esfera    
    return response;
}

Vector3 Sphere::getCenter()
{
    return center;
}

string Sphere::getGeometryName()
{
    return "sphere";
}
