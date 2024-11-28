#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"
#include "utility.h"
#include "sphere.h"

int main() {
    // Image
    double aspect_ratio = 9.0 / 16.0;
    int image_width = 800;

    int image_height = int(image_width * aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width) / image_height);
    double viewport_ratio = viewport_height / viewport_width;
    point3 camera_center = point3(0, 0, 0);

    // viewport width and height vectors
    vec3 viewport_w = vec3(viewport_width, 0, 0);
    vec3 viewport_h = vec3(0, -viewport_height, 0);

    // define pixel size
    vec3 pixel_delta_w = viewport_w / image_width;
    vec3 pixel_delta_h = viewport_h / image_height;

    // define starting point of the image
    // is this point or vector?? I think it's a vector...
    vec3 viewport_upper_left = camera_center
                                - vec3(0, 0, focal_length) // adjust z coordinate
                                - viewport_w/2 // adjust x coordinate
                                - viewport_h/2; // adjust y coordinate

    // define first pixel center
    // The first pixel center is half pixel sizes away from each edges
    vec3 pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_w + pixel_delta_h);
    point3 sphere_center = point3(0, 0, -1);
    double radius = .5;
    // sphere s1 = sphere(center, radius);

    // Print out the image
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << image_height - j << " " << std::flush;
        for (int i = 0; i < image_width; ++i) {
            vec3 pixel_center = pixel00_loc + i * pixel_delta_w + j * pixel_delta_h;
            
            // defining the ray direction depending on where the camera is!
            vec3 ray_direction = pixel_center - camera_center;

            ray r = ray(camera_center, ray_direction);

            // color pixel_color = ray_color_diagonal_gradient(r, viewport_ratio);
            color pixel_color = color_sphere(sphere_center, radius, r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog  << "\rDone.                 \n";
    
    return 0;
}