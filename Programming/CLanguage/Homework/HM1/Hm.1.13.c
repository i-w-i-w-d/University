#include <stdio.h>
#include <math.h>

int main() {
    double x, result;

    printf("Введіть число: ");
    scanf_s("%lf", &x);

    if (x > 0) {
        result = log10(x);
        printf("log10(%.3f) = %.3f\n", x, result);
    }
    else {
        printf("Число має бути додатним!\n");
    }
}