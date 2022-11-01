#include <iostream>
#include "imageio.h"

void invert(std::string input)
{
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++)
    {
        for(int col = 0; col < w; col++)
        {
            out[row][col] = abs(img[row][col] - 255);
        }
    }

    writeImage("taskA.pgm", out, h, w);

    
}

void invertHalf(std::string input)
{
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];
    int size = w;

    for(int row = 0; row < h; row++)
    {
        for(int col = 0; col < w; col++)
        {
            if(col >= w/2)
            {
                out[row][col] = abs(img[row][col] - 255);
            }
            else
            {
                out[row][col] = img[row][col];
            }
        }
    }

    writeImage("taskB.pgm", out, h, w);

}

void box(std::string input)
{
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];
    int size = w;

    for(int row = 0; row < h; row++)
    {
        for(int col = 0; col < w; col++)
        {
            if(col >= w/4 && col <= w - (w/4) && row >= h/4 && row <= h - (h/4))
            {
                out[row][col] = 255;
            }
            else
            {
                out[row][col] = img[row][col];
            }
        }
    }

    writeImage("taskC.pgm", out, h, w);
}

void frame(std::string input)
{
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++)
    {
        for(int col = 0; col < w; col++)
        {
            if((((row == h/4 || row == (h - h/4)) && (col > w/4 && col < (w - w/4)))) || ((col == w/4 || col == (w - w/4)) && (row > h/4 && row < (h - h/4))))
            {
                out[row][col] = 255;
            }
            else
            {
                out[row][col] = img[row][col];
            }
        }
    }

    writeImage("taskD.pgm", out, h, w);
}

void scale(std::string input)
{
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];
    int size = w;

    for(int row = 0; row < h; row++)
    {
        for(int col = 0; col < w; col++)
        {
            out[row*2][col*2] = img[row][col];
            out[row*2+1][col*2] = img[row][col];
            out[row*2][col*2+1] = img[row][col];
            out[row*2+1][col*2+1] = img[row][col];
        }
    }

    writeImage("taskE.pgm", out, h*2, w*2);

}

void pixelate(std::string input)
{
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];
    int avg;
    int sum;
    for(int row = 0; row < h; row+=2)
    {
        for(int col = 0; col < w; col+=2)
        {
            {
                sum = img[row][col] + img[row][col+1] + img[row+1][col] + img[row+1][col+1];
                avg = sum/4;
                out[row][col] = avg;
                out[row][col+1] = avg;
                out[row+1][col] = avg;
                out[row+1][col+1] = avg;
            }
        }
    }

    writeImage("taskF.pgm", out, h, w);
}