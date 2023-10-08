#include <stdio.h>

int main() 
{
    printf("La note ?\n");

    int note;
    scanf("%d", &note);

    if((note >= 0) && (note < 7)) {
        printf("Niveau F \n");
    } else if((note >= 7) && (note < 10)) {
        printf("Niveau E\n");
    } else if((note >= 10) && (note < 15)) {
        printf("Niveau B \n");
    } else if((note >= 15) && (note <= 20)) {
        printf("Niveau A\n");
    } else {
        printf("Note non valide!\n");
    }
    printf("Au revoir \n");
    return (0);
}