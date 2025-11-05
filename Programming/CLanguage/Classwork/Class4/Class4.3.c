#include <stdio.h>
#include <math.h>

int main (){

    double y;
    double result1 = 0;
    double n = 3;
    double x = 2;
    for (int i = 0; i <= n; i ++){

        y = pow(x, n - i);
        result1 += y;

    }
    printf("(1)Result = %.0f\n", result1);


    double result2 = 0;
    double a = 4;
    double b = 1;
    double c = 2;
    for (int i = 0; i <= a; i++){

        double k = pow(b, pow(2, a - i)) * pow(c, a - i);
        result2 += k;

    }
    printf("(2)Result2 = %.0f", result2);

}