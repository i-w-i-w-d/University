
#include <stdio.h>
#include <math.h>

double sinc(double x) {
    if (x == 0.0) {
        return 1.0;
    }
    return sin(x) / x;
}

double sinc_derivative(double x) {
    if (x == 0.0) {
        return 0.0;
    }
    return (x * cos(x) - sin(x)) / (x * x);
}

int main() {
    int count;

    printf("Скільки різних чисел обчислити: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        double x;
        printf("\nx = ", i + 1);
        scanf("%lf", &x);

        double s = sinc(x);
        double d = sinc_derivative(x);

        printf("sinc(%.6f) = %.6f\n", x, s);
        printf("sinc_derivative(%.6f) = %.6f\n", x, d);
    }
}
