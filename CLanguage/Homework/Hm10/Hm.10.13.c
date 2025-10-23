#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct {
    char surname[30];
    char name[30];
    char position[30];
    char gender[10];
    int day, month, year;
} Employee;
void findMostPopularPosition(Employee p[], int n) {
    int maxCount = 0;
    char bestPosition[30];
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (strcmp(p[i].position, p[j].position) == 0)
                count++;
        if (count > maxCount) {
            maxCount = count;
            strcpy(bestPosition, p[i].position);
        }
    }
    printf("\nа) Посада з найбільшою кількістю співробітників: %s (%d осіб)\n",
           bestPosition, maxCount);
}
void findEmployeesWithSameNames(Employee p[], int n) {
    int found = 0;
    printf("\nб) Співробітники з однаковими іменами:\n");
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (strcmp(p[i].name, p[j].name) == 0)
                count++;
        if (count > 1) {
            printf("  %s %s\n", p[i].surname, p[i].name);
            found = 1;
        }
    }
    if (!found)
        printf("  Немає співробітників з однаковими іменами.\n");
}
void findEmployeesBySurnameLetter(Employee p[], int n, char letter) {
    printf("\nв) Співробітники, прізвища яких починаються з літери '%c':\n", letter);
    int found = 0;
    letter = toupper(letter);
    for (int i = 0; i < n; i++) {
        if (toupper(p[i].surname[0]) == letter) {
            printf("  %s %s\n", p[i].surname, p[i].name);
            found = 1;
        }
    }
    if (!found)
        printf("  Немає співробітників із прізвищем на цю літеру.\n");
}
int main() {
    int n;
    printf("Введіть кількість співробітників: ");
    scanf("%d", &n);
    getchar();
    Employee *p = (Employee*)malloc(n * sizeof(Employee));
    if (!p) {
        printf("Помилка виділення пам’яті!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\nАнкета #%d\n", i + 1);
        printf("Прізвище: "); gets(p[i].surname);
        printf("Ім'я: "); gets(p[i].name);
        printf("Посада: "); gets(p[i].position);
        printf("Стать: "); gets(p[i].gender);
        printf("Дата народження (день місяць рік): ");
        scanf("%d %d %d", &p[i].day, &p[i].month, &p[i].year);
        getchar();
    }
    findMostPopularPosition(p, n);
    findEmployeesWithSameNames(p, n);
    char letter;
    printf("\nВведіть літеру для пошуку прізвищ: ");
    scanf(" %c", &letter);
    findEmployeesBySurnameLetter(p, n, letter);
    free(p);
}