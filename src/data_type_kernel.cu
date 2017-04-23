#include "cuda_runtime.h"
#include "curand.h"
#include "cublas_v2.h"

extern "C" {
#include "data_type.h"
#include "cuda.h"
#include "convolutional_layer.h"
}
typedef unsigned int uint;
__global__ void trans_kernel(float *x, float *y, int n)
{
#if DATA_TYPE==0
    return;
#elif DATA_TYPE==1
	int i = (blockIdx.x + blockIdx.y*gridDim.x) * blockDim.x + threadIdx.x;
    if (i >= n) return;
	uint t = *(uint*)&x[i];
	// 1+8+23->1+5+10
	uint frac = t&0x007fffff;
	frac = (frac >> 13)<<13;
	t = (t&(~0x007fffff))|frac;
	y[i] = t;
#else
#error Not done
#endif
}

void trans_gpu(float *x, float *y, int n)
{
    trans_kernel<<<cuda_gridsize(n), BLOCK>>>(x, y, n);
    check_error(cudaPeekAtLastError());
}