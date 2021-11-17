#include "matrix.h"

matrix *gauss(matrix *mx, matrix *vec) {
    to_triangle(mx, vec,NULL);
    matrix *answ = mkmatrix(vec->n, vec->m);
    for (int i = vec->n - 1; i >= 0; --i) {
        double eq = 0;
        for (int j = i + 1; j < mx->m; ++j) {
            eq += mx->data[i][j] * answ->data[j][0];
        }
        if (mx->data[i][i] != 0)answ->data[i][0] = (vec->data[i][0] - eq) / mx->data[i][i];
        else answ->data[i][0] = 0;
    }
    return answ;
}