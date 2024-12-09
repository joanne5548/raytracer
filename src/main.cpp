#include <iostream>
#include "camera.h"
#include "utility.h"
#include "sphere.h"

using std::make_shared;
using std::shared_ptr;

int main() {
    camera camera;
    camera.initialize();

    hittable_list happyAndPeacefulWorld = hittable_list();
    happyAndPeacefulWorld.add(make_shared<sphere>(sphere(point3(0, 0, -5), 1)));
    happyAndPeacefulWorld.add(make_shared<sphere>(sphere(point3(-0.25, -0.5, -4), 0.5)));
    happyAndPeacefulWorld.add(make_shared<sphere>(sphere(point3(0, -100.5, -5), 100)));

    camera.render_uniform_sampling(happyAndPeacefulWorld, &ray_color_vertical_gradient, 32);
    
    return 0;
}