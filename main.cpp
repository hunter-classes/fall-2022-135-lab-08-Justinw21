#include <iostream>

#include "imageio.h"
#include "funcs.h"

int main()
{
    std::string one = "image1.pgm";
    std::string two = "inImage.pgm";
    invert(one);
    invertHalf(one);
    box(one);
    frame(one);
    scale(two);
    pixelate(one);
}