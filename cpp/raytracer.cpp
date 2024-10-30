#include "raytracer.h"
#include "math/vector.h"
#include <limits>

#include <iostream>
using namespace std;


// MÉTODO que gera um "raio inicial" (ou primário): aquele que parte do olho (câmera) e passa pelo pixel (i,j)
Ray RayTracer::generateInitialRay(Camera& camera, double row, double column, const int height, const int width)
{
    double aspectRatio = ((double) width) / height;
    double heightInCameraSpace = 2 * tan(camera.getFovy() / 2);
    double widthInCameraSpace = heightInCameraSpace * aspectRatio;

    double ur = heightInCameraSpace * (((double) row) / height) - heightInCameraSpace / 2;
    double uc = widthInCameraSpace * (((double) column) / width) - widthInCameraSpace / 2;

    Vector3 gridPoint = Vector3(camera.eye);
    gridPoint += camera.cameraBaseX * uc;
    gridPoint += camera.cameraBaseY * ur;
    gridPoint -= camera.cameraBaseZ;

    Vector3 direction = gridPoint - camera.eye;

    return Ray(camera.eye, direction.normalized());
}

Vector3 RayTracer::castRay(Scene& scene, Ray& ray)
{
    // Para todos os objetos da cena, verifica se o raio o acerta e pega aquele
    // que foi atingido primeiro (menor "t")
    RayResponse closestIntersection =
    {
        false, numeric_limits<double>::max()
    };
    Object* closestObjectHit = nullptr;
    for (int c = 0; c < scene.numObjs; c++)
    {
        Object* currentObject = scene.objects[c];
        RayResponse response = currentObject->intersectsWith(ray);
        if (response.intersected)
        {
            if (response.t < closestIntersection.t)
            {
                closestIntersection = response;
                closestObjectHit = currentObject;
            }
        }
    }


    // Verifica se um objeto foi atingido. Se tiver sido, colore o pixel
    if (closestObjectHit != nullptr)
    {
        // material e pigmento deste objeto
        Material* material= closestObjectHit->material;
        Pygment* pygment = closestObjectHit->pygment;
        Vector3 color = pygment->getColorAt(closestIntersection.Q);
        
        // Esta é a variável contendo a COR RESULTANTE do pixel,
        // que deve ser devidamente calculada e retornada ao final
        // deste método (castRay)
        Vector3 shadingColor = color;

        //------------------------------------------------------------------
        // A segunda parte do TP3 (sombreamento) deve ser feita neste arquivo.
        //
        // Aqui começamos a implementar a equaçăo de Phong (e armazenar o
        //   resultado parcial em shadingColor)
        // Sugiro seguir as anotaçőes do prof. David Mount (p. 83)
        // ---
        // Exercício 1: Coloque a componente ambiente na cor resultante
        // luz ambiente: coefAmbienteDaLuz*corDoPigmento


        // Um objeto foi atingido
        // Verificamos se as fontes de luz estão iluminando este objeto
        for (int c = 0; c < scene.numLights; c++)
        {
            Light* light = &(scene.lights[c]);
            // Para verificar,
            // ---
            // Exercício 2: crie um raio do ponto de interseção com o
            //   objeto até a fonte de luz (basta instanciar devidamente
            //   um Ray, ~4 linhas)





            // Verificamos se o raio atinge algum objeto ANTES da fonte de luz
            // Se for o caso, esta fonte de luz não contribui para a luz do objeto
            bool hitsAnotherObjectBeforeLight = false;

            // ---
            // Exercício 3: Percorra os objetos da cena verificando se
            //   houve interseção com eles, antes da interseção com a fonte luminosa
            // Salve essa informação na variável hitsAnotherObjectBeforeLight (~10 linhas)
          
          







            if (!hitsAnotherObjectBeforeLight)
            {
                // ---
                // Exercício 4: Devemos terminar de calcular a equaçăo
                //   de Phong (atenuação, componente difusa e componente
                //   especular) e somar o resultado na cor resultante
                //   (na variável shadingColor, ~15 linhas)
                // cor = (corDaLuz/atenuacao) * (coefDifusoMat*corDoMat*max(0, raioLuz . normal) + (coefEspecularLuz*max(0, normal . halfway)^expoenteEspecularMat))












            }
        }

        // [Extra] Exercício 5: se o material for reflexivo, lançar raio de reflexão
        //                      chamando castRay recursivamente




        
        // [Extra] Exercício 5: se o material for transparente, lançar raio de refração
        //                      chamando castRay recursivamente





        // trunca a cor: faz r, g e b ficarem entre 0 e 1, caso tenha excedido
        shadingColor.truncate();

        return shadingColor;
    }

    // nada foi atingido. Retorna uma cor padrão (de fundo)
    return Vector3(0, 0, 1);
}

// MÉTODO que renderiza uma cena, gerando uma matriz de cores.
// Parâmetros:
//   1. Scene& scene: um objeto do tipo Scene contendo a descrição da cena (ver scene.h)
//   2. Vector3** pixels: uma matriz de cores (representadas em Vector3 - r,g,b) que vamos "colorir"
//   3. const int height: altura da imagem que estamos gerando (e.g., 600px)
//   4. const int width: largura da imagem que estamos gerando (e.g., 800px)
void RayTracer::renderScene(Scene& scene, Vector3** pixels, const int height, const int width)
{

    // Para cada pixel, lança um raio
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // cria um raio primário
            Ray ray = generateInitialRay(scene.camera, i, j, height, width);

            // lança o raio e recebe a cor
            Vector3 color = this->castRay(scene, ray);

            // salva a cor na matriz de cores
            pixels[i][j] = color;
        }
    }
}
