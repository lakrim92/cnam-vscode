#include <stdio.h>

int main() {
    int TabA[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int valeurTapee;
    int presente = 0; 

    printf("Entrez un entier : ");
    scanf("%d", &valeurTapee);

    for (int i = 0; i < 8; i++) {
        if (TabA[i] == valeurTapee) {
            presente = 1;
            break;
        }
    }

    if (presente) {
        printf("Oui\n");
    } else {
        printf("Non\n");
    }

    return 0;
}
