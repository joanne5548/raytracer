# raytracer

## To run the code, use cmake
### standard way
cmake -B build
--> writes build files using the CMakeLists.txt
cmake --build build
--> creates the executable

build/my_executable.exe > image.ppm
--> writes the program output to image.ppm

### optimized way
cmake --build build --config release
build\Release\inOneWeekend.exe > image.ppm
(I haven't tried this yet)