#include <stdio.h>
#include <math.h>
int main() {
    int n;
    printf("Натуральне число n: ");
    scanf("%d", &n);
    int a[n];
    printf("Введіть %d цілих чисел: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int k = (int)sqrt(n);
    int even_count = 0;
    printf("\nКвадрати перших %d елементів:\n", k);
    for (int i = 0; i < k; i++) {
        int square = a[i] * a[i];
        printf("a[%d]^2 = %d^2 = %d", i + 1, a[i], square);
        if (square % 2 == 0) {
            printf(" - парне\n");
            even_count++;
        } else {
            printf(" - непарне\n");
        }
    }
    printf("Кількість парних серед квадратів перших %d елементів: %d\n", k, even_count);
}