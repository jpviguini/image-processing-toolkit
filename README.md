# Image Processing Toolkit

This is a simple C program for image processing that reads a Portable Graymap (PGM) image, applies various image processing operations, and generates a new modified image.
## Features

The program supports the following image processing operations:

1. Logarithmic Transformation
2. Contrast Stretching
3. Flood Fill (Paintbrush)
4. Exponential Transformation (Optional)
5. Image Negative (Optional)
6. Mean Filter (Optional)
7. Median Filter (Optional)


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

# A few examples
Left image = Original |
Right image = M
## Logarithm operator
![image](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/16d34ffa-1027-423e-b45e-5eacdb96bfc6)
![image](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/6d98ced1-d99b-464b-a09f-0054b125e364)

## Contrast Stretching
![image](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/74b82c0b-6969-41ee-a3b3-39e28ecb2c21)
![image](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/9a85cc9e-6500-41f6-a9e2-beda758d8e3e)
