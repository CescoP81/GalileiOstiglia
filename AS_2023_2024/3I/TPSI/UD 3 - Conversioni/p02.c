#include <stdio.h>

int main(){
    int numero;     // numero da convertire
    int base;       // base in cui convertire il numero
    int resto;      // resto della divisione (il bit di resto)
    int numeroBit;  // numero di bit con cui voglio rappresentare l'informazione.
    int i;          // variabile per il ciclo di scomposizione.
    int binario[8]; // vettore "Array" per i resti (bit) in base 2 o binaria
                    // per l'utilizzo dei vettori si usa il ciclo iterativo FOR.

    numero = 45;    // in binario -> 0001 1001
    base = 2;
    numeroBit = 8;

    // ciclo di scomposizione in base 2, riempio il vettore dalla cella 0 alla cella 7
    for(i=0; i<numeroBit; i=i+1){
        binario[i] = numero % base;
        numero = numero / base;
    }

    // visualizzazione del vettore, numero binario rappresentato.
    for(i=numeroBit-1; i>=0; i = i-1){
        printf("%d ", binario[i]);
    }

    return(0);
}