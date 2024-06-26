/* Programma di dichiarazione e inizializzazione di un vettore monodimensionale
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// dichiaro una costante intera per la dimensione del vettore
const int DIM = 13;
// SEZIONE DEI PROTOTIPI
/**
 * Azzera tutte le celle di un vettore di interi
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore
*/
void initVettore(int _v[], int _dim);
/**
 * Visualizza il contenuto delle celle di un vettore su singola riga.
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore.
*/
void vediVettore(int _v[], int _dim);
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
/**
 * Funzione che cerca e comunica il valore massimo presente nel vettore.
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore.
*/
void ricercaMassimo(int _v[], int _dim);
/**
 * Sostituisce nel vettore tutti i valori uguali a src con dest.
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore.
 * @param int Valore da ricercare e da sostituire.
 * @param int Valore sostitutivo.
*/
void sostituisciValore(int _v[], int _dim, int _src, int _dest);
/**
 * Calcola e restituisce la media dei valori del vettore.
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore.
 * @return Media dei valori.
*/
float mediaVettore(int _v[], int _dim);

// SEZIONE DEL MAIN
int main(){
    int vet[DIM];

    initVettore(vet, DIM);
    vediVettore(vet, DIM);
    printf("\n");
    generaVettore(vet, DIM);
    vediVettore(vet, DIM);
    printf("\n");
    vediVettoreGrafico(vet, DIM);
    printf("\n");
    ricercaMassimo(vet, DIM);
    printf("\n");
    sostituisciValore(vet, DIM, 14, 33);
    vediVettoreGrafico(vet, DIM);
    printf("\n");
    printf("Media dei valori: %.3f \n", mediaVettore(vet, DIM));
    return(0);
}
// SEZIONE FUNZIONI
void initVettore(int _v[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        _v[i] = 0;
    }
}
void vediVettore(int _v[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        printf("%3d", _v[i]);
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
void ricercaMassimo(int _v[], int _dim){
    int i;
    int max;

    max = _v[0];
    for(i=0; i<_dim; i++){
        if(_v[i] > max)
            max = _v[i];
    }

    printf("Valore massimo presente: %d\n", max);
}
void sostituisciValore(int _v[], int _dim, int _src, int _dest){
    int i;
    for(i=0; i<_dim; i++){
        if(_v[i] == _src){
            _v[i] = _dest;
        }
    }
}
float mediaVettore(int _v[], int _dim){
    int i;
    int somma;

    somma = 0;
    for(i=0; i<_dim; i++){
        somma = somma + _v[i];
    }

    return((float)somma/_dim);
}