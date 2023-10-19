#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Structure pour représenter une carte
typedef struct {
    char couleur[10];
    char type[5];
    int valeur;
} Carte;

// Fonction pour afficher les cartes du tableau
void afficherCartesJoueurEtRestantes(Carte cartes[], int cartesTirees[], int nombreDeCartes) {
    printf("Cartes tirées par le joueur: \n");
    for (int i = 0; i < nombreDeCartes; i++) {
        if (cartesTirees[i] == 1) {
            printf("%s de %s, \n", cartes[i].type, cartes[i].couleur);
        }
    }
    printf("\n");

    printf("Cartes restantes : %d\n", 52 - nombreDeCartes);
}

int tirerCarte(int* cartesTirees) {
    int carte;
    do {
        carte = rand() % 52; // Génération aléatoire d'un index de carte entre 0 et 51
    } while (cartesTirees[carte] == 1);
    cartesTirees[carte] = 1;
    return carte;
}

int main() {
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires

    Carte cartes[52];
    // Initialisation des cartes
    int index = 0;
    for (int couleur = 0; couleur < 4; couleur++) {
        for (int valeur = 1; valeur <= 13; valeur++) {
            if (couleur == 0) {
                strcpy(cartes[index].couleur, "Coeur");
            } else if (couleur == 1) {
                strcpy(cartes[index].couleur, "Carreau");
            } else if (couleur == 2) {
                strcpy(cartes[index].couleur, "Trèfle");
            } else {
                strcpy(cartes[index].couleur, "Pique");
            }

            if (valeur == 1) {
                strcpy(cartes[index].type, "As");
                cartes[index].valeur = 1; // L'As vaut 11 ou 1
            } else if (valeur >= 10) {
                strcpy(cartes[index].type, "10");
                cartes[index].valeur = 10;
            } else {
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
    int cartesTirees[52] = {0}; // 0 signifie que la carte n'a pas encore été tirée

    while (!terminer) {
        while (solde > 0 && !terminer) {
            if (premierTourMiser) {
                // Cacher les cartes du joueur et de la banque au premier tour
                if (!premierTour) {
                    printf("    ===============================================================\n");
                    afficherCartesJoueurEtRestantes(cartes, cartesTirees, nombreDeCartesTirees);
                    printf("    ===============================================================\n");
                }
                premierTour = false;

                printf("     Solde = %d $                                     Mise = %d $\n", solde, mise);
                printf("    ===============================================================\n");

                int carteIndex = tirerCarte(cartesTirees);
                premiereCarteJoueur = cartes[carteIndex];
                sommeMainJoueur = premiereCarteJoueur.valeur;
                
                carteIndex = tirerCarte(cartesTirees);
                deuxiemeCarteJoueur = cartes[carteIndex];
                sommeMainJoueur += deuxiemeCarteJoueur.valeur;

                do {
                    scanf("%d", &mise);
                    if (mise > solde) {
                        printf("Solde insuffisant. Vous ne pouvez pas miser !\n");
                    }
                } while (mise > solde);

                premierTourMiser = false;

                carteIndex = tirerCarte(cartesTirees);
                premiereCarteBanque = cartes[carteIndex];
                
                carteIndex = tirerCarte(cartesTirees);
                deuxiemeCarteBanque = cartes[carteIndex];
                sommeMainBanque = premiereCarteBanque.valeur + deuxiemeCarteBanque.valeur;
            }
            printf("    ===============================================================\n");
            afficherCartesJoueurEtRestantes(cartes, cartesTirees, nombreDeCartesTirees);
            printf("    ===============================================================\n");

            printf("     Main du joueur      ||           %s de %s et %s de %s\n", premiereCarteJoueur.type, premiereCarteJoueur.couleur, deuxiemeCarteJoueur.type, deuxiemeCarteJoueur.couleur);
            printf("                         ||\n");
            printf("     Total               ||           %d      \n", sommeMainJoueur);
            printf("    ---------------------------------------------------------------\n");
            printf("     Main de la banque   ||           %s de %s et %s de %s\n", premiereCarteBanque.type, premiereCarteBanque.couleur, deuxiemeCarteBanque.type, deuxiemeCarteBanque.couleur);
            printf("                         ||\n");
            printf("     Total               ||           %d      \n", sommeMainBanque);
            printf("    ===============================================================\n");
            printf("                            1. Hit\n");
            printf("                            2. Stand\n");
            printf("                            3. Quit\n");
            printf("    ===============================================================\n");
            scanf("%d", &choixMenu);

            if (choixMenu == 3) {
                terminer = true;
            } else if (choixMenu == 1) {
                int carteIndex = tirerCarte(cartesTirees);
                carteHit = cartes[carteIndex];
                sommeMainJoueur += carteHit.valeur;
                nombreDeCartesTirees++;

                printf("    ===============================================================\n");
                printf("\n");
                printf("     Mise = %d $                                    solde = %d $\n", mise, solde - mise);
                printf("\n");
                printf("    ===============================================================\n");
                printf("\n");
                printf("     CARTE AJOUTÉE au joueur :                        %s de %s\n", carteHit.type, carteHit.couleur);
                printf("\n");
                printf("    ---------------------------------------------------------------\n");

                carteIndex = tirerCarte(cartesTirees);
                carteSupplementaireBanque = cartes[carteIndex];
                sommeMainBanque += carteSupplementaireBanque.valeur;
                nombreDeCartesTirees++;

                printf("     CARTE AJOUTÉE à la banque :                      %s de %s\n", carteSupplementaireBanque.type, carteSupplementaireBanque.couleur);
                printf("\n");
                printf("    ---------------------------------------------------------------\n");

                if (sommeMainJoueur > 21) {
                    nombreDeDepassements++;
                    printf("\n");
                    printf("                  La somme de votre main a dépassé 21.\n                           Vous avez perdu!\n");
                    printf("\n");
                    printf("    ===============================================================\n");
                    solde -= mise;

                    printf("     Nouveau solde : %d\n", solde);
                    printf("\n");
                    printf("    ===============================================================\n");
                    printf("\n");
                    printf("                                Remiser ?\n                               1 pour oui\n                               2 pour non\n");
                    printf("\n");
                    printf("    ===============================================================\n");
                    scanf("%d", &choixMenu);

                    if (choixMenu == 2) {
                        terminer = true;
                    } else {
                        sommeMainJoueur = 0;
                        sommeMainBanque = 0;
                        mise = 0;
                        premierTourMiser = true;
                    }
                }
            } else if (choixMenu == 2) {
                while (sommeMainBanque < 17) {  // La banque tire des cartes jusqu'à atteindre au moins 17
                    int carteIndex = tirerCarte(cartesTirees);
                    carteSupplementaireBanque = cartes[carteIndex];
                    sommeMainBanque += carteSupplementaireBanque.valeur;
                    nombreDeCartesTirees++;
                    printf("\n");
                    printf("    CARTE AJOUTÉE à la banque : %s de %s\n", carteSupplementaireBanque.type, carteSupplementaireBanque.couleur);
                    printf("\n");
                }

                if (solde <= 0) {
                    printf("Vous n'avez plus de provision ! \n Good Bye !");
                    terminer = true;
                }

                printf("    ===============================================================\n");
                printf("    Main du joueur      ||          %s de %s et %s de %s\n", premiereCarteJoueur.type, premiereCarteJoueur.couleur, deuxiemeCarteJoueur.type, deuxiemeCarteJoueur.couleur);
                printf("                        ||\n");
                printf("    Total               ||          %d      \n", sommeMainJoueur);
                printf("    ---------------------------------------------------------------\n");
                printf("    Main de la banque   ||          %s de %s et %s de %s\n", premiereCarteBanque.type, premiereCarteBanque.couleur, deuxiemeCarteBanque.type, deuxiemeCarteBanque.couleur);
                printf("                        ||\n");
                printf("    Total de la banque  ||          %d\n", sommeMainBanque);
                printf("    ===============================================================\n");

                if (sommeMainBanque > 21) {
                    printf("    La banque a dépassé 21.\n    Vous avez gagné !\n");
                    printf("    ===============================================================\n");
                    solde += mise;
                } else if (sommeMainBanque > sommeMainJoueur) {
                    printf("    La banque a un total de %d.\n    Vous avez perdu !\n", sommeMainBanque);
                    printf("    ===============================================================\n");
                    solde -= mise;
                } else if (sommeMainBanque == sommeMainJoueur) {
                    printf("    La banque a un total de %d.\n   Match nul !\n", sommeMainBanque);
                    printf("    ===============================================================\n");
                } else {
                    printf("    La banque a un total de %d.\n   Vous avez gagné !\n", sommeMainBanque);
                    printf("    ===============================================================\n");
                    solde += mise;
                }

                if (sommeMainBanque > 21) {
                    nombreDeDepassements--;
                }

                printf("    Nouveau solde : %d\n", solde);
                printf("    ===============================================================\n");
                printf("    Remiser ?\n    1 pour oui\n    2 pour non\n");
                printf("    ===============================================================\n");
                scanf("%d", &choixMenu);

                if (choixMenu == 2) {
                    terminer = true;
                } else {
                    sommeMainJoueur = 0;
                    sommeMainBanque = 0;
                    mise = 0;
                    premierTourMiser = true;
                }
            }
            if (solde <= 0) {
                printf("     Solde insuffisant. Vous ne pouvez pas miser !\n");
                printf("\n");
                printf("    ===============================================================\n");
                terminer = true;
                break; // Sortir de la boucle si le solde est nul
            }
        }
    }

    double probabiliteDepassement = (double)nombreDeDepassements / nombreDeCartesTirees;
    printf("    Probabilité de dépassement de 21 : %.0lf%%\n", probabiliteDepassement * 100);
    printf("    ===============================================================\n\n");
    printf("    Good Bye !\n");
    printf("    ===============================================================\n");
    return 0;
}

