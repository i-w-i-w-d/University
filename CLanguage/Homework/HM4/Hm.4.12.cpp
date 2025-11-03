#include <cstdio>

int main() {
    double x;
    int n;

    printf("Введіть x: ");
    scanf_s("%lf", &x);
    printf("Введіть n: ");
    scanf_s("%d", &n);

    double sum = 0.0;
    int exp = 1;

    for (int i = 0; i <= n; i++) {
        double term = 1.0;
        for (int j = 0; j < exp; j++) {
            term *= x;
        }
        sum += term;
        exp *= 3;
    }

    printf("y = %.f\n", sum);

    return 0;
}