#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <nvToolsExt.h>
#include <string.h>
#include <assert.h>

// CUDA runtime
#include <cuda.h>
#include <cuda_runtime.h>

// helper functions and utilities to work with CUDA
#include <helper_functions.h>
#include <helper_cuda.h>

	__global__
void vertorADDGPU(int n, float *x, float *y, float *z) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	// Memory reads of 8MB and memory writes of 4MB in turn
	// because n = 0x1 << 20
	if(idx < n) {
		z[idx] = x[idx] + y[idx];
	}
}

int main(int argc, char *argv[]) {
	int n = 0x1 << 20;
	int thr_num;
	float *x, *y, *z, *d_x, *d_y, *d_z;
	unsigned int flags = cudaHostAllocMapped;

	// Check the number of arguments
	if (argc != 2) {
		printf("please use with one argument\n");
		printf("The argument is thread num\n");
		return 1;
	}
	thr_num = atoi(argv[1]);

	// Dynamic memory allocation by using zero-copy memory mechanism
	checkCudaErrors(cudaHostAlloc((void **)&x, n * sizeof(float), flags));
	checkCudaErrors(cudaHostAlloc((void **)&y, n * sizeof(float), flags));
	checkCudaErrors(cudaHostAlloc((void **)&z, n * sizeof(float), flags));

	// Initialize the two input arrays
	for (int i = 0; i < n; i++) {
        x[i] = rand() / (float) RAND_MAX;
        y[i] = rand() / (float) RAND_MAX;
	}

	checkCudaErrors(cudaHostGetDevicePointer((void **)&d_x, (void *)x, 0));
	checkCudaErrors(cudaHostGetDevicePointer((void **)&d_y, (void *)y, 0));
	checkCudaErrors(cudaHostGetDevicePointer((void **)&d_z, (void *)z, 0));

	// Set the number of threads
	dim3 block(thr_num);
	dim3 grid((unsigned int)ceil(n / (float)block.x));
	while (1) {
		vertorADDGPU<<<grid, block>>>(n, d_x, d_y, d_z);
	}

	checkCudaErrors(cudaDeviceSynchronize());

	cudaFree(d_x);
	cudaFree(d_y);
	return 1;
}
