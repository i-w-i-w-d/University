#include <stdio.h>
#include <math.h>

int main() {
    double radius, height;
    const double PI = acos(-1.0); // acos(Pi) - дає значення -1.0, відповідно Pi = acos(-1.0)

    printf("Радіус основи конуса = ");
    scanf_s("%lf", &radius);
    printf("Висоту конуса = ");
    scanf_s("%lf", &height);

    double volume = (1.0 / 3.0) * PI * pow(radius, 2) * height; // Об'єм конуса: V = (1/3) * π * r² * h

    printf("\nРезультати обчислень:\n");
    printf("Радіус основи: %.2lf\n", radius);
    printf("Висота конуса: %.2lf\n", height);
    printf("Об'єм конуса: %.2lf\n", volume);
}