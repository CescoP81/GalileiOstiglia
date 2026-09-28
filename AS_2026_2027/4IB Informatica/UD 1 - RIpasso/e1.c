#include <stdio.h>

#define DIM 5

int main(){
    int altezza[DIM];
    int i;
    char junk;

    // inizializzazione a zero
    for(i=0; i<DIM; i++){
        altezza[i] = 0;
    }

    // popolamento manuale dell'array
    for(i=0; i<DIM; i++){
        printf("Inserisci la %d altezza: ", i+1);
        scanf("%d", &altezza[i]);
        junk = getchar();
    }

    // stampa dei valori inseriti come verifica dell'avvenuto inserimento.
    for(i=0; i<DIM; i++){
        printf("%d ", altezza[i]);
    }
    printf("\n\n");

    
}