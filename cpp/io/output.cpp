#include "output.h"

#include <stdio.h>
int writeImagePpm(const char* filename, int width, int height, unsigned char *buffer)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(buffer, 1, 3 * width * height, fp);
    fclose(fp);
    return 0;
}

#include "../lib/lodepng.h"
int writeImagePng(const char* filename, int width, int height, unsigned char *buffer)
{
    std::vector<unsigned char> image;
    image.resize(width * height * 4);
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[4 * width * i + 4 * j + 0] = buffer[3 * width * i + 3 * j + 0];
            image[4 * width * i + 4 * j + 1] = buffer[3 * width * i + 3 * j + 1];
            image[4 * width * i + 4 * j + 2] = buffer[3 * width * i + 3 * j + 2];
            image[4 * width * i + 4 * j + 3] = 255;
        }
    }
    lodepng::encode(filename, image, width, height);
    return 0;
}

#include <cstdlib>
#include <cstring>
int writeImageBmp(const char* filename, int width, int height, unsigned char* buffer)
{
    FILE *f;
    unsigned char *img = nullptr;
    const short headerSize = 54;
    const int dataSize = 3 * width * height;
    const int fileSize = headerSize + dataSize;

    img = new unsigned char[fileSize];
    memset(img, 0, fileSize);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            img[(j+i*width)*3+2] = buffer[(j+i*width)*3+0];
            img[(j+i*width)*3+1] = buffer[(j+i*width)*3+1];
            img[(j+i*width)*3+0] = buffer[(j+i*width)*3+2];
        }
    }

    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
    unsigned char bmppad[3] = {0,0,0};

    bmpfileheader[ 2] = (unsigned char)(fileSize);
    bmpfileheader[ 3] = (unsigned char)(fileSize >> 8);
    bmpfileheader[ 4] = (unsigned char)(fileSize >> 16);
    bmpfileheader[ 5] = (unsigned char)(fileSize >> 24);

    bmpinfoheader[ 4] = (unsigned char)(width);
    bmpinfoheader[ 5] = (unsigned char)(width >> 8);
    bmpinfoheader[ 6] = (unsigned char)(width >> 16);
    bmpinfoheader[ 7] = (unsigned char)(width >> 24);
    bmpinfoheader[ 8] = (unsigned char)(height);
    bmpinfoheader[ 9] = (unsigned char)(height >> 8);
    bmpinfoheader[10] = (unsigned char)(height >> 16);
    bmpinfoheader[11] = (unsigned char)(height >> 24);

    f = fopen(filename, "wb");
    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    for (int i = 0; i < height; i++)
    {
        fwrite(img + (width * (height - i -1) *3), 3, width, f);
        fwrite(bmppad, 1, (4 - (width * 3) % 4) % 4, f);
    }

    free(img);
    fclose(f);

    return 0;
}

