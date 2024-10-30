#include "scene/Scene.h"
#include "ray.h"

#define RANDOM (((double)rand())/RAND_MAX)

class RayTracer
{

private:
    Vector3 castRay(Scene& scene, Ray& ray);
    Ray generateInitialRay(Camera& camera, double row, double column, const int height, const int width);

public:
    void renderScene(Scene& scene, Vector3**, const int height, const int width);
};
