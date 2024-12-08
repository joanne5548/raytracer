#pragma once
#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

using color = vec3;

inline color rgb_mapping(const point3& point) {
    return 0.5 * color(point + point3(1, 1, 1));
}

/**
 * @brief Parameterized constructor.
 *
 * @param out Outstream object
 * @param pixel_color Color type to be mapped. Both [0, 1] and [0, 255] ranges are supported.
 */
inline void write_color(std::ostream& out, const color& pixel_color) {
    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    int rbyte = int(r * 256);
    int gbyte = int(g * 256);
    int bbyte = int(b * 256);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif