# raytracer

### How to run the code
Cmake was used to compile C++ code
At the root directory, run `./generate.sh` <br />
It automatically generates the sample image in PPM format in `sample_images` directory <br />
Note: the script `./test.sh` is used for debugging purposes

### How to view PPM image files
I use the VSCode extension [PBM/PPM/PGM Viewer for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ngtystr.ppm-pgm-viewer-for-vscode). <br />
The website [PPM Viewer](https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html) is also useful. <br />

### Sample Images (work in progress)
![Vertical gradient, pink to yellow](/sample_images/previous/sphere_minus.png) <br />
Before Uniform Sampling            |  After Uniform Sampling (n=32)
:-------------------------:|:-------------------------:
![before sampling](/sample_images/readme/before%20sampling.png)  |  ![after sampling](/sample_images/readme/after%20sampling.png)

### To-Do
~~1. Identify if my implementation of random sampling is wrong~~ &#8594; my sampling was correct <br />
~~2. Check if clamping function is needed~~ &#8594; it wasn't needed <br />
**Turns out my write_color function mixed up conversion between [0.0, 1.0] and [0.0, 256.0] during color addition!** <br />
3. Reorganize the header files by separating the function definitions into cpp file