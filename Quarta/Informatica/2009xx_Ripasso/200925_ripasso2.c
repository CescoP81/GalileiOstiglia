#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 100

int riempi_vet(int [], int);

int main(){
	int vet[DIM]; //vet[0] --> vet[9]
	int i;
	srand(time(NULL));
	for(i=0; i<DIM; i++){
		vet[i] = 0;
	}
	
	if(riempi_vet(vet, 0)){
		for(i=0; i<DIM; i++){
			printf("%3d", vet[i]);
		}
	}
	else{
		printf("Problemi con la lunghezza del vettore");
	}
	
	return(0);
}

int riempi_vet(int v[], int l){
	int i;
	if(l<=0 || l>DIM)
		return(0);
	else{
		for(i=0; i<l; i++){
			v[i] = rand()%50 + 1;
		}
		return(1);
	}	
}
