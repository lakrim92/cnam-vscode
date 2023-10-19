#include <stdio.h>

int main() {
    int var = 10;
    printf("%d\n", var); // Output: Value of variable is 20
    printf("\n");
    printf("===========================================\n");
    printf("\n");
    int* ptr = &var;
    *ptr = 20;
    printf("%d\n", *ptr); // prints: 20
    printf("\n");
    printf("===========================================\n");

    return 0;
}
