#ifndef __MATERIAL_H__
#define __MATERIAL_H__


class Material
{
public:
    Material();

    double ambientCoefficient;
    double diffuseCoefficient;
    double specularCoefficient;
    double specularExponent;

    double reflectionCoefficient;
    double transmissionCoefficient;
    double snellCoefficient;
};

#endif // __MATERIAL_H__
