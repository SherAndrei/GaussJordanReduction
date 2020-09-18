#include "matrix.h"
#include <stdlib.h>

double* alloc_matrix(int dim) {
    return (double*) malloc (dim*dim*sizeof(double));
}
