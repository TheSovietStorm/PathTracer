//
// Created by Peter Zdankin on 26.03.18.
//

#ifndef PATHTRACER_MATERIAL_HPP
#define PATHTRACER_MATERIAL_HPP

#include <jmorecfg.h>
#include "Point.hpp"

class Material{
private:
    const Point ambient;
    const Point diffuse;
    const Point specular;
    const Point emission;
    bool emits;
    const double exponent;
    const double local;
    const double IOR;
    const bool shadowCaster;
public:
    Material(const Point& _ambient,const Point& _diffuse,const Point& _specular, const Point& _emission, double _exponent):
            ambient(_ambient), diffuse(_diffuse),specular(_specular), emission(_emission), exponent(_exponent), local(1), IOR(0), shadowCaster(true){emits = (_emission - Point()).length() > 0;}
    Material(const Point& _ambient,const Point& _diffuse,const Point& _specular, const Point& _emission, double _exponent, double _local):
            ambient(_ambient), diffuse(_diffuse),specular(_specular), emission(_emission), exponent(_exponent), local(_local), IOR(0), shadowCaster(true){emits = (_emission - Point()).length() > 0;}
    Material(const Point& _ambient,const Point& _diffuse,const Point& _specular, const Point& _emission, double _exponent, double _local, double _IOR):
            ambient(_ambient), diffuse(_diffuse),specular(_specular), emission(_emission), exponent(_exponent), local(_local), IOR(_IOR), shadowCaster(true){emits = (_emission - Point()).length() > 0;}
    Material(const Point& _ambient,const Point& _diffuse,const Point& _specular, const Point& _emission, double _exponent, double _local, boolean _isShadowCaster):
            ambient(_ambient), diffuse(_diffuse),specular(_specular), emission(_emission), exponent(_exponent), local(_local), IOR(0), shadowCaster(_isShadowCaster){emits = (_emission - Point()).length() > 0;}
    double getExponent() const;
    bool isShadowCaster() const;
    bool reflects() const;
    bool refracts() const;
    double getLocalReflectivity() const;
    double getIndexOfRefraction() const;
    const Point& getAmbient() const;
    const Point& getDiffuse() const;
    const Point& getSpecular() const;
    const Point& getEmission() const;
    bool isEmitting() const;
    double getReflectivity(double cosI) const;

};

#endif //PATHTRACER_MATERIAL_HPP
