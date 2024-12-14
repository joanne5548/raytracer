#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "interval.h"
#include "color.h"
#include "ray.h"
#include "hittable_list.h"

class camera {
    private:
        int image_width, image_height;
        point3 camera_center;
        vec3 pixel_delta_w, pixel_delta_h, pixel00_loc;

        color color_world(const hittable_list& list, const ray& r, color (*background_color)(const ray&));

        point3 choose_pixel(point3 target, int grid_size);

    public:
        void initialize();

        void render(const hittable_list& world, color (*background_color)(const ray&));

        void render_uniform_sampling(const hittable_list& world, color (*background_color)(const ray&), int sample_size);

        void render_stratified_sampling(const hittable_list& world, color (*background_color)(const ray&), int grid_size);
};

#endif