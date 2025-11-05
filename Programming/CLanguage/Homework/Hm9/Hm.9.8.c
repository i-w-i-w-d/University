#include <stdio.h>
#include <math.h>
int main() {
    int n;
    double x[100];
    char choice;
    do {
        printf("Введіть розмірність вектора (не більше 100): ");
        if (scanf("%d", &n) != 1 || n <= 0 || n > 100) break;
        printf("Введіть %d дійсних чисел:\n", n);
        for (int i = 0; i < n; ++i)
            scanf("%lf", &x[i]);
        double sum = 0;
        for (int i = 0; i < n; ++i)
            sum += x[i];
        double mean = sum / n;
        double var_sum = 0;
        for (int i = 0; i < n; ++i)
            var_sum += (x[i] - mean) * (x[i] - mean);
        double variance = var_sum / n;
        printf("Середнє: %.4f\n", mean);
        printf("Дисперсія: %.4f\n", variance);
        printf("Ще один вектор? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}