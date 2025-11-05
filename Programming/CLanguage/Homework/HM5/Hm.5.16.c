#include <stdio.h>
#include <math.h>

int main() {
    double x, eps;
    printf("x (|x| < 1) = ");
    scanf("%lf", &x);
    printf("Eps = ");
    scanf("%lf", &eps);

    double sum = 0.0;
    double term = x;
    int k = 0;

    while (fabs(term) >= eps) {
        sum += term;
        k++;
        term *= ((2.0 * k - 1) * (2.0 * k - 1) * x * x) / ((2.0 * k) * (2.0 * k + 1));
    }

    printf("arcsin(%lf) ≈ %lf\n", x, sum);
}