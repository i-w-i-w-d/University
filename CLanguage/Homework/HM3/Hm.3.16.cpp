#include <cstdio>
#include <cmath>

int main() {
    double x1, y1, r1;
    double x2, y2, r2;

    printf("(x1 y1 r1) = ");
    scanf_s("%lf %lf %lf", &x1, &y1, &r1);

    printf("(x2 y2 r2) = ");
    scanf_s("%lf %lf %lf", &x2, &y2, &r2);

    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    if (distance > r1 + r2) {
        printf("Кола не перетинаються\n");
    }
    else if (distance < fabs(r1 - r2)) {
        printf("Одне коло знаходиться в середині іншого\n");
    }
    else if (distance == 0 && r1 == r2) {
        printf("Кола співпадають\n");
    }
    else if (distance == r1 + r2 || distance == fabs(r1 - r2)) {
        printf("Мають одну точку дотику\n");
    }
    else {
        printf("Кола мають дві точки дотику\n");
    }
}