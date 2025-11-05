#include <stdio.h>

int main (){

    unsigned char n;
    printf("n (0 - 6) = ");
    scanf("%hhu", &n);
    if (n < 0 || n > 6){
        printf("Ви ввели недійсне число");
        return 1;
    }
    unsigned char result = 1 << n;
    printf("2^%d = %d", n, result);

}