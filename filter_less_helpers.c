#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width; row++)
        {
            float pixelRed = image[col][row].rgbtRed;
            float pixelGreen = image[col][row].rgbtGreen;
            float pixelBlue = image[col][row].rgbtBlue;
            int avg = round((pixelRed + pixelGreen + pixelBlue) / 3);
            image[col][row].rgbtRed = avg;
            image[col][row].rgbtGreen = avg;
            image[col][row].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width; row++)
        {
            float sepiaPixelRed =
                (.393 * image[col][row].rgbtRed + .769 * image[col][row].rgbtGreen + .189 * image[col][row].rgbtBlue);
            float sepiaPixelGreen =
                (.349 * image[col][row].rgbtRed + .686 * image[col][row].rgbtGreen + .168 * image[col][row].rgbtBlue);
            float sepiaPixelBlue =
                (.272 * image[col][row].rgbtRed + .534 * image[col][row].rgbtGreen + .131 * image[col][row].rgbtBlue);

            int newSepiaPixelRed = round(sepiaPixelRed);
            if (sepiaPixelRed < 0 || sepiaPixelRed > 255)
            {
                newSepiaPixelRed = 255;
            }
            image[col][row].rgbtRed = newSepiaPixelRed;

            int newSepiaPixelGreen = round(sepiaPixelGreen);
            if (sepiaPixelGreen < 0 || sepiaPixelGreen > 255)
            {
                newSepiaPixelGreen = 255;
            }
            image[col][row].rgbtGreen = newSepiaPixelGreen;

            int newSepiaPixelBlue = round(sepiaPixelBlue);
            if (sepiaPixelBlue < 0 || sepiaPixelBlue > 255)
            {
                newSepiaPixelBlue = 255;
            }
            image[col][row].rgbtBlue = newSepiaPixelBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width / 2; row++)
        {
            RGBTRIPLE imageTemp = image[col][row];
            image[col][row] = image[col][width - (row + 1)];
            image[col][width - (row + 1)] = imageTemp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}