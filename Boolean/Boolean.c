#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool win = false;
    bool sleep = true;

    printf("Win = %d\n", win);
    printf("Sleep = %d\n", sleep);

    bool billFalse = (1 > 2); 
    printf("Bill_False = %d\n", billFalse);

    bool billTrue = (2 > 1); 
    printf("Bill_True = %d\n", billTrue);

    return (0);
}