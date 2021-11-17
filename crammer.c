
#include "matrix.h"

double count_xi(matrix *mx, matrix *vec, int i) {
    matrix *mxi = mkmatrix(mx->n, mx->m);
    for (int j = 0; j < mx->n; ++j) {
        for (int k = 0; k < mx->m; ++k) {
            if (k == i)mxi->data[j][k] = vec->data[j][0];
            else mxi->data[j][k] = mx->data[j][k];
        }
    }
    double detxi = det(mxi);
    delete_matrix(mxi);
    return detxi;
}

matrix *crammer(matrix *mx, matrix *vec) {
    matrix *res = mkmatrix(vec->n, vec->m);
    double dett = det(mx);
    if (dett==0)return gauss(mx,vec);
    for (int i = 0; i < mx->m; ++i) {
        res->data[i][0] = count_xi(mx, vec, i) / dett;
    }
    return res;
}
