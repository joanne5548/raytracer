# raytracer

## to run the code, use cmake
### standard way
```cmake -B build``` <br />
--> writes build files using the CMakeLists.txt <br />
```cmake --build build``` <br />
--> creates the executable <br />
<br />
```build/my_executable.exe > image.ppm``` <br />
--> writes the program output to image.ppm

### optimized way
```cmake --build build --config release``` <br />
```build\Release\inOneWeekend.exe > image.ppm``` <br />
(I haven't tried this yet)
