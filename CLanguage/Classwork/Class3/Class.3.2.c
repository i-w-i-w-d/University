#include <stdio.h>

int main() {

    int x;
    printf("x = ");
    scanf("%d", &x);
    if (x < 100 || x > 999) {
        printf("Має бути тризначне число!");
        return 1;
    }

    int hundr = x / 100;
    int tens = (x / 10) % 10;
    int ones = x % 10;
    int reversed = ones * 100 + tens * 10 + hundr;
    
    if (hundr == tens || hundr == ones || tens == ones) {
        printf("Є однакові цифри\n");
        return 1;

    } else {
        printf("Всі цифри різні\n");
        printf("Зворотнє число = %d", reversed);
        return 0;
    }
}