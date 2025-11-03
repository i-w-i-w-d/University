#include <cstdio>
using namespace std;

int main() {
    unsigned int m, n;
    scanf_s("%u %u", &m, &n);

    unsigned int commonOnes = m & n;
    int countOnes = 0;
    while (commonOnes) {
        countOnes += commonOnes & 1;
        commonOnes >>= 1;
    }

    unsigned int sameBits = ~(m ^ n);
    int countSame = 0;
    for (int i = 0; i < 32; i++) {
        countSame += (sameBits >> i) & 1;
    }

    printf("Спільні одиниці: %d\n", countOnes);
    printf("Співпадіння бітів: %d\n", countSame);
}