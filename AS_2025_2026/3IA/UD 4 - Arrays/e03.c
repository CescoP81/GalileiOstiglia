#include <stdio.h>
#include "lib.c"

#define DIM 8

int main(){
    int numero;     // variabile per acquisire un valore intero da tastiera.
    int bin[DIM];   // array per rappresentare un numero in binario.
    char junk;
/*
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
    printf("\n\n");
*/
    int n1 = 245;
    int n2 = 12;
    int bin1[DIM];
    int bin2[DIM];
    int bin3[DIM];
    convertiBinario(n1, bin1, DIM);
    convertiBinario(n2, bin2, DIM);
    if(sommaBinaria(bin1, bin2, bin3, DIM) == 0){
        printf("\nBin1: %d\n", n1);
        stampaBinarioBasic(bin1, DIM);
        printf("\nBin2: %d\n", n2);
        stampaBinarioBasic(bin2, DIM);
        printf("\nBin3:\n");
        stampaBinarioBasic(bin3, DIM);
    }
    else{
        printf("Attenzione...la somma ha generato Overflow!\n");
    }

    return(0);
}

// gcc e.c -lm