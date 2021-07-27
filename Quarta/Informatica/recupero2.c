#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int a;
	int *pa;
	int **ppa;
	
	a = 7;		// assegno 7 alla variabile a;
	pa = &a;	// assegno l'indirizzo di 'a' al puntatore pa.
	
	printf("A: %d\n", a);
	printf("PA: %d\n", pa);
	printf("*PA: %d\n", *pa);
	
	*pa = 19;
	printf("\n\nA: %d\n", a);
	printf("PA: %d\n", pa);
	printf("*PA: %d\n", *pa);
	
	
	ppa = &pa;
	*(*ppa) = 21;
	printf("\n\nA: %d\n", a);
	printf("PA: %d\n", pa);
	printf("*PPA: %d\n", *pa);
	
	
	return(0);
}
