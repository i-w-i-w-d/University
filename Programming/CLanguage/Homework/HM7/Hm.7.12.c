#include <stdio.h>
int main() {
    int n;
    printf("Введіть кількість елементів: ");
    scanf("%d", &n);
    int A[n], freq[n];
    int i, j, maxFreq = 0;
    printf("Введіть елементи масиву:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        freq[i] = 1;
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                freq[i]++;
            }
        }
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }
    printf("Мода(N): ");
    for (i = 0; i < n; i++) {
        if (freq[i] == maxFreq) {
            int alreadyPrinted = 0;
            for (j = 0; j < i; j++) {
                if (A[i] == A[j]) {
                    alreadyPrinted = 1;
                    break;
                }
            }
            if (!alreadyPrinted) {
                printf("%d ", A[i]);
            }
        }
    }
    printf("\n");
}