#include <stdio.h>

int main() {
    int TabA[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int valeurTapee;
    int occurrences = 0;

    printf("Entrez un entier : ");
    scanf("%d", &valeurTapee);

    for (int i = 0; i < 8; i++) {
        if (TabA[i] == valeurTapee) {
            occurrences++;
        }
    }

    if (occurrences > 0) {
        printf("Oui, la valeur est présente %d fois.\n", occurrences);
    } else {
        printf("Non, la valeur n'est pas présente dans le tableau.\n");
    }

    return 0;
}
