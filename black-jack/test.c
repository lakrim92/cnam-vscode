#include <stdio.h>

struct personne
{
    char prenom[50];
    char nom[50];
    float taille;
    int age;
};

int main()
{
    struct personne Georges;

    printf("    ==============================================\n");
    printf("    Entrez le prénom : \n");
    printf("    ==============================================\n");
    scanf("     %s", Georges.prenom);
    printf("    ==============================================\n");

    printf("    Entrez le nom : \n");
    printf("    ==============================================\n");
    scanf("     %s", Georges.nom);
    printf("    ==============================================\n");

    printf("    Entrez l'âge : \n");
    printf("    ==============================================\n");
    scanf("     %d", &Georges.age);
    printf("    ==============================================\n");

    printf("    Entrez la taille (en mètres) : \n");
    printf("    ==============================================\n");
    scanf("     %f", &Georges.taille);
    printf("    ==============================================\n");

    printf("    Informations de la personne :\n");
    printf("    ==============================================\n");
    printf("    Prénom : %s\n", Georges.prenom);
    printf("    ==============================================\n");
    printf("    Nom : %s\n", Georges.nom);
    printf("    ==============================================\n");
    printf("    Âge : %d ans\n", Georges.age);
    printf("    ==============================================\n");
    printf("    Taille : %.2f mètres\n", Georges.taille);
    printf("    ==============================================\n");
    
    printf("    bonjour, j'ai %d ans, je mesure %.2f metres \n    et je me nomme %s %s \n", Georges.age, Georges.taille, Georges.prenom, Georges.nom);
    printf("    ==============================================\n");

    return 0;
}