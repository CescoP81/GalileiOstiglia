#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>

int mediaVettore(int v[], int dimensione){
    int somma=0;
    int i;
    for(i=0;i<dimensione;i++){
        somma=somma+v[i];
    }
    return (somma/dimensione);
}

void valoriSottoMedia(int v[], int dimensione){
    int i;
    for(i=0;i<dimensione;i++){
        if(v[i]<mediaVettore(v, dimensione)){
            printf("%d ",v[i]);
        }
    }
}

int maggioreVettore(int v[], int dimensione){
	int i;
	int maggiore = 0;
	
	for(i=0; i<dimensione; i++){
		if(v[i] > maggiore)
			maggiore = v[i];
	}
	return (maggiore);
}

void scostamentiVettore(int v[], int dimensione){
	int differenza;
	int i;
	
	for	(i=0; i<dimensione; i++){
		differenza = v[i] - maggioreVettore(v, dimensione);
		printf("%d ", differenza);
	}
}

int ordinaVettore(int v[], int dimensione, int modo){
	int i, j;
	int tmp;
	int successo = 0;
	
	if(modo==1){ //ordinamento crescente
		for(i=0; i<dimensione; i++){
			for(j=i; j<dimensione; j++){
				if(v[i] > v[j]){
					tmp = v[i];
					v[i] = v[j];
					v[j] = tmp;
				}
			}
		}
		successo = 1;
	}
	if(modo==0){ //ordinamento decrescente
		for(i=0; i<dimensione; i++){
			for(j=i; j<dimensione; j++){
				if(v[i] < v[j]){
					tmp = v[i];
					v[i] = v[j];
					v[j] = tmp;
				}
			}
		}
		successo = 1;
	}
	return successo;
}









