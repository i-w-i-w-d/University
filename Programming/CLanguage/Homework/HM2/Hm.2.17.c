#include <stdio.h>
#include <math.h>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
    double f = sigmoid(x);
    return f * (1.0 - f);
}

int main() {
    double x;
    printf("x = ");
    scanf_s("%lf", &x);

    double f = sigmoid(x);
    double df = sigmoid_derivative(x);

    printf("sigmoid(%.6f) = %.6f\n", x, f);
    printf("sigmoid_derivative(%.6f) = %.6f\n", x, df);
}