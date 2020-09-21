#include "fill.h"
#include "formula.h"
#include "error.h"
#include "matrix.h"
#include <stdio.h>

int fill_from_file(double* matrix, const int dim, const char* filename) {
    FILE* inp;
    if((inp = fopen(filename, "r")) == NULL) 
        return FUNC_ERROR("fopen");

    int counter = 0;
    for(int i = 0; i < dim * dim; ++i)
        if(fscanf(inp, "%lf", &(matrix[i])) == 1)
            counter++;
        else break;
            
    if(counter != dim * dim)
        return FUNC_ERROR("fscanf");

    return 1;
}

void fill_with_formula(double* matrix, const int dim, const int formula_name){
    switch (formula_name)
    {
    case 1: formula_one(matrix, dim);
        break;
    case 2: formula_two(matrix, dim);
        break;
    case 3: formula_three(matrix, dim);
        break;
    case 4: formula_four(matrix, dim);
        break;
    default:
        break;
    }
}

void fill_right_part(const double* matrix, double* right_part, const int dim)
{
    for(int i = 0; i < dim; i++) {
        for(int k = 0; k < (dim + 1)/2; k++) {
            right_part[i] += Matrix(i, 2*k + 1, dim);
        }
    }
}