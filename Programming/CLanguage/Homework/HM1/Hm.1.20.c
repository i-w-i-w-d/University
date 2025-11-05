#include <stdio.h>

int main() {
    double A, B, C;

    printf("Введіть три числа: A=xxx.xxx, B=xxExxx, C=xxx.xxxx: ");
    scanf_s("A=%lf, B=%lf, C=%lf", &A, &B, &C);
    
    double arithmetic = (A + B + C) / 3;
    
    double harmonic = 3 / (1 / A + 1 / B + 1 / C);
    
    printf("\nРезультати:\n");
    printf("Середнє арифметичне:\n");
    printf("Фіксована крапка: %.3f\n", arithmetic);
    printf("Науковий формат: %e\n", arithmetic);
    
    printf("Середнє гармонічне:\n");
    printf("Фіксована крапка: %.3f\n", harmonic);
    printf("Науковий формат: %e\n", harmonic);
}