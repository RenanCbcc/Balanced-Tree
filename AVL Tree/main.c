#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 10;

    int *p = &count;
    int **p2 = &p;
    *p = 12;

    printf("Tests before the execution");
    printf("\nAddres of count: %p",&count);
    printf("\nContent of p: %p",p);
    printf("\nAddres of p: %p",&p);
    printf("\nContent of p2: %p",p2);

    printf("\nSize of int: %i", sizeof(int));
    return EXIT_SUCCESS;

}