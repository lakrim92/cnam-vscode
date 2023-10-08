/* Exercice 3:
Ecrire une boucle For qui affiche 100 fois les “Bonjours”.
Modifier le programme pour qu’il indexes les “Bonjours” par un
entier. Nous devons obtenir en sortie écran:
1 Bonjour
2 Bonjour
3 Bonjour
…
100 Bonjour */

#include <stdio.h>

int main() {
    int N;
    printf("Entrez un entier N : ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
