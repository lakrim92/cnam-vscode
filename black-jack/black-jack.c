#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int tirerCarte(int min, int max)
{
    int resultat = (rand() % (max - min + 1)) + min;
    return resultat;
}

int main()
{
    int cartes[52] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int solde = 1000;
    int mise = 0;
    int sommeMainJoueur = 0;
    int sommeMainBanque = 0;
    bool terminer = false;
    int choixMenu;
    bool premierTourMiser = true;
    int premiereCarteJoueur;
    int deuxiemeCarteJoueur;
    int carteHit;
    int carteSupplementaire;
    int tmp;
    int carteSupplementaireBanque;
    bool tourDeLaBanque = true;
    int tmpBanque;
    int premiereCarteBanque;
    int deuxiemeCarteBanque;
    int nombreDeDepassements = 0;
    int nombreDeCartesTirees = 0;

    while (!terminer)
    {
        if (premierTourMiser)
        {
            printf("    ========================================\n");
            printf("     Solde = %d $              Mise = %d $\n", solde, mise);
            printf("    ========================================\n");
            scanf("%d", &mise);
            premierTourMiser = false;
            tmp = tirerCarte(0, 51);
            premiereCarteJoueur = cartes[tmp];
            tmp = tirerCarte(0, 51);
            deuxiemeCarteJoueur = cartes[tmp];
            sommeMainJoueur = premiereCarteJoueur + deuxiemeCarteJoueur;

            tmpBanque = tirerCarte(0, 51);
            premiereCarteBanque = cartes[tmpBanque];
            tmpBanque = tirerCarte(0, 51);
            deuxiemeCarteBanque = cartes[tmpBanque];
            sommeMainBanque = premiereCarteBanque + deuxiemeCarteBanque;
        }
        printf("    ========================================\n");
        printf("    Mise = %d $               solde = %d $\n", mise, solde - mise);
        printf("    ========================================\n");
        printf("    Main du joueur      ||          %d et %d\n", premiereCarteJoueur, deuxiemeCarteJoueur);
        printf("    Total               ||          %d      \n", sommeMainJoueur);
        printf("    ----------------------------------------\n");
        printf("    Main de la banque   ||          %d et %d\n", premiereCarteBanque, deuxiemeCarteBanque);
        printf("    Total               ||          %d      \n", sommeMainBanque);
        printf("    ========================================\n");
        printf("    1. Hit\n");
        printf("    2. Stand\n");
        printf("    3. Quit\n");
        printf("    ========================================\n");

        scanf("%d", &choixMenu);

        if (choixMenu == 3)
        {
            terminer = true;
        }
        else if (choixMenu == 1)
        {
            tmp = tirerCarte(0, 51);
            carteSupplementaire = cartes[tmp];
            sommeMainJoueur += carteSupplementaire;
            nombreDeCartesTirees++;
            printf("    CARTE AJOUTÉE : %d\n", carteSupplementaire);
            
            if (sommeMainJoueur > 21) {
                nombreDeDepassements++;
            }

            if (sommeMainJoueur > 21)
            {
                printf("    La somme de votre main a depasseé 21.\n    Vous avez perdu!\n");
                printf("    ========================================\n");
                solde -= mise;
                printf("    Nouveau solde : %d\n", solde);
                printf("    ========================================\n");
                printf("    Remiser ?\n    1 pour oui\n    2 pour non\n");
                printf("    ========================================\n");

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
            while (sommeMainBanque < 17)
            {
                tmpBanque = tirerCarte(0, 51);
                carteSupplementaireBanque = cartes[tmpBanque];
                sommeMainBanque += carteSupplementaireBanque;
                nombreDeCartesTirees++;
            }

            printf("    ========================================\n");
            printf("    Main du joueur      ||          %d et %d\n", premiereCarteJoueur, deuxiemeCarteJoueur);
            printf("    Total               ||          %d      \n", sommeMainJoueur);
            printf("    ----------------------------------------\n");

            printf("    Main de la banque   ||          %d et %d\n", premiereCarteBanque, deuxiemeCarteBanque);
            printf("    Total de la banque  ||          %d\n", sommeMainBanque);
            printf("    ========================================\n");

            if (sommeMainBanque > 21)
            {
                printf("    La banque a dépassé 21.\n   Vous avez gagné !\n");
                printf("    ========================================\n");
                solde += mise;
            }
            else if (sommeMainBanque > sommeMainJoueur)
            {
                printf("    La banque a un total de %d.\n   Vous avez perdu !\n", sommeMainBanque);
                printf("    ========================================\n");
                solde -= mise;
            }
            else if (sommeMainBanque == sommeMainJoueur)
            {
                printf("    La banque a un total de %d.\n   Match nul !\n", sommeMainBanque);
                printf("    ========================================\n");
            }
            else
            {
                printf("    La banque a un total de %d.\n    Vous avez gagné !\n", sommeMainBanque);
                printf("    ========================================\n");
                solde += mise;
            }

            if (sommeMainBanque > 21) {
                nombreDeDepassements--;
            }

            printf("    Nouveau solde : %d\n", solde);
            printf("    ========================================\n");
            printf("    Remiser ?\n    1 pour oui\n    2 pour non\n");
            printf("    ========================================\n");

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

    double probabiliteDepassement = (double)nombreDeDepassements / nombreDeCartesTirees;
    printf("Probabilité de dépassement de 21 : %.2lf\n", probabiliteDepassement);

    printf("Good Bye !");
    return 0;
}

