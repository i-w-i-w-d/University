#include <stdio.h>
#include <math.h>

int main() {
    float f1 = powf(10, -4);
    double d1 = pow(10, -4);
    long double ld1 = powl(10, -4);

    printf("float: 10^-4 = %.2f\n", f1);
    printf("double: 10^-4 = %.2lf\n", d1);
    printf("long double: 10^-4 = %.2lf\n", (double)ld1);

    float f2 = 24.33E5f;
    double d2 = 24.33E5;
    long double ld2 = 24.33E5L;

    printf("float: 24.33E5 = %.2f\n", f2);
    printf("double: 24.33E5 = %.2lf\n", d2);
    printf("long double: 24.33E5 = %.2lf\n", (double)ld2);

    float f3 = 3.14159265358979323846f;
    double d3 = 3.14159265358979323846;
    long double ld3 = 3.14159265358979323846L;

    printf("float: PI = %.2f\n", f3);
    printf("double: PI = %.2lf\n", d3);
    printf("long double: PI = %.2lf\n", (double)ld3);

    float f4 = 2.71828182845904523536f;
    double d4 = 2.71828182845904523536;
    long double ld4 = 2.71828182845904523536L;

    printf("float: e = %.2f\n", f4);
    printf("double: e = %.2lf\n", d4);
    printf("long double: e = %.2lf\n", (double)ld4);

    float f5 = sqrtf(5.0f);
    double d5 = sqrt(5.0f);
    long double ld5 = sqrtl(5.0f);

    printf("float: sqrt5 = %.2f\n", f5);
    printf("double: sqrt5 = %.2lf\n", d5);
    printf("long double: sqrt5 = %.2lf\n", (double)ld5);

    float f6 = logf(100.0f);
    double d6 = log(100.0f);
    long double ld6 = logl(100.0f);

    printf("float: ln(100) = %.2f\n", f6);
    printf("double: ln(100) = %.2lf\n", d6);
    printf("long double: ln(100) = %.2lf\n", (double)ld6);

}