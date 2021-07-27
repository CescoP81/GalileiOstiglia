#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

int riempi_vet(int [], int);
void stampa_vet(int [], int);
void ordina_vet(int [], int, int);
int media_vet(int [], int);
void vedi_mag_media(int [], int, int);

int main(){
	int vet[DIM];
	int media;
	srand(time(NULL));
	
	if(riempi_vet(vet, DIM) == 0){
		printf("Errore in inizializzazione vettore...\n");
	}
	stampa_vet(vet, DIM);
	ordina_vet(vet, DIM, 2);
	stampa_vet(vet, DIM);
	media = media_vet(vet, DIM);
	printf("Media Vettore: %d\n", media);
	vedi_mag_media(vet, DIM, media_vet(vet, DIM));
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

void stampa_vet(int v[], int l){
	int i;
	for(i=0; i<l; i++){
		printf("%3d", v[i]);
	}
	printf("\n");
}

/**
	Funzione di ordinamento di un vettore.
	@param v[] vettore
	@param l	int lunghezza.
	@param modo int 1 crescente, 2 decrescete
	@return void
*/
void ordina_vet(int v[], int l, int modo){
	int i,j,box;
	if(modo == 1){
		for(i=0; i<l; i++){
			for(j=i; j<l; j++){
				if(v[i] > v[j]){ // ordinamento crescente.
					box = v[i];
					v[i] = v[j];
					v[j] = box;
				}
			}
		}
	}
	if(modo == 2){
		for(i=0; i<l; i++){
			for(j=i; j<l; j++){
				if(v[i] < v[j]){ // ordinamento crescente.
					box = v[i];
					v[i] = v[j];
					v[j] = box;
				}
			}
		}
	}	
}

int media_vet(int v[], int l){
	int somma;
	int i;
	somma = 0;
	for(i=0; i<l; i++){
		somma = somma + v[i];
	}
	somma = somma / l;
	return(somma);
}

void vedi_mag_media(int v[], int l, int med){
	int i;
	for(i=0; i<l; i++){
		if(v[i] > med)
			printf("%3d", v[i]);
		else
			printf(" ***");
	}
	printf("\n");
}
