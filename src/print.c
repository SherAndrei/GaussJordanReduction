#include "print.h"
#include <stdio.h>
#include <stdlib.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

void print_matrix(double* matrix, int Nrows, int Ncolumns, int print_value)
{
    for(int i = 0; i < min(Nrows, print_value); ++i)
    {
        for(int j = 0; j < min(Ncolumns, print_value); ++j)
            printf("%10.3e ", matrix[i*Nrows + j]);
        
        printf("\n");
    }
    printf("\n\n");
}