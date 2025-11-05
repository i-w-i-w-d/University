#include <stdio.h>
#include <stdbool.h>

void checkBits(unsigned int a, unsigned int b) {
    bool found = false;
    printf("Однакові біти на таких позиціях: ");
    for (int i = 0; i < 32; i++) {
        unsigned int bitA = (a >> i) & 1;
        unsigned int bitB = (b >> i) & 1;
        if (bitA == bitB) {
            printf("%d ", i);
            found = true;
        }
    }
    if (!found) {
        printf("Немає");
    }
    printf("\n");
}

int main() {
    unsigned int m, n;
    printf("m = ");
    scanf("%u", &m);
    printf("n = ");
    scanf("%u", &n);
    checkBits(m, n);
}