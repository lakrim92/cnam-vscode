#include <stdio.h>

int main()
{
    int age;
    printf("Quel est votre age ?\n");
    scanf("%d", &age);

    if((age >= 0) && (age < 13)){
        printf("Vous êtes un enfant !");
    } else if(age < 18){
        printf("Vous êtes un ado!");
    } else if(age <= 62) {
        printf("Vous êtes un adulte!");
    } else {
        printf("Vous êtes un senior");
    }
    return (0);
}