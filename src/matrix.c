#include "matrix.h"
#include <stdlib.h>

double* alloc_matrix(const int length, const int width) {
    return (double*) malloc (length*width*sizeof(double));
}
