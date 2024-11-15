#ifndef UTILITY_H
#define UTILITY_H

#include "color.h"
#include "ray.h"

class utility{
    public:
        static color ray_color_vertical_gradient(const ray& r);
        static color ray_color_diagonal_gradient(const ray& r, double viewport_ratio);
};

static color ray_color_vertical_gradient(const ray& r) {
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

static color ray_color_diagonal_gradient(const ray& r, double viewport_ratio) {
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

#endif