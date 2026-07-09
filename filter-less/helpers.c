#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg = 0;
    int intavg = 0;


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            avg = 0;
            intavg = 0;

            avg += image[i][j].rgbtBlue;
            avg += image[i][j].rgbtGreen;
            avg += image[i][j].rgbtRed;

            avg = avg/3.0;
            intavg = round(avg);


            image[i][j].rgbtBlue = intavg;
            image[i][j].rgbtGreen = intavg;
            image[i][j].rgbtRed = intavg;



        }

    }



    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{


    float avg = 0;
    int intavg = 0;


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int ored = image[i][j].rgbtRed;
            int oblu = image[i][j].rgbtBlue;
            int ogreen = image[i][j].rgbtGreen;

           float sepiaRed = .393 * ored + .769 * ogreen + .189 * oblu;
           float sepiaGreen = .349 * ored + .686 * ogreen + .168 * oblu;
           float sepiaBlue = .272 * ored + .534 * ogreen + .131 * oblu;

             int isepiaRed = round(sepiaRed);
             int isepiaGreen = round(sepiaGreen);
             int isepiaBlue = round(sepiaBlue);

            if(isepiaRed > 255)
            {
                isepiaRed = 255;

            }

            if(isepiaBlue > 255)
            {
                isepiaBlue = 255;

            }

            if(isepiaGreen > 255)
            {
                isepiaGreen = 255;

            }

            image[i][j].rgbtBlue = isepiaBlue;
            image[i][j].rgbtGreen = isepiaGreen;
            image[i][j].rgbtRed = isepiaRed;



        }

    }



    return;


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[width];
    for(int i = 0; i < height; i++)
    {

        for(int j = 0; j < width; j++)
        {

            temp[j] = image[i][j];

        }

        for(int k = 0; k < width; k++)
        {

            image[i][k] = temp[width - k - 1];

        }






    }





return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurred_image[height][width];

    for (int col = 0; col < height; col++) {
        for (int row = 0; row < width; row++) {

            double sumRed = 0;
            double sumGreen = 0;
            double sumBlue = 0;
            double divider = 0;

            for (int y = col - 1; y <= col + 1; y++) {
                for (int x = row - 1; x <= row + 1; x++) {
                    // If a pixel is within a valid range
                    if ((y >= 0 && y < height) && (x >= 0 && x < width)) {
                        sumRed = image[y][x].rgbtRed + sumRed;
                        sumGreen = image[y][x].rgbtGreen + sumGreen;
                        sumBlue = image[y][x].rgbtBlue + sumBlue;
                        divider++;
                    }

                }
            }

            blurred_image[col][row].rgbtRed = round((sumRed / divider));
            blurred_image[col][row].rgbtGreen = round((sumGreen / divider));
            blurred_image[col][row].rgbtBlue = round((sumBlue / divider));

        }
    }

    // Overwrite the orinal image with the blurred image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].rgbtRed = blurred_image[i][j].rgbtRed;
            image[i][j].rgbtGreen = blurred_image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = blurred_image[i][j].rgbtBlue;
        }
    }

    return;
}
