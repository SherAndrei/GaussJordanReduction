#include "print.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a) < (b)) ? (a) : (b))

void print_matrix(const double* matrix, const int Nrows, const int Ncolumns, const int print_value)
{
    for(int i = 0; i < MIN(Nrows, print_value); ++i)
    {
        for(int j = 0; j < MIN(Ncolumns, print_value); ++j)
            printf("%10.3e ", Matrix(i, j, Nrows));
        
        printf("\n");
    }
    printf("\n\n");
}