#include "ray.h"

int main() {
    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    int image_height = int(image_width * aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    double viewpoint_height = 2.0;
    double viewpoint_width = viewpoint_height * (double(image_width) / image_height);
}