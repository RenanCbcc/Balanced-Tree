/*
 ============================================================================
 Name        : AVL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int count = 10;

	int *p = &count;
	int **p2 = &p;

	printf("Variable count before assignment: %i",count);

	*p = 12;

	printf("\nVariable count after assignment: %i",count);
	printf("\nAddres of count: %p",&count);
	printf("\nVariable p after assignment: %p",p);
	printf("\nVariable p2 after assignment: %p",*p2);
	return EXIT_SUCCESS;
}
