#include <iostream>

#include "imageio.h"

int main()
{
    std::string input = "image1.pgm";
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

    writeImage("invertImage.pgm", out, h, w);

    
    return 0;
}