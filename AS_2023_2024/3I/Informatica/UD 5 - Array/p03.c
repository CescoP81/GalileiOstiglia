/*
Realizzare un programma che esegue le seguenti operazioni, in sequenza, utilizzando funzioni e vettori.
1. Inizializza con valori random, compresi tra 1 e 20, un vettore di 10 elementi.
2. Visualizza il vettore dalla cella 0 alla cella Dim-1.
3. Calcola e restituisce la media del vettore.
4. Calcola e restituisce quanti valori sono superiori alla media.
5. Richiede un valore X e se il valore della cella è maggiore di X allora lo sottrae, altrimenti lo aggiunge.
6. Visualizza a video tutti i valori pari e nella riga sotto tutti i valori dispari.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIM = 10;

// PROTOTIPI
/**
 * Azzera tutte le celle di un vettore di interi
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore
*/
void initVettore(int _v[], int _dim);
/**
 * Inizializza le celle di un vettore con valori random
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore.
*/
void generaVettore(int _v[], int _dim);
/**
 * Visualizza un vettore contornando ogni cella e il suo contenuto con caratteri della tabella Ascii.
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore.
*/
void vediVettoreGrafico(int _v[], int _dim);

float mediaVettore(int _v[], int _dim);
int contaSuperioriMedia_1(int _v[], int _dim, float _m);
int contaSuperioriMedia_2(int _v[], int _dim);
void usaValoreX(int _v[], int _dim, int _x);
void vediPariDispari(int _v[], int _dim);

int main(){
    int vet[DIM];
    float med;
    int varX;

    initVettore(vet, DIM);
    // punto 1 OK.
    generaVettore(vet, DIM);
    // punto 2 OK.
    vediVettoreGrafico(vet, DIM);
    // punto 3 OK
    med = mediaVettore(vet, DIM);
    printf("\nMedia del vettore: %.2f\n", med);
    // punto 4 OK
    printf("Valori superiori alla media 1: %d\n", contaSuperioriMedia_1(vet, DIM, med));
    printf("Valori superiori alla media 2: %d\n", contaSuperioriMedia_2(vet, DIM));
    // punto 5 OK
    printf("Inserisci valore X: ");
    scanf("%d", &varX);
    fflush(stdin);
    usaValoreX(vet, DIM, varX);
    vediVettoreGrafico(vet, DIM);
    // punto 6
    vediPariDispari(vet, DIM);
    return(0);
}

// FUNZIONI
void initVettore(int _v[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        _v[i] = 0;
    }
}
void generaVettore(int _v[], int _dim){
    int i;
    srand(time(NULL));

    for(i=0; i<_dim; i++){
        _v[i] = 1 + rand()%20;  // riempio il vettore con valori random compresi tra 1 e 20 (estremi compresi).
    }
}
void vediVettoreGrafico(int _v[], int _dim){
    int i;
    //printf("%c %c %c %c %c\n", 191, 192, 196, 217, 218);
    printf("%c", 218);
    for(i=0; i<_dim; i++){
        printf("%c%c%c", 196,196,196);
        if(i!=_dim-1)
            printf("%c", 194);
    }
    printf("%c", 191);
    printf("\n");
    printf("%c", 179);
    for(i=0; i<_dim; i++){
        printf("%3d", _v[i]);
        printf("%c", 179);
    }
    printf("\n");
    printf("%c", 192);
    for(i=0; i<_dim; i++){
        printf("%c%c%c", 196,196,196);
        if(i!=_dim-1)
            printf("%c", 193);
    }
    printf("%c", 217);
    printf("\n");
    for(i=0; i<_dim; i++)
        printf("%4d", i);
    printf("\n");
}
float mediaVettore(int _v[], int _dim){
    int somma = 0;
    float media;
    int i;
    for(i=0; i<_dim; i++){          // sommo tutti i valori presenti nel vettore
        somma = somma + _v[i];
    }
    media = (float)somma / _dim;    // calcolo la media come somma totale fratto numero valori.

    return(media);                  // ritorno il valore calcolato alla main che ha chiamato la funzione.
}
int contaSuperioriMedia_1(int _v[], int _dim, float _m){
    int cnt=0;
    int i;
    for(i=0; i<_dim; i++){
        if(_v[i] > _m)
            cnt = cnt + 1;
    }
    return(cnt);
}
int contaSuperioriMedia_2(int _v[], int _dim){
    int cnt=0;
    float media;
    media = mediaVettore(_v, _dim);
    int i;
    for(i=0; i<_dim; i++){
        if(_v[i] > media)
            cnt = cnt + 1;
    }
    return(cnt);
}
void usaValoreX(int _v[], int _dim, int _x){
    int i;
    for(i=0; i<_dim; i++){
        if(_v[i] > _x){
            _v[i] = _v[i] - _x;
        }
        else{
            if(_v[i] < _x){
                _v[i] = _v[i] + _x;
            }
        }
    }
}
void vediPariDispari(int _v[], int _dim){
    int i;
    for(i=0; i<_dim; i++){      // ciclo per visualizzare i pari.
        if(_v[i]%2 == 0){
            printf("%3d", _v[i]);
        }
    }
    printf("\n");
    for(i=0; i<_dim; i++){      // ciclo per visualizzare i dispari.
        if(_v[i]%2 != 0){
            printf("%3d", _v[i]);
        }
    }
}