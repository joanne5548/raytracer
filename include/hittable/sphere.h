#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class sphere : public hittable {
    point3 center;
    double radius;

    public:
        // const point3& is probably used since other calculations depend on the center
        sphere(const point3& center, double radius) : center(center), radius(std::fmax(0, radius)) {}

        /**
         * @brief Calculates t value for intersection of ray r and sphere.
         *        Modifies hit_record rec if t value is between t_min, t_max.
         * @returns true if for t value between t_min and t_max, the ray hits the sphere.
         * Uses discriminant b^2 - 4ac
         */
        bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override {
            point3 r0 = r.origin();
            vec3 r_dir = r.direction();
            vec3 u = center - r0;

            double a = dot(r_dir, r_dir);
            double b = -2 * dot(r_dir, u);
            double c = dot(u, u) - radius * radius;

            double discriminant = b * b - 4.0 * a * c;
            if (discriminant < 0) {
                return false;
            }

            double root;
            // One problem - it always checks for solution t where it's in front of the viewport
            double t_1 = (-b + sqrt(discriminant)) / (2.0 * a);
            double t_2 = (-b - sqrt(discriminant)) / (2.0 * a);
            if (t_1 >= t_min && t_1 <= t_max) {
                root = t_1;
            }
            else if (t_2 >= t_min && t_2 <= t_max) {
                root = t_2;
            }
            else {
                return false;
            }

            rec.intersection = r.at(root);
            rec.normal = unit_vector(rec.intersection - center); // ok sure we will store normalized vector
            rec.t = root;
            
            return true;
        }
};

#endif