#include <stdio.h>
#include <math.h>

int main() {

    double a, b, c;
    printf("a, b, c = ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double p = (a + b + c) / 2;
    double S = sqrtl(p * (p - a) * (p - b) * (p - c));
    printf("S = %.4lf", S);

}