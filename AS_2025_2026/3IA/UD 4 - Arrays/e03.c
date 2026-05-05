#include <stdio.h>
#include "lib.c"

#define DIM 8

int main(){
    int numero;     // variabile per acquisire un valore intero da tastiera.
    int bin[DIM];   // array per rappresentare un numero in binario.
    char junk;

    // step 1: acquisico il valore intero da tastiera
    printf("Inserisci un valore intero: ");
    scanf("%d", &numero);
    junk = getchar();

    if(convertiBinario(numero, bin, DIM)){
        //stampaBinario(bin, DIM);
        stampaBinarioBasic(bin, DIM);
        printf("\n\n");
    }
    else{
        printf("Attenzione il numero %d non e' rappresentabile con %d bit!", numero, DIM);
    }


    int bin1[DIM];
    int bin2[DIM];
    int bin3[DIM];
    convertiBinario(14, bin1, DIM);
    convertiBinario(16, bin2, DIM);
    sommaBinaria(bin1, bin2, bin3, DIM);
    stampaBinarioBasic(bin3, DIM);

    return(0);
}

// gcc e.c -lm