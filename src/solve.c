#include "matrix.h"
#include "print.h"
#include <stdio.h>

void swap(double* lhs, double* rhs) 
{
    double temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

void swap_lines(double* matrix, const int dim, int lhs, int rhs) {
    for (int j = 0; j < dim; j++) {
        swap(&(Matrix(lhs, j)), &(Matrix(rhs, j)));
    }
}

int solve(const int dim, double* matrix, double* answer)
{
    double coef;
    //идем по столбикам
    for(int k = 0; k < dim; k++) {
        //Если элемент на диагонали равен  0, то
        if(Matrix(k, k) == 0) {
            int non_zero_row = -1;
            //ищем ненулевой элемент, 
            for(int i = k; i < dim; i++) {
                if(Matrix(i, k) != 0) {
                    //Если нашли, то запомнили
                    non_zero_row = i;
                    //Поменяли
                    swap_lines(matrix, dim, k, non_zero_row);
                    swap(&(answer[k]),&(answer[non_zero_row]));
                    break;
                }
            }
            //Если не нашли, то вовзращаем код ошибки
            if(non_zero_row == -1) {
                return -1;
            }
        }

        //Так как элемент a_kk на диагонали != 0, то
        //разделим k уравнение на него  
        coef = Matrix(k,k);
        answer[k] /= coef;
        for(int j = k; j < dim; j++) {
            Matrix(k, j) /= coef;
        }
    
        // теперь a_kk == 1 
        //Зануляем в столбике все остальное
        for(int i = 0; i < dim; i++) {
            if(i != k) {
                coef = Matrix(i, k);
                answer[i] -=  coef * answer[k];
                //Применим вычетание ко всей строчке
                for(int j = k; j < dim; j++) {
                    Matrix(i, j) -= coef * (Matrix(k, j));
                }
            }
        }   
    }
    return 0;
}

double residual(const int dim, double* matrix,const double* r_part,const double* answer)
{
    //Вычисляем AX-b
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            Matrix(i,0) +=  Matrix(i,j)*answer[j];
        }
        Matrix(i,0) -= r_part[i];
    }
    return norm(matrix, dim, 1) / norm(r_part, 1, dim);

}

double diff(const int dim, double* answer)
{
    for(int i = 0; i < dim; i+=2) {
        answer[i] -= 1;
    }
    return norm(answer, 1, dim);
}