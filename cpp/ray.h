#ifndef __RAY_H__
#define __RAY_H__

#include "math/vector.h"

struct Ray
{
    // Ponto de origem do raio (ponteiro, atribuir usando "new": ray.p0 = new Vector3(...))
    Vector3 P;
    // Vetor de direção do raio (ponteiro)
    Vector3 u;

    Ray();
    Ray(const Vector3& P, const Vector3& u);
};


struct RayResponse
{
    // Indica se houve interseção com algum objeto
    bool intersected;
    // O valor de "t" do raio para quando houve interseção.
    // Se tiver acontecido duas interseções (raio entrou e saiu), guarda o menor valor.
    double t;
    // O ponto (x,y,z) da superfície do objeto onde houve a interseção no valor de "t" igual a "t"
    Vector3 Q;
    // O vetor normal do objeto atingido, calculado no ponto de interseção ("Q")
    Vector3 normal;
};

#endif

