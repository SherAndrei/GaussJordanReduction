#pragma once

int  fill_from_file(double* matrix, const int dim, const char* filename);
void fill_with_formula(double* matrix, const int dim, int formula_name);
void fill_right_part(const double* matrix, double* right_part, const int dim);