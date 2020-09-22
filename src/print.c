#include "print.h"
#include "solve.h"
#include <stdio.h>

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

void print_all(double* matrix, const double* answer, const int dim, const int print_value, float time)
{
        printf("==================================\n\n");
        print_matrix(matrix, dim, dim, print_value);
        print_matrix(answer, 1, dim, print_value);
        printf("Time of solving : %6.3f sec\n", time);
}   

void print_residual(const double* matrix, const double* r_part, const int dim, const double* answer)
{ 
    printf("Residual norm   : %10.3e\n", residual(dim, matrix, r_part, answer)); 
}
void print_difference(const int dim, double* answer)
{ 
    printf("Differense norm : %10.3e\n", diff(dim, answer)); 
}