#pragma once

void print_matrix(const double* matrix, const int Nrows, const int Ncolumns, const int print_value);
void print_all(double* matrix, double* answer,  
               const int dim, const int print_value, float time);
void print_residual(double* matrix, const double* r_part, const int dim, double* answer);