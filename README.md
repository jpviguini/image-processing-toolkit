# Image Processing Toolkit

This is a simple C program for image processing, capable of performing various operations on PGM images. The program supports the following operations:

1. Logarithmic transformation
2. Contrast stretching
3. Paintbrush (flood fill)
4. Exponential transformation (optional)
5. Image negative (optional)

The program can read PGM images in both ASCII (P2) and binary (P5) formats.


## Requirements

• C compiler (e.g., GCC)<br />
• PGM image files for testing the program

<br />

# Usage

• Enter the operation number you wish to perform.<br />
• Next, enter the filename of the PGM image you want to process. The image should be located in the same directory as the program.<br />
• The program will process the image and create a new PGM image file named img_nova.pgm with the results of the chosen operation.    

<br />

# Input format
The program expects a PGM image file as input in either ASCII (P2) or binary (P5) format.<br />
The header of the PGM file should contain the following information:

P2/P5<br />
#CREATOR: [creator information]<br />
[width] [height]<br />
[max_value]<br />
[pixel data]<br />

<br />

# Output format
The output will be a new PGM image file named img_nova.pgm, which will be stored in the same directory as the program.<br />
The format of the output image will be the same as the input image.

# Examples
