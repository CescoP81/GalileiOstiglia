/*
    1- Visualizzare tutti i divisori di un numero con una funzione ricorsiva.
    2- Inizializzare un vettore di 10 elementi interi con numeri random tra 1 e 50.
        - Stampare il vettore (funzione).
        - Stampare solo i valori primi (due funzioni distinte).
        - Il vettore deve essere gestito con i PUNTATORI.
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

// PROTOTIPI PER IL PUNTO 1
/*
Funzione ricorsiva che mostra tutti i divisori di un numero.
@param int Numero iniziale.
@param int Ultimo divisore testato.
@return void.
*/
void divisoriRicorsiva(int _num, int _lastDiv);

// PROTOTIPI PER IL PUNTO 2
/* Funzione che inizializza un vettore di interi
@param int* puntatore al vettore.
@param int dimensione del vettore.
@return void */
void initVettore(int *_v, int _length);

/* Funzione che stampa un vettore di interi
@param int* puntatore al vettore.
@param int dimensione del vettore.
@return void */
void printVettore(int *_v, int _length);

/* Funzione che stampa i soli numeri primi presenti nel vettore.
@param int* puntatore al vettore.
@param int dimensione del vettore.
@return void */
void printPrimi(int *_v, int _length);

/* Funzione che determina se un numero passato per valore è primo oppure no.
@param int Numero da verificare.
@return int 1 In caso affermativo, 0 in caso negativo.*/
int isPrimo(int _n);

int main(){
    int numero;
    int v[DIM];
    numero = 64;

    divisoriRicorsiva(numero, 1);
    printf("\n\n");
    
    initVettore(v, DIM);
    printVettore(v,DIM);
    printf("\n");
    printPrimi(v, DIM);

    return(0);
}

// FUNZIONI PUNTO 1
void divisoriRicorsiva(int _num, int _lastDiv){
    if(_lastDiv <= _num){
        if(_num%(_lastDiv) == 0)
            printf("%d ", (_lastDiv));
        divisoriRicorsiva(_num, _lastDiv+1);
    }
}

// FUNZIONI PUNTO 2
void initVettore(int *_v, int _length){
    int i;
    srand(time(NULL));

    for(i=0; i<_length; i++)
        *(_v+i) = rand()%50 + 1;
}

void printVettore(int *_v, int _length){
    int i;
    for(i=0; i<_length; i++)
        printf("%d ", *(_v+i));
}

int isPrimo(int _n){
    int i;
    int cnt;
    cnt = 0;

    for(i=1; i<=_n; i++){
        if(_n%i == 0)
            cnt++;
    }
    if(cnt<=2)
        return(1); // se il numero _n è primo
    else
        return(0); // se il numero _n non è primo
}

void printPrimi(int *_v, int _length){
    int i;
    for(i=0; i<_length; i++){
        if(isPrimo(*(_v+i))) // euivalente a scrivere 'isPrimo(*(_v+i)) == 1'
            printf("%d ", *(_v+i));
    }
}