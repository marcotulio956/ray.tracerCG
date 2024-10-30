#ifndef __PYGMENT_H__
#define __PYGMENT_H__

#include <string>
#include "../../math/vector.h"

/**
 * Um pigmento define como um objeto deve ser pintado - como pegar uma cor.
 */
class Pygment
{
public:
    Pygment() {

    }
    virtual ~Pygment() {
        
    }
    
    /**
     * Deve retornar uma cor que deve ser aplicada ao objeto na dada posição.
     * @param position posição tendo sua cor determinada.
     * @return cor.
     */
    virtual Vector3 getColorAt(Vector3) = 0;

    /**
     * Deve retornar o tipo do objeto (eg, "sphere").
     * @return uma string com o formato do objeto. É usado somente para
     * depuração.
     */
    virtual string getPygmentName() = 0;
};

#endif // __PYGMENT_H__
