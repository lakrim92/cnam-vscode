#include <stdio.h>
#include <string.h>

void estPalindrome (char lemot[])
{
    int indexGauche = 0;
    int indexDroit = strlen(lemot) - 1;

    while (indexDroit > indexGauche);
    {
        if (lemot[indexGauche] != lemot[indexDroit])
        {
            printf("%s Ce n'est pas un palindrome\n", lemot);
            return;
        }
        indexGauche++;
        indexDroit--;
    }
    printf("Le mot %s est un palindrome\n", lemot);

}