#include "matrix.h"

int is_triangle(matrix *mx){
    for (int i = 0; i < mx->n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(mx->data[i][j]!=0)return 0;
        }
    }
    return 1;
}

void switch_string(matrix *mx, int i, int j) {
    for (int k = 0; k < mx->m; k++) {
        mx->data[i][k] += mx->data[j][k];
        mx->data[j][k] = mx->data[i][k] - mx->data[j][k];

    }
}

//умножение строки на число
void multip(matrix *mx, int str, double k) {
    for (int i = 0; i < mx->m; i++) {
        mx->data[str][i] *= k;
    }
}

//вычитание из строки ded строки v
void subtraction_rows(matrix *mx, int ded, int v) {
    for (int i = 0; i < mx->m; ++i) {
        mx->data[ded][i] -= mx->data[v][i];
    }
}

//по алгоритму надо идти по строкам и для каждой i строки и i столбца  путем домножения строки на число и сложения строк занулять все элементы столбца ниже строки
void zero_column(matrix *mx, matrix *vec, int col,double *multiplicator) {
    for (int i = col + 1; i < mx->n; ++i) {
        if(mx->data[i][col]==0) continue;
        double k = mx->data[col][col] / mx->data[i][col];
        if(multiplicator!=NULL)*multiplicator*=k;
        multip(mx, i, k);
        if(vec!=NULL)multip(vec, i, k);
        subtraction_rows(mx, i, col);
        if(vec!=NULL)subtraction_rows(vec, i, col);
    }
}

//функция приведения матрицы к треугольному виду
void to_triangle(matrix *mx, matrix *vec,double *multiplicator) {
    if (is_triangle(mx))return;
    for (int i = 0; i < mx->m; ++i) {
        zero_column(mx, vec, i,multiplicator);
    }

}
