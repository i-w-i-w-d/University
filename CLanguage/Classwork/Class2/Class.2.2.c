#include <stdio.h>
#include <math.h>

int main () {

    double a, b;
    printf("a, b = ");
    scanf("%lf %lf", &a, &b);
    double aa = a * a;
    double bb = b * b;
    double c = sqrtl(aa + bb);
    printf("c = %.4lf", c);

}