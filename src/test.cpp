#include <iostream>
#include "camera.h"
#include "utility.h"
#include "sphere.h"

int main() {
    camera camera;
    camera.initialize();

    hittable_list happyAndPeacefulWorld = hittable_list();
    happyAndPeacefulWorld.add(make_shared<sphere>(sphere(point3(0, 0, -5), 1)));
    happyAndPeacefulWorld.add(make_shared<sphere>(sphere(point3(-0.25, -0.5, -4), 0.5)));
    happyAndPeacefulWorld.add(make_shared<sphere>(sphere(point3(0, -100.5, -5), 100)));

    // camera.render_uniform_sampling(happyAndPeacefulWorld, &ray_color_vertical_gradient);

    vec3 pixel_center = camera.pixel00_loc + 398 * camera.pixel_delta_w + 179 * camera.pixel_delta_h;

    color pixel_color(0, 0, 0);
    for (int sample = 0; sample < 8; ++sample) {
        point3 sample_pixel = camera.choose_pixel(pixel_center);

        vec3 ray_direction = sample_pixel - camera.camera_center;
        ray r_sample = ray(camera.camera_center, ray_direction);

        color sample_color = camera.color_world(happyAndPeacefulWorld, r_sample, &ray_color_vertical_gradient);
        write_color(std::cout, sample_color);
        write_color(std::cout, pixel_color);
        pixel_color += sample_color;
        write_color(std::cout, pixel_color);
    }

    write_color(std::cout, pixel_color / 8);

    std::cout << std::endl;
    color start(0, 0, 0);
    color one(227, 247, 255);
    start += one;
    write_color(std::cout, start);

    color two(124, 255, 135);
    start += two;
    write_color(std::cout, start);
}