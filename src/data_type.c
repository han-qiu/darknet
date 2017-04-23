#include "data_type.h"
typedef unsigned int uint;
#define FRAC(x) (x&0x007fffff)
#define EXP(x) ((x&0x7f800000) >> 23)
#define SIGN(x) ((x&0x80000000) >> 31)
typedef union{
  float f;
  unsigned int u;
} ufloat;
float trans_(float input){
	#if DATA_TYPE == 0
	return input;
	#elif DATA_TYPE==1
	ufloat u1;
	u1.f = input;
	uint t = u1.u;
	// 1+8+23->1+5+10
	uint frac = t&0x007fffff;
	frac = (frac >> 13)<<13;
	t = (t&(~0x007fffff))|frac;
	u1.u = t;
	return u1.f;
	#elif DATA_TYPE==2
	
	#else
	#error Unsupported choice setting;
	#endif
}
void trans(float *input,float *output, int n){
	int i;
	for(i=0;i<n;++i)
		output[i] = trans_(input[i]);
	return;
}
size_t myfread(void *ptr, size_t size, size_t nmemb, FILE *stream){
	fread(ptr, size, nmemb, stream);
	assert(size==sizeof(float));
	float *p = (float*)ptr;
	trans(p, p, nmemb);
}