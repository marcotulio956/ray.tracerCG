package raytracer.scene.objects;

import raytracer.Ray;
import raytracer.RayResponse;
import raytracer.math.Constants;
import raytracer.math.Vector3;

/**
 * Uma esfera, que tem uma posição do seu centro e um raio.
 *
 */
public class Sphere extends Object {

    private final Vector3 center;
    private final double radius;

    public Sphere(Vector3 center, double radius) {
        this.center = center;
        this.radius = radius;
    }
    

    /**
     * *
     * Retorna um objeto do tipo RayResponse com informações sobre uma possível
     * interseção do raio com este objeto.
     *
     * O objeto response deve preencher os seguintes valores: 
     * - response.intersected, true/false indicando se houve interseção ou não
     * - response.intersectionT, o valor t do raio da primeira interseção,
     *   caso haja mais que 1 interseção
     * - response.intersectionPoint, contendo o ponto (x,y,z) de interseção
     * - ray.intersectionNormal, contendo o vetor normal do objeto no ponto 
     *   de interseção. A normal deve ser *normalizada* (norma = 1)
     *
     *
     * @param ray o raio sendo lançado.
     * @return objeto com a resposta da colisão.
     */
    @Override
    public RayResponse intersectsWith(Ray ray) {
        RayResponse response = new RayResponse();

        // ------------------------------------------------------------------
        // A primeira parte do TP3 (colisão) deve ser feita neste arquivo.
        //
        // Está sempre retornando que não houve colisão, sem sequer resolver a
        // equação de segundo grau que a verifica. Por isso, a imagem gerada 
        // Você deve implementar este método de forma que ele retorne um
        // não tem nada (apenas cor de fundo).
        // objeto do tipo RayResponse contendo a resposta de colisão
        // dependendo se o raio acerta ou não a esfera
        return response;
    }

    @Override
    public Vector3 getCenter() {
        return center;
    }

    @Override
    public String getGeometryName() {
        return "sphere";
    }
}
