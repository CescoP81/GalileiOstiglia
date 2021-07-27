#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

void init_vet(int []);
void stampa_vet(int []);
int media_vet(int []);
void max_e_pos(int [], int *, int *);

int main(){
	srand(time(NULL));
	int vet[DIM]={0};
	int scelta;
	
	do{
		printf("1- Inizializza vettore\n");
		printf("2- Visualizza vettore\n");
		printf("3- Media vettore\n");
		printf("4- Max e Pos\n");
		
		printf("0- Uscita\n");
		printf("Scelta: ");
		scanf("%d", &scelta);
		fflush(stdin);
		printf("\n\n");
		switch(scelta){
			case 1:{
				init_vet(vet);
				printf("Vettore generato...");
				break;
			}
			case 2:{
				printf("Vettore: ");
				stampa_vet(vet);
				break;
			}
			case 3:{
				printf("Media: %d", media_vet(vet));
				break;
			}
			case 4:{
				int max, pos;
				max_e_pos(vet, &max, &pos);
				printf("Massimo: %d in posizione %d\n",max,pos+1);
				break;
			}
			case 0:{
				printf("Programma terminato!\n");
				break;
			}	
		}
		getchar();
	}while(scelta != 0);
	return(0);
}

// PARTE DI DEFINIZIONE DELLE FUNZIONI
void init_vet(int v[]){
	int i;
	for(i=0; i<DIM; i++){
		v[i] = rand()%20 + 1; 
	}	
}

void stampa_vet(int v[]){
	int i;
	for(i=0; i<DIM; i++){
		printf("%3d", v[i]);
	}
}

int media_vet(int v[]){
	int i;
	int somma;
	int media;
	
	somma = 0;
	media = 0;
	for(i=0; i<DIM; i++){
		somma = somma + v[i];	
	}
	media = somma / DIM;
	
	return(media);
}

void max_e_pos(int v[], int *m, int *p){
	int i;
	
	*m = v[0];
	*p = 0;
	for(i=1; i<DIM; i++){
		if(v[i] > *m){
			*m = v[i];
			*p = i;
		}
	}
}





