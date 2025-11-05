#include <stdio.h>

int main (){

    int n;
    unsigned int k;
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%u", &k);

    int result = n | (1 << k);

    printf("Result = %d", result);

}