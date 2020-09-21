#include "print.h"
#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a) < (b)) ? (a) : (b))

void print_matrix(const double* matrix, const int Nrows, const int Ncolumns, const int print_value)
{
    for(int i = 0; i < MIN(Nrows, print_value); ++i)
    {
        for(int j = 0; j < MIN(Ncolumns, print_value); ++j)
            printf("%10.3e ", matrix[i*Nrows + j]);
        
        printf("\n");
    }
    printf("\n");
}

void print_all(const double* matrix, const double* answer, const int dim, const double residual, const int print_value, float time)
{
        printf("==================================\n\n");
        print_matrix(matrix, dim, dim, print_value);
        print_matrix(answer, 1, dim, print_value);
        printf("Time of solving: %f\n", time);
        printf("Residual norm  : %10.3e\n", residual);
        // printf("Differense norm: %10.3e", diff());
}   