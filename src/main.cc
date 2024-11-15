#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"
#include "utility.h"

int main() {
    // Image
    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    int image_height = int(image_width * aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width) / image_height);
    double viewport_ratio = viewport_height / viewport_width;
    auto camera_center = point3(0, 0, 0);

    // viewport width and height vectors
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // define pixel size
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // define starting point of the image
    auto viewport_upper_left = camera_center
                                - vec3(0, 0, focal_length) // adjust z coordinate
                                - viewport_u/2 // adjust x coordinate
                                - viewport_v/2; // adjust y coordinate
    // define first pixel center
    // The first pixel center is half pixel sizes away from each edges
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Print out the image
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << image_height - j << " " << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + i * pixel_delta_u + j * pixel_delta_v;
            
            // defining the ray direction depending on where the camera is!
            auto ray_direction = pixel_center - camera_center;

            ray r = ray(camera_center, ray_direction);

            color pixel_color = ray_color_diagonal_gradient(r, viewport_ratio);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog  << "\rDone.                 \n";
    
    return 0;
}