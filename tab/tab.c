#include <stdio.h>

int main() {
    int tabA[10] = {10, 5, 20, 3, 15, 7, 25, 30, 12, 18};
    int plusGrand = tabA[0];
    int plusPetit = tabA[0];
    int somme = 0;

    for (int i = 1; i < 10; i++) {
        if (tabA[i] > plusGrand) {
            plusGrand = tabA[i];
        }
        if (tabA[i] < plusPetit) {
            plusPetit = tabA[i];
        }
        somme += tabA[i];
    }

    double moyenne = (double)somme / 10;

    printf("Le plus grand entier : %d\n", plusGrand);
    printf("Le plus petit entier : %d\n", plusPetit);
    printf("La moyenne des valeurs du tableau : %.2lf\n", moyenne);

    return 0;
}
