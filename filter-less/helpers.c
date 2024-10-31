#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
int check(int sep)
{
    if (sep > 255)
        return 255;
    else
        return sep;
}
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepRed = check(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                         .189 * image[i][j].rgbtBlue));
            int sepGreen = check(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                           .168 * image[i][j].rgbtBlue));
            int sepBlue = check(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                          .131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = sepRed;
            image[i][j].rgbtGreen = sepGreen;
            image[i][j].rgbtBlue = sepBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            float count = 0;
            for (int a = i - 1; a < i + 2; a++)
            {
                if (a < 0 || a > height - 1)
                    continue;
                for (int b = j - 1; b < j + 2; b++)
                {
                    if (b < 0 || b > width - 1)
                    continue;

                    red += copy[a][b].rgbtRed;
                    green += copy[a][b].rgbtGreen;
                    blue += copy[a][b].rgbtBlue;
                    count++;
                }
            }
            image[i][j].rgbtRed = round(red / count);
            image[i][j].rgbtGreen = round(green / count);
            image[i][j].rgbtBlue = round(blue / count);
        }
    }
    return;
}
