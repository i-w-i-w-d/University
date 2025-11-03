#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double x, eps;
    printf("x (|x| < 1) = ");
    scanf_s("%lf", &x);
    printf("Eps = ");
    scanf_s("%lf", &eps);

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