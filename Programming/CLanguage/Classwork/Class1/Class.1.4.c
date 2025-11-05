#include <stdio.h>
#include <math.h>

int main() {

    double Y = 6.673 * pow(10, -11);
    double m1 = 5.972 * pow(10, 24);
    double m2 = 7.348 * pow(10, 22);
    double r = 3.844 * pow(10, 8);
    double F = (Y * m1 * m2) / (r * r);
    printf("Сила притягання = %.2e Н", F);


}