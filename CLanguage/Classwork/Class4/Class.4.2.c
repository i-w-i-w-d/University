#include <stdio.h>

int main() {

    int n;
    printf("n = ");
    scanf("%d", &n);

    printf("%d! = ", n);

    for (int i = 1; i <= n; i++){

        printf("%d", i);
        if (i < n){

            printf(" * ");

        }

    }

    printf("\n%d! = ", n);

    for (int i = n; i >= 1; i--){

        printf("%d", i);
        if (i > 1){
            
            printf(" * ");

        }

    }

}