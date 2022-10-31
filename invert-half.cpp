#include <iostream>

#include "imageio.h"

int main()
{
    std::string input = "image1.pgm";
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

    writeImage("invertHalfImage.pgm", out, h, w);

    
    return 0;
}