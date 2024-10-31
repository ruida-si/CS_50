#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int grey =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtBlue = grey;
        }
    }
    return;
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
    return;
}

// Blur image
RGBTRIPLE make_blur(int height, int width, int i, int j, RGBTRIPLE copy[height][width])
{
    int red = 0;
    int green = 0;
    int blue = 0;
    float count = 0;
    RGBTRIPLE image;

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
    image.rgbtRed = round(red / count);
    image.rgbtGreen = round(green / count);
    image.rgbtBlue = round(blue / count);

    return image;
}
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
            image[i][j] = make_blur(height, width, i, j, copy);
        }
    }
    return;
}

// Detect edges
int check(int rgb)
{
    if (rgb > 255)
        rgb = 255;
    return rgb;
}
RGBTRIPLE make_edges(int height, int width, int i, int j, RGBTRIPLE copy[height][width])
{
    int fy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int fx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    RGBTRIPLE image;
    int rx = 0;
    int ry = 0;
    int gx = 0;
    int gy = 0;
    int bx = 0;
    int by = 0;

    for (int a = i - 1; a < i + 2; a++)
    {
        if (a < 0 || a > height - 1)
            continue;
        for (int b = j - 1; b < j + 2; b++)
        {
            if (b < 0 || b > width - 1)
            continue;

            rx += copy[a][b].rgbtRed * fx[a - (i - 1)][b - (j - 1)];
            ry += copy[a][b].rgbtRed * fy[a - (i - 1)][b - (j - 1)];
            gx += copy[a][b].rgbtGreen * fx[a - (i - 1)][b - (j - 1)];
            gy += copy[a][b].rgbtGreen * fy[a - (i - 1)][b - (j - 1)];
            bx += copy[a][b].rgbtBlue * fx[a - (i - 1)][b - (j - 1)];
            by += copy[a][b].rgbtBlue * fy[a - (i - 1)][b - (j - 1)];
        }
    }
    image.rgbtRed = check(round(sqrt(pow(rx, 2) + pow(ry, 2))));
    image.rgbtGreen = check(round(sqrt(pow(gx, 2) + pow(gy, 2))));
    image.rgbtBlue = check(round(sqrt(pow(bx, 2) + pow(by, 2))));

    return image;
}
void edges(int height, int width, RGBTRIPLE image[height][width])
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
            image[i][j] = make_edges(height, width, i, j, copy);
        }
    }
    return;
}
