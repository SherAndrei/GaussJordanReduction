#include "fill.h"
#include "error.h"
#include "matrix.h"
#include <stdio.h>

int fill_from_file(double* matrix, int dim, const char* filename){
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

// double* fill_with_formula(double* matrix, int dim, int formula_name){

// }