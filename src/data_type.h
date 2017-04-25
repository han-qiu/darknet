#ifndef DATA_TYPE_H
#define DATA_TYPE_H
#include "assert.h"
#include "stdio.h"
#include "ap_fixed.h"
#include "hls_half.h"
//1
typedef ap_fixed<16, 2, AP_RND_CONV, AP_SAT> data_tw;
//
typedef ap_fixed<16, 6, AP_RND_CONV, AP_SAT> data_ti;
typedef ap_fixed<16, 7, AP_RND_CONV, AP_SAT> data_to;
float trans_one_i(float input);
float trans_one_w(float input);
float trans_one_o(float input);
void trans_i(float *input,float *output, int n);
void trans_w(float *input, float *output, int n);
void trans_o(float *input, float *output, int n);
#endif