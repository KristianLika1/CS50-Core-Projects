#include "helpers.h"
#include <cs50.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    long md = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            md = round((float) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = md;
            image[i][j].rgbtGreen = md;
            image[i][j].rgbtBlue = md;
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
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int totalred, totalgreen, totalblue, counter;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // reset the totals and counter to 0
            totalred = 0, totalgreen = 0, totalblue = 0, counter = 0;

            // The next two loops iterate on the 3X3 box of pixels
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    // checks if we are within the boundaries
                    if ((i + di < 0 || i + di >= height) || (j + dj < 0 || j + dj >= width))
                    {
                        continue;
                    }
                    totalred += image[i + di][j + dj].rgbtRed;
                    totalgreen += image[i + di][j + dj].rgbtGreen;
                    totalblue += image[i + di][j + dj].rgbtBlue;
                    counter++;
                }
            }
            temp[i][j].rgbtRed = round(fminf(255.0, ((float) totalred / counter)));
            temp[i][j].rgbtGreen = round(fminf(255.0, ((float) totalgreen / counter)));
            temp[i][j].rgbtBlue = round(fminf(255.0, ((float) totalblue / counter)));
        }
    }
    for (int n = 0; n < height; n++)
    {
        for (int l = 0; l < width; l++)
        {
            image[n][l] = temp[n][l];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width], totalx, totaly;
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // resetting all values to 0
            int totalxRed = 0, totalxGreen = 0, totalxBlue = 0, totalyRed = 0, totalyGreen = 0, totalyBlue = 0;

            // The next two loops iterate on the 3X3 box of pixels
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    // checks if we are within the boundaries
                    if ((i + di < 0 || i + di >= height) || (j + dj < 0 || j + dj >= width))
                    {
                        continue;
                    }

                    totalxRed += image[i + di][j + dj].rgbtRed * Gx[di + 1][dj + 1];
                    totalxGreen += image[i + di][j + dj].rgbtGreen * Gx[di + 1][dj + 1];
                    totalxBlue += image[i + di][j + dj].rgbtBlue * Gx[di + 1][dj + 1];

                    totalyRed += image[i + di][j + dj].rgbtRed * Gy[di + 1][dj + 1];
                    totalyGreen += image[i + di][j + dj].rgbtGreen * Gy[di + 1][dj + 1];
                    totalyBlue += image[i + di][j + dj].rgbtBlue * Gy[di + 1][dj + 1];
                }
            }
            temp[i][j].rgbtRed = round(fminf(sqrt(pow(totalxRed, 2) + pow(totalyRed, 2)), 255.0));
            temp[i][j].rgbtGreen = round(fminf(sqrt(pow(totalxGreen, 2) + pow(totalyGreen, 2)), 255.0));
            temp[i][j].rgbtBlue = round(fminf(sqrt(pow(totalxBlue, 2) + pow(totalyBlue, 2)), 255.0));
        }
    }
    for (int n = 0; n < height; n++)
    {
        for (int l = 0; l < width; l++)
        {
            image[n][l] = temp[n][l];
        }
    }
    return;
}
