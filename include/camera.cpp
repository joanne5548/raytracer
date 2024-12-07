#include "camera.h"

void camera::initialize() {
    // Image
    double aspect_ratio = 9.0 / 16.0;
    image_width = 800;

    image_height = int(image_width * aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width) / image_height);
    double viewport_ratio = viewport_height / viewport_width;
    camera_center = point3(0, 0, 0);

    // viewport width and height vectors
    vec3 viewport_w = vec3(viewport_width, 0, 0);
    vec3 viewport_h = vec3(0, -viewport_height, 0);

    // define pixel size
    pixel_delta_w = viewport_w / image_width;
    pixel_delta_h = viewport_h / image_height;

    // define starting point of the image
    // is this point or vector?? I think it's a vector...
    vec3 viewport_upper_left = camera_center
                                - vec3(0, 0, focal_length) // adjust z coordinate
                                - viewport_w/2 // adjust x coordinate
                                - viewport_h/2; // adjust y coordinate

    // define first pixel center
    // The first pixel center is half pixel sizes away from each edges
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_w + pixel_delta_h);
}

color camera::color_world(const hittable_list& list, const ray& r, color (*background_color)(const ray&)) {
    hit_record rec;
    if (list.hit(r, 0, infinity, rec)) {
        return rgb_mapping(rec.normal);
    }
    else {
        return background_color(r);
    }
}

void camera::render(const hittable_list& world, color (*background_color)(const ray&)) {
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << image_height - j << " " << std::flush;
        for (int i = 0; i < image_width; ++i) {
            vec3 pixel_center = pixel00_loc + i * pixel_delta_w + j * pixel_delta_h;
            
            // defining the ray direction depending on where the camera is!
            vec3 ray_direction = pixel_center - camera_center;

            ray r = ray(camera_center, ray_direction);

            color pixel_color = color_world(world, r, background_color);

            write_color(std::cout, pixel_color);
        }
    }
    std::clog  << "\rDone.                 \n";
}

// I'm a little concerned multiplying pixel_delta.x or y - it assumes other fields are 0!
point3 camera::choose_pixel(point3 target) {
    double x_rand = random_number_generator(-0.5, 0.5) * pixel_delta_w.x();
    double y_rand = random_number_generator(-0.5, 0.5) * pixel_delta_h.y();
    return target + point3(x_rand, y_rand, 0);
}

void camera::render_uniform_sampling(const hittable_list& world, color (*background_color)(const ray&)) {
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << image_height - j << " " << std::flush;
        for (int i = 0; i < image_width; ++i) {
            vec3 pixel_center = pixel00_loc + i * pixel_delta_w + j * pixel_delta_h;
            
            color pixel_color(0, 0, 0);
            for (int j = 0; j < sample_size; ++j) {
                point3 sample_pixel = choose_pixel(pixel_center);

                vec3 ray_direction = sample_pixel - camera_center;
                ray r = ray(camera_center, ray_direction);

                pixel_color += color_world(world, r, background_color);
            }

            write_color(std::cout, pixel_color / sample_size);
        }
    }
    std::clog  << "\rDone.                 \n";
}