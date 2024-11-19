#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
    public:
        point3 intersection;
        vec3 normal;
        // t value where the intersection occurs on ray (intersection = r.at(t))
        // honestly idk why we're storing this
        double t;
};

class hittable {
    public:
        // automatically creates destructor where it calls destructors of all member objects
        virtual ~hittable() = default;

        // =0 at the end indicates pure virtual function. This means:
        // 1. no implementation in base class
        // 2. if a class contains this function, it automatically becomes abstract unless concrete impelmentation is written
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif