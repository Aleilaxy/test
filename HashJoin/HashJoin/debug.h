#pragma once
#ifndef CONST_CUH_
#define CONST_CUH_

#include<iostream>
#include<cstdint>
#include<cstdlib>
#include<string>
#include<cuda_runtime.h>

#define BLOCK_NUM 1<<7
#define THREADS_BLOCK 1<<10

#define HANDLE_ERROR( err ) (HandleError( err,__FILE__, __LINE__ ))
#define HANDLE_KERNEL_ERROR() HandleKernelError( __FILE__, __LINE__)

#define HANDLE_NULL( a ) { \
  if (a == NULL) { printf( "Host memory failed in %s at line %d\n",\
              __FILE__, __LINE__ ); \
       exit( EXIT_FAILURE );}}

static void HandleError(cudaError_t err, const char *file, int line) {
	if (err != cudaSuccess) {
		printf("%s in %s at line %d\n", cudaGetErrorString(err), file, line);
		exit(EXIT_FAILURE);
	}
}

static void HandleKernelError(const char *file, int line) {
	cudaError_t err = cudaGetLastError();
	// err = cudaDeviceSynchronize();
	if (err != cudaSuccess) {
		printf("%s in %s at line %d\n", cudaGetErrorString(err), file, line);
		exit(EXIT_FAILURE);
	}
}

#endif