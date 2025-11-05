#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double** create_matrix(int n, int m) {
    double** a = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
        a[i] = (double*)malloc(m * sizeof(double));
    return a;
}
void fill_matrix(double** a, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = (rand() % 1000) / 10.0;
}
void print_matrix(double** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%6.1f ", a[i][j]);
        printf("\n");
    }
}
int find_max_row(double** a, int n, int m) {
    int max_row = 0;
    double max_val = a[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] > max_val) {
                max_val = a[i][j];
                max_row = i;
            }
    return max_row;
}
double** insert_row(double** a, int* n, int m, int pos) {
    double** b = (double**)malloc((*n + 1) * sizeof(double*));
    for (int i = 0; i <= *n; i++)
        b[i] = (double*)malloc(m * sizeof(double));
    for (int i = 0; i <= *n; i++) {
        if (i <= pos)
            for (int j = 0; j < m; j++)
                b[i][j] = a[i][j];
        else if (i == pos + 1)
            for (int j = 0; j < m; j++)
                b[i][j] = 0.0;
        else
            for (int j = 0; j < m; j++)
                b[i][j] = a[i - 1][j];
    }
    for (int i = 0; i < *n; i++)
        free(a[i]);
    free(a);
    (*n)++;
    return b;
}
int main() {
    int N = 4, M = 3;
    srand((unsigned)time(NULL));
    double** A = create_matrix(N, M);
    fill_matrix(A, N, M);
    printf("Початкова матриця:\n");
    print_matrix(A, N, M);
    int max_row = find_max_row(A, N, M);
    A = insert_row(A, &N, M, max_row);
    printf("\nМатриця, після внесених змін:\n", max_row);
    print_matrix(A, N, M);
    for (int i = 0; i < N; i++)
        free(A[i]);
    free(A);
    return 0;
}