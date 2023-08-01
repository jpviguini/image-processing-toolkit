# Image Processing Toolkit

This is a simple C program for image processing that reads a Portable Graymap (PGM) image, applies various image processing operations, and generates a new modified image.
## Features

The program supports the following image processing operations:

1. Logarithmic Transformation
2. Contrast Stretching
3. Flood Fill (Paintbrush)
4. Exponential Transformation 
5. Image Negative 
6. Mean Filter 
7. Median Filter 


## Getting Started

• Clone the repository to your local machine. <br />
• Compile the C program using a C compiler (e.g., GCC).<br />
• Run the compiled binary.<br />

## Usage

• Upon running the program, you will be prompted to choose an image processing operation from the menu. <br />
• Enter the number corresponding to the desired operation. <br />
• Provide the filename of the PGM image you want to process when prompted. <br />
• The program will perform the selected operation on the input image and generate a new modified PGM image named "img_nova.pgm" in the same directory. <br />

## Input Format

The program supports PGM images in both ASCII and binary formats (P2 and P5, respectively). It automatically detects the format and reads the image accordingly.

## Output Format

The modified image will be generated in the P2 (ASCII) format, regardless of the input format. The output image is saved as "img_nova.pgm" in the same directory.

# Examples
Left image = Original <br />
Right image = Modified
## Logarithm operator
![fusca1](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/188fdfac-44a5-4e28-b1fb-1b32406b9ea7)
![fuscalog](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/2d5c7c37-f1a4-446b-922e-a61a5147e42f)


## Contrast Stretching
![bubbles2](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/901d5ddb-a1c0-4cea-a75a-127e3a276ea0)
![bubblesmod](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/fec2e419-a16e-47c5-8882-ae77f5f19024)


## Floodfill
![folha](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/c92493bf-48b3-433d-abfb-adb4f5af5030)
![folhamod](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/0df3053a-83c6-4abb-9349-34a18ea7600e)

