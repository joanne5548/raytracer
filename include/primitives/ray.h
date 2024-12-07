#pragma once
#ifndef RAY_H
#define RAY_H

#include "vec3.h"

/**
 * @class ray
 *
 * This class represents a ray with origin (point3) and direction (vec3):
 * R(t) = orig + t * dir
 * It implements a function at(t) to return the point where t = certain value
 *
 * @see vec3
 * @see point3
 */
class ray {
    point3 orig;
    vec3 dir;

    public:
        ray() {}

        ray(const vec3& origin, const vec3& direction) : orig(origin), dir(direction) {}

        const point3& origin() const { return orig; }
        const vec3& direction() const { return dir; }

        point3 at(double t) const {
            return orig + t * dir;
        }

};

#endif