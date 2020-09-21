#include "matrix.h"
#include <stdlib.h>
#include <math.h>

double* alloc_matrix(const int length, const int height) {
    return (double*) malloc (length*height*sizeof(double));
}

double  norm(const double* matrix,  const int height, const int length)
{
    double result = 0.;
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < length; j++) {
            result += (matrix[i*height + j] * matrix[i*height + j]);
        }
    }
    return sqrt(result);
}