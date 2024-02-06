/*
    Esempio di funzioni per:
    - input valori controllati.
    - generazione valori random con range controllati.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* -- sezione relativa ai prototipi delle funzioni -- */

/**
 * Ritorna un valore compreso tra 0 e il valore massimo passato come parametro.
 * @param int Valore massimo ammissibile.
 * @return Valore intero valido (compreso tra 0 e max passato).
*/
int getValueLessThan(int _max);

/**
 * Ritorna un valore compresto tra min e max richiesto come input all'utente.
 * @param int Valore minimo ammissibile.
 * @param int Valore massimo ammissibile.
 * @return Valore inserito valido (compreso tra min e max, estremi compresi).
*/
int getValueBetween(int _min, int _max);

/* -- sezione del main program -- */
int main(){
    int x;

    // Verifica funzione
    x = getValueLessThan(20);
    printf("E' stato inserito il valore: %d\n", x);

    x = getValueBetween(9, 2);
    printf("Valore di x: %d\n", x);
    x = getValueBetween(1, 10);
    printf("Valore di x: %d\n", x);

    return(0);
}

/* sezione di definizione delle funzioni */
int getValueLessThan(int _max){
    int valore;     // variabile per il valore in input.

    // ciclo iterativo che "gira" finché viene inserito un numero SBAGLIATO
    do{
        printf("Inserisci un valore (compreso tra 0 e %d): ", _max);
        scanf("%d", &valore);
        fflush(stdin);
    }while(valore<0 || valore>_max);

    // ritorno al MAIN il valore valido inserito dall'utente.
    return(valore);
}

int getValueBetween(int _min, int _max){
    int valore;

    // controllo che gli estremi siano validi e in ordine corretto.
    if(_min < _max){
        do{
            printf("Inserisci un valore (compreso tra %d e %d): ", _min, _max);
            scanf("%d", &valore);
            fflush(stdin);
        }while(valore<_min || valore>_max);
    }
    else{
        printf("Attenzione! controllare estremi del range.\n");
        valore = -1;
    }

    return(valore);
}