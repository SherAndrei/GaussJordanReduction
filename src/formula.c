#include "formula.h"
#include "matrix.h"
#include <stdlib.h>
#include <math.h>

void formula_one(double* matrix, const int dim)
{
    for(int i = 0; i < dim; ++i)
        for(int j = 0; j < dim; ++j)
            Matrix(i, j, dim) = dim - MAX(i + 1, j + 1) + 1;
}
void formula_two(double* matrix, const int dim)
{
    for(int i = 0; i < dim; ++i)
        for(int j = 0; j < dim; ++j)
            Matrix(i, j, dim) = MAX(i + 1, j + 1);
}
void formula_three(double* matrix, const int dim)
{
    for(int i = 0; i < dim; ++i)
        for(int j = 0; j < dim; ++j)
            Matrix(i, j, dim) = abs(i - j);
}
void formula_four(double* matrix, const int dim)
{
    for(int i = 0; i < dim; ++i)
        for(int j = 0; j < dim; ++j)
            Matrix(i, j, dim) = fabs(1. / (i + j + 1));
}