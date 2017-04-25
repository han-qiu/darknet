#ifndef DATA_TYPE_H
#define DATA_TYPE_H
#include "assert.h"
#include "stdio.h"
#ifdef __cplusplus
extern "C"{
#endif
float trans_one_i(float input);
float trans_one_w(float input);
float trans_one_o(float input);
void trans_i(float *input,float *output, int n);
void trans_w(float *input, float *output, int n);
void trans_o(float *input, float *output, int n);
#ifdef __cplusplus
}
#endif
#endif