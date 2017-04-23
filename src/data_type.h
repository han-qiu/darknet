#ifndef DATA_TYPE_H
#define DATA_TYPE_H
#include "assert.h"
#include "stdio.h"
float trans_(float input);
void trans(float *input,float *output, int n);
#ifdef GPU
void trans_gpu(float *x,float *y, int n);
#endif
size_t myfread(void *ptr, size_t size, size_t nmemb, FILE *stream);
#endif