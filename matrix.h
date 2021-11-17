#include "stdlib.h"
#include "math.h"
#include "stdio.h"
#include "locale.h"
#include "windows.h"
struct Matrix {
    double **data;
    int n;
    int m;
};

typedef struct Matrix matrix;

matrix *mkmatrix(int n, int m);
int is_triangle(matrix *mx);
void delete_array(double **arr, int n);
void delete_matrix(matrix *mx);
matrix *find_reverce_matrix(matrix *mx);
void print_matrix(matrix *mx);
double det(matrix *mx);
void fill_matrix(matrix *mx);
void fill_matrix_from_array(matrix *mx, double **arr);
double count_det(matrix *mx) ;
double count_minor(matrix *mx, int i, int j);
double algebraic_complement(matrix *mx, int i, int j) ;
void switch_string(matrix *mx, int i, int j);
void multip(matrix *mx, int str, double k);
void subtraction_rows(matrix *mx, int ded, int v) ;
void zero_column(matrix *mx, matrix *vec, int col,double *multiplicator);
void to_triangle(matrix *mx, matrix *vec,double *multiplicator);
matrix *gauss(matrix *mx, matrix *vec);
double count_xi(matrix *mx, matrix *vec, int i);
matrix *crammer(matrix *mx, matrix *vec) ;
matrix *matrix_addition(matrix *mx1, matrix *mx2);
matrix *matrix_subtraction(matrix *mx1, matrix *mx2);
matrix *matrix_multiplication(matrix *mx1, matrix *mx2);

