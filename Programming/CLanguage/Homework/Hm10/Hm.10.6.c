#include <stdio.h>
struct Seminar {
    char predmet[50];
    char vykladach[50];
    int nomer_grupy;
    char den_tyzhdnya[20];
    char hodyny_zanyat[20];
    char audytoriya[20];
};
void vvesty(struct Seminar *s) {
    printf("Введіть предмет: ");
    fgets(s->predmet, sizeof(s->predmet), stdin);
    printf("Введіть викладача: ");
    fgets(s->vykladach, sizeof(s->vykladach), stdin);
    printf("Введіть номер групи: ");
    scanf("%d", &s->nomer_grupy);
    getchar();
    printf("Введіть день тижня: ");
    fgets(s->den_tyzhdnya, sizeof(s->den_tyzhdnya), stdin);
    printf("Введіть години занять: ");
    fgets(s->hodyny_zanyat, sizeof(s->hodyny_zanyat), stdin);
    printf("Введіть аудиторію: ");
    fgets(s->audytoriya, sizeof(s->audytoriya), stdin);
}
void vyvesty(struct Seminar s) {
    printf("\n--- Інформація про семінар ---\n");
    printf("Предмет: %s", s.predmet);
    printf("Викладач: %s", s.vykladach);
    printf("Номер групи: %d\n", s.nomer_grupy);
    printf("День тижня: %s", s.den_tyzhdnya);
    printf("Години занять: %s", s.hodyny_zanyat);
    printf("Аудиторія: %s", s.audytoriya);
}
int main() {
    struct Seminar seminar;   
    vvesty(&seminar);
    vyvesty(seminar);
}