#pragma once

int solve(const int dim, double* matrix, double* answer);
double residual(const int dim, const double* matrix,const double* r_part,const double* answer);
double diff(const int dim, double* answer);