#include <stdio.h>

int main(){
    int numero;     // numero da convertire
    int base;       // base in cui convertire il numero
    int resto;      // resto della divisione (il bit di resto)
    int numeroBit;  // numero di bit con cui voglio rappresentare l'informazione.
    int i;          // variabile per il ciclo di scomposizione.

    numero = 45;    // in binario -> 0001 1001
    base = 2;
    numeroBit = 8;

    // eseguire la conversione per divisioni successive.
    i=0;
    while(i<numeroBit){
        resto = numero % base;
        printf("%d ", resto);
        numero = numero / base;
        i = i + 1; 
    }

    return(0);
}