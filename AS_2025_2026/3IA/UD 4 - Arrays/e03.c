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
    return(0);
}

// gcc e.c -lm