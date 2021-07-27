#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

#define DIM 10

int main(){
	char str[DIM] = {'c','i','a','o','\0'};
	char str2[DIM];
	int i;
	
	// inizializzo la stringa da codice
	i = 0;
	while(str[i]!='\0'){
		printf("%c", str[i++]);
	}
	
	// Ma cosa contiene in effetti tutto il vettore??
	printf("\n\n");
	for(i=0; i<DIM; i++){
		if(str[i]!='\0')
			printf("%c", str[i]);
		else
			printf("#");
	}
	
	// Acquisisco la stringa da tastiera con la scnaf()
	printf("\n\n");
	for(i=0; i<DIM; i++){
		if(str2[i]!='\0')
			printf("%c", str2[i]);
		else
			printf("#");
	}
	printf("\n");
	printf("Stringa: ");
	scanf("%s", &str2);
	fflush(stdin);
	printf("%s\n", str2);
	
	for(i=0; i<DIM; i++){
		if(str2[i]!='\0')
			printf("%c", str2[i]);
		else
			printf("#");
	}
	return(0);
}
