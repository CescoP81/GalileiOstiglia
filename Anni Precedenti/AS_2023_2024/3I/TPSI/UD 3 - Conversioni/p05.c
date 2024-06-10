/*
    Programma C che richiede l'inserimento di 8 bit binari e comunica il rispettivo numero
    convertito in base 10.
    Per questo programma è necessaria la libreria math.h
*/
#include <stdio.h>
#include <math.h>

const int DIM = 8;

int main(){
    int numeroDecimale;
    int numeroBinario[DIM];
    int i;

    // step 1: richiedo il numero binario al mio utente.
    for(i=DIM-1; i>=0; i--){            // l'utente inserisce il numero binario leggendolo da sinistra verso destra, 
                                        // quindi il primo bit è quello con valore 2^7
        do{
            printf("Inserisci il bit[%d]: ", i);
            scanf("%d", &numeroBinario[i]);
            fflush(stdin);
        }while(numeroBinario[i] < 0 || numeroBinario[i]>1);
    }

    // step 2: Visualizzo il numero binario inserito dall'utente
    printf("Binario inserito: ");
    for(i=DIM-1; i>=0; i--){
        printf("%d", numeroBinario[i]);
    }

    // fatte queste due operazioni, compilo e verifico.

    // step 3: eseguo la codifica in forma decimale.
    numeroDecimale = 0;
    for(i=0; i<DIM; i++){
        numeroDecimale = numeroDecimale + (numeroBinario[i] * pow(2,i));
    }
    printf("\n\nNumero decimale equivalente: %d", numeroDecimale);

    return(0);
}