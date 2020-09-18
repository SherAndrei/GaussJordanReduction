#include "matrix.h"
#include <stdlib.h>

double* alloc_matrix(const int dim) {
    return (double*) malloc (dim*dim*sizeof(double));
}
