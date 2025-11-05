#include <stdio.h>
#include <math.h>

double solve_sin(int n, double x){

    double result = x;

    for (int i = 0; i < n; i++){

        result = sin(result);

    }
    
    return result;

}

int main() {

    int n;
    printf("n = ");
    scanf("%d", &n);

    double x;
    printf("x = ");
    scanf("%lf", &x);

    double result = solve_sin(n, x);
    printf("Result = %.12f", result);

}