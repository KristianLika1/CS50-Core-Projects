#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    long md = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            md = round((float)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = md;
            image[i][j].rgbtGreen = md;
            image[i][j].rgbtBlue = md;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiared = 0, sepiagreen = 0, sepiablue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiared = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiagreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiablue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if(sepiared > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiared;
            }
            if(sepiagreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiagreen;
            }
            if(sepiablue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiablue;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE average;
    RGBTRIPLE temp[height][width];
    bool in_boundaries;
    int counter;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            counter = 0;
            average.rgbtRed = 0, average.rgbtGreen = 0, average.rgbtBlue = 0;

            for (int di = -1; di <= 1; di++)
            {
            for (int dj = -1; dj <= 1; dj++)
            {
            // Check if the pixel at (i + di, j + dj) is within the image boundaries
            if ((i + di >= height || i + di < 0) || (j + dj >= width || j + dj < 0))
            {
                continue;
            }
            // If it is, add its color values to the running total and increment the counter
            else
            {
                average.rgbtRed += image[i + di][j + dj].rgbtRed;
                average.rgbtGreen += image[i + di][j + dj].rgbtGreen;
                average.rgbtBlue += image[i + di][j + dj].rgbtBlue;
                counter++;
            }
            }
            temp[i][j].rgbtRed = round(average.rgbtRed / counter);
            temp[i][j].rgbtGreen = round(average.rgbtGreen / counter);
            temp[i][j].rgbtBlue = round(average.rgbtBlue / counter);
            }
        }
    }
    for (int s = 0; s < height; s++)
    {
        for (int t = 0; t < width; t++)
        {
            image[s][t].rgbtRed = temp[s][t].rgbtRed;
            image[s][t].rgbtGreen = temp[s][t].rgbtGreen;
            image[s][t].rgbtBlue = temp[s][t].rgbtBlue;
        }
    }
    return;
}
