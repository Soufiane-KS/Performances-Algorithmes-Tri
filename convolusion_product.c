#include<stdio.h>
#include<stdlib.h>

int** conv_matrices(int** A, int** B, int N, int p) {
  // Calculate result matrix size
  int result_size = N - p + 1;

  // Dynamically allocate memory for the result matrix with boundary checks
  int** result = (int**)malloc(result_size * sizeof(int*));
  for (int i = 0; i < result_size; ++i) {
    if (i < 0 || i >= result_size) {
      return NULL; // Handle memory allocation error
    }
    result[i] = (int*)malloc(result_size * sizeof(int));
    for (int j = 0; j < result_size; ++j) {
      if (j < 0 || j >= result_size) {
        return NULL; // Handle memory allocation error
      }
      result[i][j] = 0;
    }
  }

  // Nested loops for convolution with boundary checks
  for (int i = 0; i < result_size; ++i) {
    for (int j = 0; j < result_size; ++j) {
      int sum = 0;
      for (int k = 0; k < p; ++k) {
        for (int l = 0; l < p; ++l) {
          // Check if indices are within bounds of matrices A and B
          if (i + k >= 0 && i + k < N && j + l >= 0 && j + l < N) {
            sum += A[i + k][j + l] * B[k][l];
          }
        }
      }
      result[i][j] = sum;
    }
  }

  return result;
}
