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

Full explanation of each operation can be found here: https://homepages.inf.ed.ac.uk/rbf/HIPR2/wksheets.htm

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
![fusca1](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/01d7f9df-bccc-4e95-8912-8cc758ed216e)
![fuscalog](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/2517f4a7-f417-4339-9dcc-d67b1e8ee4cd)


## Contrast Stretching
![bubbles2](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/302efdc3-a3d4-4b58-a6cd-d4d6eff66111)
![bubblesmod](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/45ea4722-5adf-4e4f-86dd-e999c74fb4ac)


## Floodfill
![folha](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/d49aacfa-b43f-4c82-a3a5-c27833c262b0)
![folhamod](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/2e26e250-1e84-4740-b23c-a56713c13e9f)


## Aknowledgements
This is an extended version of the final project from the discipline Introduction do Computer Science (SCC-221) at the Institute of Mathematics and Computer Science (University of São Paulo).
