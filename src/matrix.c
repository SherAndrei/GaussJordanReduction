#include "matrix.h"
#include <stdlib.h>
#include <math.h>

double* alloc_matrix(const int length, const int height) {
    return (double*) malloc (length*height*sizeof(double));
}

double  norm(const double* vector, const int length)
{
    double result = 0.;
    for(int i = 0; i < length; ++i) {
            result += (vector[i] * vector[i]);
    }
    return sqrt(result);
}