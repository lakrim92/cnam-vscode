#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Structure pour représenter une carte
typedef struct
{
    char couleur[10];
    char type[5];
    int valeur;
} Carte;

// Fonction pour afficher les cartes du joueur et le nombre de cartes restantes
void afficherCartesJoueurEtRestantes(Carte cartes[], int cartesTirees[], int nombreDeCartesTirees, int cartesRestantes)
{
    printf("Cartes tirées par le joueur: ");
    for (int i = 0; i < nombreDeCartesTirees; i++)
    {
        if (cartesTirees[i] == 1)
        {
            printf("%s de %s, ", cartes[i].type, cartes[i].couleur);
        }
    }
    printf("\n");

    printf("Cartes restantes : %d\n", cartesRestantes);
}

int tirerCarte(int *cartesTirees, int min, int max)
{
    int carte;
    do
    {
        carte = (rand() % (max - min + 1)) + min;
    } while (cartesTirees[carte] == 1);
    cartesTirees[carte] = 1;
    return carte;
}

int main()
{
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires

    Carte cartes[52];
    // Initialisation des cartes
    int index = 0;
    for (int couleur = 0; couleur < 4; couleur++)
    {
        for (int valeur = 1; valeur <= 13; valeur++)
        {
            if (couleur == 0)
            {
                strcpy(cartes[index].couleur, "Coeur");
            }
            else if (couleur == 1)
            {
                strcpy(cartes[index].couleur, "Carreau");
            }
            else if (couleur == 2)
            {
                strcpy(cartes[index].couleur, "Trèfle");
            }
            else
            {
                strcpy(cartes[index].couleur, "Pique");
            }

            if (valeur == 1)
            {
                strcpy(cartes[index].type, "As");
                cartes[index].valeur = 11; // L'As vaut 11 ou 1
            }
            else if (valeur >= 10)
            {
                sprintf(cartes[index].type, "10");
                cartes[index].valeur = 10;
            }
            else
            {
                sprintf(cartes[index].type, "%d", valeur);
                cartes[index].valeur = valeur;
            }
            index++;
        }
    }

    int solde = 1000;
    int mise = 0;
    int sommeMainJoueur = 0;
    int sommeMainBanque = 0;
    bool terminer = false;
    int choixMenu;
    bool premierTourMiser = true;
    Carte premiereCarteJoueur;
    Carte deuxiemeCarteJoueur;
    Carte carteHit;
    Carte carteSupplementaireJoueur;
    int tmp;
    Carte carteSupplementaireBanque;
    int tmpBanque;
    Carte premiereCarteBanque;
    Carte deuxiemeCarteBanque;
    int nombreDeDepassements = 0;
    int nombreDeCartesTirees = 0;
    bool premierTour = true; // Pour suivre si c'est le premier tour
    int cartesTirees[52] = {0};

    while (!terminer)
    {
        while (solde > 0 && !terminer)
        {
            // Cacher les cartes du joueur et de la banque au premier tour
            if (premierTour)
            {
                tmp = tirerCarte(cartesTirees, 0, 51);
                int carteIndex = tmp;
                premiereCarteJoueur = cartes[carteIndex];
                cartesTirees[carteIndex] = 1;

                tmp = tirerCarte(cartesTirees, 0, 51);
                carteIndex = tmp;
                deuxiemeCarteJoueur = cartes[carteIndex];
                cartesTirees[carteIndex] = 1;
                sommeMainJoueur = premiereCarteJoueur.valeur + deuxiemeCarteJoueur.valeur;

                printf("    ===============================================================\n");
                afficherCartesJoueurEtRestantes(cartes, cartesTirees, nombreDeCartesTirees, 52 - nombreDeCartesTirees);
                printf("    ===============================================================\n");

                premierTour = false;
            }

            printf("     Solde = %d $                                     Mise = %d $\n", solde, mise);
            printf("    ===============================================================\n");

            // Le reste du code de la boucle principale reste inchangé...

            // ...
        }
    }

    double probabiliteDepassement = (double)nombreDeDepassements / nombreDeCartesTirees;
    printf("    Probabilité de dépassement de 21 : %.0lf%%\n", probabiliteDepassement * 100);
    printf("    ===============================================================\n\n");
    printf("    Good Bye !\n");
    printf("    ===============================================================\n");
    return 0;
}
