#include <iostream>
#include "vec3.h"
#include "color.h"

int main() {
    int width = 256;
    int height = 256;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    for (int j = 0; j < height; ++j) {
        std::clog << "\rScanlines remaining: " << height - j << " " << std::flush;
        for (int i = 0; i < width; ++i) {
            color pixel_color = color(double(i)/(width-1), double(j)/(height-1), 0);
            // std::cout << double(i)/(width-1) << std::endl;
            write_color(std::cout, pixel_color);
        }
    }

    std::clog  << "\rDone.                 \n";
    
    return 0;
}