#include <stdio.h>
#define DIM 8       // dimensione del vettore per la codifica binaria.

int main(){
    int b[DIM];         // vettore di DIM celle per i bit.
    int i;              // variabile indice per le singole celle.
    int numero = 13;    // valore da convertire in binario.

    /*for(i=0; i<DIM; i++)
        b[i] = i+1;*/
    for(i=0; i<DIM; i++){       // ciclo di scomposizione del numero intero in bit per divisioni successive.
        b[i] = numero % 2;
        numero = numero / 2;
    }
    
    /*for(i=0; i<DIM; i++)
        printf("%d ",b[i]);*/

    for(i=DIM-1; i>=0; i--){    // ciclo di visualizzazione del vettore contenente i bit.
        printf("%d", b[i]);
    }

    /* equivalente  al ciclo di visualizzazione
    for(i=0; i<DIM; i++){
        printf("%d", b[DIM-i-1]);
    }*/
    return(0);
}