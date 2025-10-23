#include <stdio.h>

#define SIZE 4

void rotate90Clockwise(int matrix[SIZE][SIZE]) {
    int temp[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[j][SIZE - 1 - i] = matrix[i][j];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = temp[i][j];
}

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int matrix[SIZE][SIZE] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Оригінальна матриця:\n");
    printMatrix(matrix);

    rotate90Clockwise(matrix);

    printf("\nПовернута на 90° за годинниковою стрілкою:\n");
    printMatrix(matrix);
}