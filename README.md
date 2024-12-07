# raytracer

### How to run the code
Cmake was used to compile C++ code
At the root directory, run `./generate.sh` <br />
It automatically generates the sample image in PPM format in `sample_images` directory <br />

### How to view PPM image files
I use the website [PPM Viewer](https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html) <br />
The VSCode extension [PBM/PPM/PGM Viewer for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ngtystr.ppm-pgm-viewer-for-vscode) is also useful <br />

### Sample Image (work in progress)
![Vertical gradient, pink to yellow](/sample_images/previous/sphere_minus.png)

### To-Do
1. Identify if my implementation of random sampling is wrong
2. Check if clamping function is needed
3. Reorganize the header files by separating the function definitions into cpp file