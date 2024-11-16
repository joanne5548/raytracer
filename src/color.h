#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

using color = vec3;

/**
 * @brief Parameterized constructor.
 *
 * @param out Outstream object
 * @param pixel_color Color type to be mapped. Both [0, 1] and [0, 255] ranges are supported.
 */
void write_color(std::ostream& out, const color& pixel_color) {
    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    int rbyte, gbyte, bbyte;
    if (r < 1.0 && g < 1.0 && b < 1.0) {
        rbyte = int(255.999 * r);
        gbyte = int(255.999 * g);
        bbyte = int(255.999 * b);
    }
    else {
        rbyte = r;
        gbyte = g;
        bbyte = b;
    }

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif