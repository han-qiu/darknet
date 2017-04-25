#include "data_type.h"
typedef unsigned int uint;
#define FRAC(x) (x&0x007fffff)
#define EXP(x) ((x&0x7f800000) >> 23)
#define SIGN(x) ((x&0x80000000) >> 31)
typedef union{
  float f;
  unsigned int u;
} ufloat;
float f2fp16(float input){
	ufloat u1;
	u1.f = input;
	uint t = u1.u;
	// 1+8+23->1+5+10
	uint frac = t&0x007fffff;
	frac = (frac >> 13)<<13;
	t = (t&(~0x007fffff))|frac;
	u1.u = t;
	return u1.f;
}
float trans_one_w(float input){
	#if DATA_TYPE == 0
	return input;
	#elif DATA_TYPE==1
	return f2fp16(input);
	#elif DATA_TYPE==2
	data_tw tmp;
	tmp = input;
	float re;
	re = tmp;
	return re;
	#else
	#error Unsupported choice setting;
	#endif
}
float trans_one_i(float input){
	#if DATA_TYPE == 0
	return input;
	#elif DATA_TYPE==1
	return f2fp16(input);
	#elif DATA_TYPE==2
	data_ti tmp;
	tmp = input;
	float re;
	re = tmp;
	return re;
	#else
	#error Unsupported choice setting;
	#endif
}
float trans_one_o(float input){
	#if DATA_TYPE == 0
	return input;
	#elif DATA_TYPE==1
	return f2fp16(input);
	#elif DATA_TYPE==2
	data_to tmp;
	tmp = input;
	float re;
	re = tmp;
	return re;
	#endif
}
void trans_o(float *input,float *output, int n){
	int i;
	for(i=0;i<n;++i)
		output[i] = trans_one_o(input[i]);
	return;
}
void trans_w(float *input,float *output, int n){
	int i;
	for(i=0;i<n;++i)
		output[i] = trans_one_w(input[i]);
	return;
}
void trans_i(float *input,float *output, int n){
	int i;
	for(i=0;i<n;++i)
		output[i] = trans_one_i(input[i]);
	return;
}