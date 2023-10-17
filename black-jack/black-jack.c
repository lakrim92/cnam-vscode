#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Structure pour représenter une carte
typedef struct {
    char couleur[10];
    char type[5];
    int valeur;
} Carte;

int tirerCarte(int min, int max)
{
    int resultat = (rand() % (max - min + 1)) + min;
    return resultat;
}

int main()
{
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires

    Carte cartes[52];
    // Initialisation des cartes
    int index = 0;
    for (int couleur = 0; couleur < 4; couleur++) {
        for (int valeur = 1; valeur <= 13; valeur++) {
            if (couleur == 0) {
                sprintf(cartes[index].couleur, "Coeur");
            }
            else if (couleur == 1) {
                sprintf(cartes[index].couleur, "Carreau");
            }
            else if (couleur == 2) {
                sprintf(cartes[index].couleur, "Trèfle");
            }
            else {
                sprintf(cartes[index].couleur, "Pique");
            }

            if (valeur == 1) {
                sprintf(cartes[index].type, "As");
                cartes[index].valeur = 11; // Valeur par défaut de l'As
            }
            else if (valeur >= 10) {
                sprintf(cartes[index].type, "10");
                cartes[index].valeur = 10;
            }
            else {
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
    Carte carteSupplementaire;
    int tmp;
    Carte carteSupplementaireBanque;
    bool tourDeLaBanque = true;
    int tmpBanque;
    Carte premiereCarteBanque;
    Carte deuxiemeCarteBanque;
    int nombreDeDepassements = 0;
    int nombreDeCartesTirees = 0;
    bool premierTour = true; // Pour suivre si c'est le premier tour

    while (solde > 0 && !terminer)
    {
        if (premierTourMiser)
        {
            // Cacher les cartes du joueur et de la banque au premier tour
            if (!premierTour) {

                printf("    ===============================================================\n");
                printf("     Main du joueur      ||          %s de %s et %s de %s\n", premiereCarteJoueur.type, premiereCarteJoueur.couleur, deuxiemeCarteJoueur.type, deuxiemeCarteJoueur.couleur);
                printf("                         ||\n");
                printf("     Main de la banque   ||          %s de %s et %s de %s\n", premiereCarteBanque.type, premiereCarteBanque.couleur, deuxiemeCarteBanque.type, deuxiemeCarteBanque.couleur);
                printf("    ===============================================================\n");
            }
            premierTour = false;
            
            printf("     Solde = %d $                                     Mise = %d $\n", solde, mise);
            printf("    ===============================================================\n");
            
            do {
                scanf("%d", &mise);
                if (mise > solde) {
                    printf("Solde insuffisant. Vous ne pouvez pas miser plus que ce que vous avez. Veuillez réduire votre mise.\n");
                }
            } while (mise > solde);

            premierTourMiser = false;
            
            tmp = tirerCarte(0, 51);
            premiereCarteJoueur = cartes[tmp];
            tmp = tirerCarte(0, 51);
            deuxiemeCarteJoueur = cartes[tmp];
            sommeMainJoueur = premiereCarteJoueur.valeur + deuxiemeCarteJoueur.valeur;

            tmpBanque = tirerCarte(0, 51);
            premiereCarteBanque = cartes[tmpBanque];
            tmpBanque = tirerCarte(0, 51);
            deuxiemeCarteBanque = cartes[tmpBanque];
            sommeMainBanque = premiereCarteBanque.valeur + deuxiemeCarteBanque.valeur;
        }
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

        if (choixMenu == 3)
        {
            terminer = true;
        }
        else if (choixMenu == 1)
        {
            tmp = tirerCarte(0, 51);
            carteHit = cartes[tmp];
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

            tmpBanque = tirerCarte(0, 51);
            carteSupplementaireBanque = cartes[tmpBanque];
            sommeMainBanque += carteSupplementaireBanque.valeur;
            nombreDeCartesTirees++;

            printf("     CARTE AJOUTÉE à la banque :                      %s de %s\n", carteSupplementaireBanque.type, carteSupplementaireBanque.couleur);
            printf("\n");
            printf("    ---------------------------------------------------------------\n");

            if (sommeMainJoueur > 21)
            {
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

                if (choixMenu == 2)
                {
                    terminer = true;
                }
                else
                {
                    sommeMainJoueur = 0;
                    sommeMainBanque = 0;
                    mise = 0;
                    premierTourMiser = true;
                }
            }
        }
        else if (choixMenu == 2)
        {
            while (sommeMainBanque < 21)
            {
                tmpBanque = tirerCarte(0, 51);
                carteSupplementaireBanque = cartes[tmpBanque];
                sommeMainBanque += carteSupplementaireBanque.valeur;
                nombreDeCartesTirees++;
                printf("\n");
                printf("    CARTE AJOUTÉE à la banque : %s de %s\n", carteSupplementaireBanque.type, carteSupplementaireBanque.couleur);
                printf("\n");
            }

            if (solde <= 0)
            {
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

            if (sommeMainBanque > 21)
            {
            printf("    La banque a dépassé 21.\n    Vous avez gagné !\n");
            printf("    ===============================================================\n");
                solde += mise;
            }
            else if (sommeMainBanque > sommeMainJoueur)
            {
                printf("    La banque a un total de %d.\n    Vous avez perdu !\n", sommeMainBanque);
                printf("    ===============================================================\n");
                solde -= mise;
            }
            else if (sommeMainBanque == sommeMainJoueur)
            {
                printf("    La banque a un total de %d.\n   Match nul !\n", sommeMainBanque);
                printf("    ===============================================================\n");
            }
            else
            {
                printf("    La banque a un total de %d.\n   Vous avez gagné !\n", sommeMainBanque);
                printf("    ===============================================================\n");
                solde += mise;
            }

            if (sommeMainBanque > 21)
            {
                nombreDeDepassements--;
            }

            printf("    Nouveau solde : %d\n", solde);
            printf("    ===============================================================\n");
            printf("    Remiser ?\n    1 pour oui\n    2 pour non\n");
            printf("    ===============================================================\n");
            scanf("%d", &choixMenu);

            if (choixMenu == 2)
            {
                terminer = true;
            }
            else
            {
                sommeMainJoueur = 0;
                sommeMainBanque = 0;
                mise = 0;
                premierTourMiser = true;
            }
        }
        if (solde <= 0)
    {
        printf("     Solde insuffisant. Vous ne pouvez pas miser !\n");
        printf("\n");
        printf("    ===============================================================\n");
        terminer = true;
        break; // Sortir de la boucle si le solde est nul
    }
    }

    double probabiliteDepassement = (double)nombreDeDepassements / nombreDeCartesTirees;
    printf("    Probabilité de dépassement de 21 : %.2lf\n", probabiliteDepassement);
    printf("    ===============================================================\n");
    printf("\n");
    printf("    Good Bye !\n");
    printf("\n");
    printf("    ===============================================================\n");
    return 0;
}
