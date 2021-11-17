
#include "matrix.h"

//инициализация матрицы
matrix *mkmatrix(int n, int m) {
    matrix *mx = (matrix *) malloc(sizeof(matrix));
    mx->m = m;
    mx->n = n;
    mx->data = (double **) (malloc(sizeof(double *) * n));
    for (int i = 0; i < n; ++i) {
        mx->data[i] = (double *) malloc(sizeof(double) * m);
    }
    return mx;
}


void delete_array(double **arr, int n) {
    for (int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);
}

void delete_matrix(matrix *mx) {
    delete_array(mx->data, mx->n);
    free(mx);
}

//вывод матрицы в консоль
void print_matrix(matrix *mx) {
    if (mx == NULL) {
        printf("Ответа не существует\n");
        return;
    }
    for (int i = 0; i < mx->n; ++i) {
        for (int j = 0; j < mx->m; ++j) {
            printf("%lf ", mx->data[i][j]);
        }
        putchar('\n');
    }
}

//считывание матрицы из консоли
void fill_array(double **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        arr[i] = calloc(sizeof(double), m);
        for (int j = 0; j < m; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
}

void fill_matrix_from_array(matrix *mx, double **arr) {
    for (int i = 0; i < mx->n; ++i) {
        for (int j = 0; j < mx->m; ++j) {
            mx->data[i][j] = arr[i][j];
        }
    }
}

void slau_interface() {
    int n;
    printf("Введите размер матрицы\n");
    scanf("%d", &n);
    double **mtrx = calloc(sizeof(double *), n);
    matrix *mx = mkmatrix(n, n);
    double **answ = calloc(sizeof(double *), n);
    matrix *vec = mkmatrix(n, 1);
    printf("Введите матрицу n*n\n");
    fill_array(mtrx, n, n);
    fill_matrix_from_array(mx, mtrx);
    printf("Введите вектор значений уравнений\n");
    fill_array(answ, n, 1);
    fill_matrix_from_array(vec, answ);
    char method;
    do {
        printf("Укажите метод решения системы (g - метод Гаусса, c - метод Крамера)\n");
        method = getchar();
    } while (method != 'g' && method != 'c');
    if (method == 'c') {
        matrix *res = crammer(mx, vec);
        print_matrix(res);
    } else {
        matrix *gs = gauss(mx, vec);
        print_matrix(gs);
    }
}

void two_matrix_interface() {
    printf("введите размерность первой матрицы\n");
    int n, m;
    scanf("%d %d", &n, &m);
    printf("введите матрицу\n");
    double **mtrx = calloc(sizeof(double *), n);
    matrix *mx = mkmatrix(n, m);
    fill_array(mtrx, n, m);
    fill_matrix_from_array(mx, mtrx);

    printf("введите размерность второй матрицы\n");
    scanf("%d %d", &n, &m);
    printf("введите матрицу\n");
    matrix *mx2 = mkmatrix(n, m);
    fill_array(mtrx, n, m);
    fill_matrix_from_array(mx, mtrx);

    int doing;
    do {
        printf("Введите действие (1-сложение, 2-умножение)\n");
        scanf("%d", &doing);
    } while (doing != 1 && doing != 2);
    if (doing == 1) {
        print_matrix(matrix_addition(mx, mx2));
    } else {
        print_matrix(matrix_multiplication(mx, mx2));
    }
}

void find_reverce_matrix_interface() {
    printf("введите размерность матрицы\n");
    int n, m;
    scanf("%d %d", &n, &m);
    printf("введите матрицу\n");
    double **mtrx = calloc(sizeof(double *), n);
    matrix *mx = mkmatrix(n, m);
    fill_array(mtrx, n, m);
    fill_matrix_from_array(mx, mtrx);
    print_matrix(find_reverce_matrix(mx));

}

int main() {
    setlocale(LC_ALL, "RUS");
    int method;
    do {
        printf("Введите 1 для решения слау, 2 для матричных операций, 3 для поиска обратной матрицы");
        scanf("%d",&method);
    } while (method!=1&&method!=2&&method!=3);
    if(method==1)slau_interface();
    else if(method==2)two_matrix_interface();
    else find_reverce_matrix_interface();
    system("pause");
    return 0;
}