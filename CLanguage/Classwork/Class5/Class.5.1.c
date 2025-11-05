#include <stdio.h>

void find_first_greater_recursive(double a, int n, double sum, int *result_n, double *result_sum) {
    
    if (sum > a){

        *result_n = n;
        *result_sum = sum;
        return;

    }

    find_first_greater_recursive(a, n + 1, sum + 1.0 / (n + 1), result_n, result_sum);

}

int main () {

    double a;
    printf("a = ");
    scanf("%lf", &a);

    int result_n;
    double result_sum;
    find_first_greater_recursive(a, 0, 0.0, &result_n, &result_sum);

    printf("Result = %.12lf\n", result_sum);
    printf("n = %d", result_n);

}