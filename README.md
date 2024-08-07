# Image Processing Toolkit

This is a C program for image processing that reads a Portable Graymap (PGM) image, applies various image processing operations, and generates a new modified image.
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
```
/// Operations Menu ///
1. Logarithmic Transformation
2. Contrast Stretching
3. Flood Fill (Paintbrush)
4. Exponential Transformation 
5. Image Negative 
6. Mean Filter 
7. Median Filter 
```
• Enter the number corresponding to the desired operation. <br />
```
Operation number: 1
```
• Provide the filename of the PGM image you want to process when prompted. <br />
```
PGM file name: fusca.pgm
```
• The program will perform the selected operation on the input image and generate a new modified PGM image named **"img_nova.pgm"** in the same directory. <br />

## Input Format

The program supports PGM images in both ASCII and binary formats (P2 and P5, respectively). It automatically detects the format and reads the image accordingly.

## Output Format

The modified image will be generated in the P2 (ASCII) format, regardless of the input format. The output image is saved as **"img_nova.pgm"** in the same directory.

# Some examples
Left image = Original <br />
Right image = Modified
## Logarithm operator
![fusca1](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/01d7f9df-bccc-4e95-8912-8cc758ed216e)
![fuscamod1](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/9a7e3f09-dd64-468c-8c5b-d8e95ad6294f)



## Contrast Stretching
![bubbles2](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/302efdc3-a3d4-4b58-a6cd-d4d6eff66111)
![bubblesmod1](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/37f45c89-c643-4442-acfc-b660f366ea9c)



## Floodfill
![folha](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/d49aacfa-b43f-4c82-a3a5-c27833c262b0)
![folhamod1](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/5fc7ba56-7f4d-406f-9dca-49ebb41af36a)


## Image Negative
![sat_image](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/dc753cc6-a68e-4027-a356-a16077a6f8aa)
![sat_imagemod1](https://github.com/jpviguini/image-processing-toolkit/assets/70961838/29d3086b-70eb-46ca-abae-61b73b958018)



## Aknowledgements
This is an **extended version** of the final project from the discipline "Introduction do Computer Science I" (SCC-221) at the Institute of Mathematics and Computer Science (University of São Paulo) - ICMC/USP

