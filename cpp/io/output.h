#ifndef __OUTPUT_H__
#define __OUTPUT_H__

int writeImagePpm(const char* filename, int width, int height, unsigned char* buffer);
int writeImageBmp(const char* filename, int width, int height, unsigned char* buffer);
int writeImagePng(const char* filename, int width, int height, unsigned char* buffer);

#endif
