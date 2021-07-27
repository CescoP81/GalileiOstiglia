/*
Realizzare un programma che inizializza un vettore di 10 elementi interi 
compresi tra 1 e 100, visualizza il vettore, determina la posizione del valore maggiore.
Calcola e comunica il valor medio. Scambia due celle del vettore scelte dall'utente.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

void initVettore(int _v[], int _length);
void printVettore(int _v[], int _length);
int positionMax(int _v[], int _length);
int* addrPositionMax(int _v[], int _length);
float getMediaVettore(int _v[], int _length);
int swapCells(int _v[], int _length, int _x1, int _x2);

int main(){
    int vet[DIM];
    int cella_max;
    int *max;

    initVettore(vet, DIM);
    printVettore(vet, DIM);
    printf("\n\n");

    cella_max = positionMax(vet, DIM);
    printf("Valore massimo in posizione [%d]=%d\n", cella_max, vet[cella_max]);
    printf("Valore massimo in posizione [%d]=%d\n\n", positionMax(vet, DIM), vet[positionMax(vet, DIM)]);

    max = addrPositionMax(vet, DIM);
    printf("Valore Massimo: %d", *max);
    printf("\n\n");

    printf("Valor medio del vettore: %.2f", getMediaVettore(vet, DIM));
    printf("\n\n");

    if(swapCells(vet, DIM, 0, 9))
        printVettore(vet, DIM);
    else 
        printf("Indici errati o non validi!");
    return(0);
}

void initVettore(int _v[], int _length){
    int i;
    srand(time(NULL));

    for(i=0; i<_length; i++)
        _v[i] = rand()%100 + 1;
}

void printVettore(int _v[], int _length){
    int i;
    for(i=0; i<_length; i++)
        printf("%4d", _v[i]);
}

int positionMax(int _v[], int _length){
    int i;
    int max, pmax;

    max = _v[0];
    pmax = 0;
    for(i=1; i<_length; i++){
        if(_v[i] > max){
            max = _v[i];
            pmax = i;
        }    
    }
    return(pmax);
}

int* addrPositionMax(int _v[], int _length){
    int i;
    int max, pmax;

    max = _v[0];
    pmax = 0;
    for(i=1; i<_length; i++){
        if(_v[i] > max){
            max = _v[i];
            pmax = i;
        }    
    }
    return(&_v[pmax]);
}

float getMediaVettore(int _v[], int _length){
    int i;
    int somma;
    float media;

    somma = 0;
    for(i=0; i<_length; i++)
        somma = somma + _v[i];
    
    media = (float)somma / _length;
    return(media); // uguale fare: return((float)somma / _length);
}

int swapCells(int _v[], int _length, int _x1, int _x2){
    int tmp;
    if((_x1>=0 && _x1<_length) && (_x2>=0 && _x2<_length)){
        tmp = _v[_x1];
        _v[_x1] = _v[_x2];
        _v[_x2] = tmp;
        return(1);
    }
    else
        return(0);
}