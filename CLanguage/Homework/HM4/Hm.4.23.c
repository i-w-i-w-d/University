#include <stdio.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        double y_i;
        printf("y_%d = ", i);
        scanf("%lf", &y_i);

        double z_i;
        if (y_i < 10) {
            z_i = y_i;
        }
        else {
            z_i = 1.0;
        }

        sum += z_i;
    }

    printf("Результат: %.2f\n", sum);
}