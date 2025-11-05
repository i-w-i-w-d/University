#include <stdio.h>

int main(){

    int x;
    printf("x = ");
    scanf("%d", &x);
    int hundr = x / 100;
    int tens = (x / 10) % 10;
    int ones = x % 10;
    printf("Сотні = %d, десятки = %d, одиниці = %d\n", hundr, tens, ones);

    int sum = hundr + tens + ones;
    printf("Сума = %d\n", sum);

    int reversed = ones * 100 + tens * 10 + hundr;
    printf("Зворотнє число = %d", reversed);

}