#include <stdio.h>

double findElement(int n) {
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1.5;

    double v0 = 0, v1 = 0, v2 = 1.5;
    double vi = 0;

    for (int i = 3; i <= n; i++) {
        vi = ((i - 2.0) / ((i - 3.0) * (i - 3.0) + 1.0)) * v2
            - v1 * v0 + 1.0;

        v0 = v1;
        v1 = v2;
        v2 = vi;
    }

    return vi;
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    double result = findElement(n);
    printf("v[%d] = %.2f\n", n, result);
}