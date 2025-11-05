#include <stdio.h>
#include <math.h>

int main() {

    int a, b, c;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);

    int multiplication = a * b * c;
    int first = pow(2, 10);
    int second = pow(2, 21);

    if (abs(a) <= first && abs(b) <= first && abs(c) <= first) {
        printf("Добуток = %d\n", multiplication);
    } 
    else {
        printf("Числа не повинні перевищувати 2^10\n");
    }

    if (abs(a) <= second && abs(b) <= second && abs(c) <= second) {
        printf("Добуток = %d\n", multiplication);
    } 
    else {
        printf("Числа не повинні перевищувати 2^21\n");
    }

}