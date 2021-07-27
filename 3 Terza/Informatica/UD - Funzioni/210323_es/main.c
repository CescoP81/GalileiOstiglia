/*esercitazione sulle funzioni e sui vettori*/
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"funzioni.c"
#define DIM 10

int main(){
    int vet[DIM];
    int i;
    srand(time(NULL));

    for(i=0;i<DIM;i++){
        vet[i]=rand()%20+1;
    }
    for(i=0;i<DIM;i++){
       printf("%d ",vet[i]);
    }
    printf("\n");
    printf("media del vettore: %d", mediaVettore(vet, DIM));

    printf("\n");
    valoriSottoMedia(vet, DIM);
    printf("\n");
    
    printf("valore maggiore: %d ", maggioreVettore(vet,DIM));
 	printf("\n");
	scostamentiVettore(vet, DIM);
	
	printf("\n");
	if(ordinaVettore(vet, DIM, 3) == 1){
		for(i=0;i<DIM;i++){
	       printf("%d ",vet[i]);
	   }	
	} else{
		printf("modo di ordinamento non valido");
	}
	printf("\n");
	if(ordinaVettore(vet, DIM, 4) == 1){
		for(i=0;i<DIM;i++){
	       printf("%d ",vet[i]);
	    }
	}
	else{
		printf("modo di ordinamento non valido");
	}
    return 0;
}

