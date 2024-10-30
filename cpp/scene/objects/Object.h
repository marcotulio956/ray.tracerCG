#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>
#include "../pygments/Pygment.h"
#include "../Material.h"
#include "../../math/vector.h"
#include "../../ray.h"

class Object
{
public:
    Object() {

    }
    virtual ~Object() {
        
    }

    Pygment* pygment;
    Material* material;

    /**
     *
     * Retorna **true** se o objeto tem interseção com o raio ou **false**, do
     * contrário.
     *
     * Além do valor retornado, caso exista interseção, este método preenche
     * _ray_ com informações cosbre o ponto de colisão: - ray.Q,
     * contendo o ponto (x,y,z) de interseção - ray.normal, contendo
     * o vetor normal do objeto no ponto de interseção. A normal deve ser
     * **normalizada** (norma = 1)
     *
     * @param ray
     * @return
     */
    virtual RayResponse intersectsWith(Ray& ray) = 0;

    /**
     * Deve retornar uma posição representando o centróide do objeto.
     * Este método é usado apenas para depuração.
     * @return uma posição com o centróide do objeto.
     */
    virtual Vector3 getCenter() = 0;

    /**
     * Deve retornar o tipo do objeto (eg, "sphere").
     * @return uma string com o formato do objeto. É usado somente para
     * depuração.
     */
    virtual string getGeometryName() = 0;

};

#endif // __OBJECT_H__
