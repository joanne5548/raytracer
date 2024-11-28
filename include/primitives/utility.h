#ifndef UTILITY_H
#define UTILITY_H

#include <float.h>
#include "color.h"
#include "ray.h"
#include "hittable_list.h"

color ray_color_vertical_gradient(const ray& r) {
    // normalize dir vector. The components are now in the range of [-1.0, 1.0]
    const vec3& dir_norm = unit_vector(r.direction());

    // Scale y in range from [-1.0, 1.0] to [0.0, 1.0]
    // double x_pos_norm = 0.5 * (dir_norm.x() + 1.0);
    double y_pos_norm = 0.5 * (dir_norm.y() + 1.0);
    // std::cout << y_pos_norm << std::endl;

    // start from yellow, end as pink - top to bottom
    color start_color = color(248, 200, 220); // pink
    color end_color = color(253, 253, 150); // yellow
    return y_pos_norm * start_color + (1 - y_pos_norm) * end_color;
}

color ray_color_diagonal_gradient(const ray& r, double viewport_ratio) {
    // [-1.0, 1.0]
    const vec3& dir_norm = unit_vector(r.direction());

    // From [-1.0, 1.0] to [0.0, 1.0]
    double x_pos_norm = 0.5 * (dir_norm.x() + 1.0);
    double y_pos_norm = 0.5 * (dir_norm.y() + 1.0);
    
    color start_color = color(248, 200, 220); // pink
    color end_color = color(253, 253, 150); // yellow

    if (y_pos_norm > viewport_ratio * x_pos_norm) {
        return start_color * (1 - 0.5 * y_pos_norm) + end_color * (0.5 * x_pos_norm);
    }
    return start_color * (0.5 - 0.5 * y_pos_norm) + end_color * (0.5 + 0.5 * x_pos_norm);
}

/**
 * @returns t value of ray r where the intersection occurs
 * Uses discriminant b^2 - 4ac
 */
double intersection_sphere(const point3& center, double radius, const ray& r) {
    point3 origin = r.origin();
    vec3 dir = r.direction();
    vec3 u = center - origin; // The (C - P0) part

    double a = dot(dir, dir);
    double b = -2 * dot(dir, u);
    double c = dot(u, u) - radius * radius;

    double discriminant = b * b - 4.0 * a * c;
    if (discriminant < 0) {
        return -1.0; // right now this is fine since we don't care about t < 0 ??
    }

    // There could be two solutions in the quadratic root formula
    // +: represents intersection on the front of the sphere
    // -: represents intersection on the back of the sphere
    return (-b + sqrt(discriminant)) / (2.0 * a);
}
color color_sphere(const point3& center, double radius, const ray& r) {
    double t_solution = intersection_sphere(center, radius, r);

    if (t_solution == -1) {
        return ray_color_vertical_gradient(r);
    }

    vec3 intersection = r.at(t_solution);
    vec3 outward_normal = unit_vector(intersection - center); // note each component is [-1, 1] - we need [0, 1] for color mapping
    color rgb_mapping = 0.5 * color(outward_normal.x() + 1, outward_normal.y() + 1, outward_normal.z() + 1);

    return rgb_mapping;
}

color color_hittable_list(const hittable_list& list, const ray& r, hit_record& rec) {
    if (list.hit(r, DBL_MIN, DBL_MAX, rec)) {
        vec3 normal = rec.normal;
        return 0.5 * color(normal.x() + 1, normal.y() + 1, normal.z() + 1);
    }
    else {
        return ray_color_vertical_gradient(r);
    }
}

#endif