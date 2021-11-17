#include "matrix.h"

matrix *find_reverce_matrix(matrix *mx){
    double dett = det(mx);
    if(dett==0)return NULL;
    dett = 1/dett;
    matrix *ar = mkmatrix(mx->m,mx->n);
    for (int i = 0; i < mx->n; ++i) {
        for (int j = 0; j < mx->m; ++j) {
            ar->data[i][j] = algebraic_complement(mx,j,i);
        }
    }
    for (int i = 0; i < ar->n; ++i) {
        multip(ar,i,dett);
    }
    return ar;
}

double det(matrix *mx) {
    if (mx->n == 2 && mx->m == 2)return mx->data[0][0] * mx->data[1][1] - mx->data[0][1] * mx->data[1][0];
    else {
        double res = 0;
        for (int i = 0; i < mx->m; ++i) {
            res += mx->data[0][i] * algebraic_complement(mx, 0, i);
        }
        return res;
    }
}

double count_minor(matrix *mx, int i, int j) {
    matrix *new_mx = mkmatrix(mx->n - 1, mx->m - 1);
    int ii = 0, ij = 0;
    for (int k = 0; k < mx->n; ++k) {
        for (int l = 0; l < mx->m; ++l) {
            if (k != i && l != j) {
                new_mx->data[ii][ij] = mx->data[k][l];
                ij++;
            }
        }
        ij = 0;
        if (k != i)ii++;
    }
    double res = det(new_mx);
    delete_matrix(new_mx);
    return res;
}

double algebraic_complement(matrix *mx, int i, int j) {
    return count_minor(mx, i, j) * pow(-1, i + 1 + j + 1);
}

matrix *matrix_addition(matrix *mx1, matrix *mx2) {
    if (mx1->m != mx2->m && mx1->n != mx2->n)return NULL;
    else {
        matrix *res = mkmatrix(mx1->n, mx2->m);
        for (int i = 0; i < res->n; ++i) {
            for (int j = 0; j < res->m; ++j) {
                res->data[i][j] = mx1->data[i][j] + mx2->data[i][j];
            }
        }
        return res;
    }

}

matrix *matrix_subtraction(matrix *mx1, matrix *mx2) {
    if (mx1->m != mx2->m && mx1->n != mx2->n)return NULL;
    else {
        matrix *res = mkmatrix(mx1->n, mx2->m);
        for (int i = 0; i < res->n; ++i) {
            for (int j = 0; j < res->m; ++j) {
                res->data[i][j] = mx1->data[i][j] - mx2->data[i][j];
            }
        }
        return res;
    }
}

matrix *matrix_multiplication(matrix *mx1, matrix *mx2) {
    if (mx1->m != mx2->n)return NULL;
    else {
        matrix *res = mkmatrix(mx1->n, mx2->m);
        for (int i = 0; i < mx1->n; ++i) {
            for (int j = 0; j < mx2->m; ++j) {
                double elem = 0;
                for (int k = 0; k < mx1->m; ++k) {
                    for (int l = 0; l < mx1->n; ++l) {
                        for (int m = 0; m < mx2->m; ++m) {
                            elem += mx1->data[l][k] * mx2->data[k][m];
                        }
                    }
                }
                res->data[i][j] = elem;
            }
        }
        return res;
    }
}

