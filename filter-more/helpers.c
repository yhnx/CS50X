#include "helpers.h"
#include <math.h>
#include <stdio.h>

int more(int num)
{
    if (num > 255)
    {
        return 255;
    }
    else
    {
        return num;
    }
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float m = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int n = round(m);
            image[i][j].rgbtRed = n;
            image[i][j].rgbtGreen = n;
            image[i][j].rgbtBlue = n;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half_w = round(width / 2.0);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < half_w; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            double count = 0;
            int R = 0;
            int G = 0;
            int B = 0;
            for (int x = -1; x < 2; x++)
            {

                for (int y = -1; y < 2; y++)
                {
                    if ((h + y > -1) && (w + x > -1) && (h + y < height) && (w + x < width))
                    {
                        R += temp[h + y][w + x].rgbtRed;
                        G += temp[h + y][w + x].rgbtGreen;
                        B += temp[h + y][w + x].rgbtBlue;
                        count++;
                    }
                }
            }
            image[h][w].rgbtRed = more(round(R / count));
            image[h][w].rgbtGreen = more(round(G / count));
            image[h][w].rgbtBlue = more(round(B / count));
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int XR = 0, YR = 0, XG = 0, YG = 0, XB = 0, YB = 0;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if ((h + y > -1) && (w + x > -1) && (h + y < height) && (w + x < width))
                    {
                        XR += temp[h + y][w + x].rgbtRed * Gx[x + 1][y + 1];
                        YR += temp[h + y][w + x].rgbtRed * Gy[x + 1][y + 1];
                        XG += temp[h + y][w + x].rgbtGreen * Gx[x + 1][y + 1];
                        YG += temp[h + y][w + x].rgbtGreen * Gy[x + 1][y + 1];
                        XB += temp[h + y][w + x].rgbtBlue * Gx[x + 1][y + 1];
                        YB += temp[h + y][w + x].rgbtBlue * Gy[x + 1][y + 1];
                    }
                }
            }
            image[h][w].rgbtRed = more(round(sqrt(XR * XR + YR * YR)));
            image[h][w].rgbtGreen = more(round(sqrt(XG * XG + YG * YG)));
            image[h][w].rgbtBlue = more(round(sqrt(XB * XB + YB * YB)));
        }
    }

    return;
}
