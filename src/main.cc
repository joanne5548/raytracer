#include <iostream>

int main() {
    int width = 256;
    int height = 256;

    std::cout << "Sample Image\n" << width << " " << height << "\n255\n";

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            double r = double(i) / (width - 1);
            double g = double(j) / (height - 1);
            double b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << " " << ig << " " << ib << std::endl;
        }
    }

    return 0;
}