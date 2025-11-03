#include <stdio.h>
#include <stdlib.h>
void createFileF(const char *filename) {
    int data[] = {5, 7, -3, -2, 4, 8, -6, -1, -4, 2};
    int size = sizeof(data) / sizeof(data[0]);
    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("Помилка fopen для F.txt");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        fprintf(f, "%d\n", data[i]);
    }
    fclose(f);
}
int checkBalance(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Помилка fopen для перевірки балансу.");
        exit(1);
    }
    int num, pos = 0, neg = 0;
    while (fscanf(f, "%d", &num) == 1) {
        if (num > 0) pos++;
        else if (num < 0) neg++;
    }
    fclose(f);
    return pos == neg;
}
void rewritePattern(const char *fileF, const char *fileG, const char *fileH) {
    FILE *f = fopen(fileF, "r");
    FILE *g = fopen(fileG, "w");
    FILE *h = fopen(fileH, "w");
    if (!f || !g || !h) {
        perror("Помилка fopen при переписуванні.");
        exit(1);
    }
    int pos[100], neg[100];
    int p = 0, n_ = 0, num;
    while (fscanf(f, "%d", &num) == 1) {
        if (num > 0) pos[p++] = num;
        else if (num < 0) neg[n_++] = num;
    }
    int i = 0, j = 0;
    int written = 0;
    while (i + 1 < p && j + 1 < n_) {
        fprintf(g, "%d\n", pos[i]);
        fprintf(g, "%d\n", pos[i + 1]);
        fprintf(g, "%d\n", neg[j]);
        fprintf(g, "%d\n", neg[j + 1]);
        fprintf(h, "%d %d\n", pos[i], pos[i + 1]);
        fprintf(h, "%d %d\n", neg[j], neg[j + 1]);
        i += 2;
        j += 2;
        written += 4;
    }
    int leftovers[2], count = 0;
    if (i < p) leftovers[count++] = pos[i];
    if (i + 1 < p) leftovers[count++] = pos[i + 1];
    if (j < n_ && count < 2) leftovers[count++] = neg[j];
    if (j + 1 < n_ && count < 2) leftovers[count++] = neg[j + 1];
    if (count > 0) {
        printf("Неможливо продовжити, останні числа:\n");
        for (int k = 0; k < count; k++) {
            printf("%d\n", leftovers[k]);
        }
    }
    fclose(f);
    fclose(g);
    fclose(h);
}
int main() {
    const char *fileF = "C:\\Users\\i_w_i_w_d\\Programming\\University\\F.txt";
    const char *fileG = "C:\\Users\\i_w_i_w_d\\Programming\\University\\G.txt";
    const char *fileH = "C:\\Users\\i_w_i_w_d\\Programming\\University\\H.txt";
    createFileF(fileF);
    if (!checkBalance(fileF)) {
        printf("Кількість додатних та від’ємних чисел не збігається.\n");
        return 0;
    }
    rewritePattern(fileF, fileG, fileH);
    printf("Файл G створено.\n");
}