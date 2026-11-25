/*
    Author: Francesco Pradella
    Date: 25.11.2026
    Abstract: Esempio base di dichiarazione, inserimento e stampa di una struttura.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5 

typedef struct{
    int base;
    int altezza;
}shape;

int main(){
    shape x;                // dichiaro una variabile di tipo shape
    shape vectorShape[DIM]; // dichiaro un vettore di 5 elementi di tipo shape
    char junk;
    srand(time(NULL));

    // inizializzazione variabile singola
    x.altezza = 10;
    x.base = 5;
    if(x.altezza == x.base){
        printf("Ho in mano un quadrato e la sua area e': %d\n", x.altezza*x.base);
    }
    else{
        printf("Ho in mano un rettangolo e la sua area e': %d\n", x.altezza*x.base);
    }

    // utilizzo di un vettore anziche variabile singola
    for(int i=0; i<DIM; i++){   // inizializzo le 5 strutture con valori random compresi tra 1 e 20
        vectorShape[i].altezza = 1 + rand()%20;
        vectorShape[i].base = 1 + rand()%20;
    }
    // per ogni struttura stabilisco se è un quadrato o un rettangolo e calcolo la relativa area.
    for(int i=0; i<DIM; i++){
        if(vectorShape[i].altezza == vectorShape[i].base)
            printf("%d -> Ho in mano un quadrato[b:%d - h:%d] e la sua area e': %d\n", i+1, vectorShape[i].base, vectorShape[i].altezza, vectorShape[i].altezza*vectorShape[i].base);
        else
            printf("%d -> Ho in mano un rettangolo[b:%d - h:%d] e la sua area e': %d\n", i+1, vectorShape[i].base, vectorShape[i].altezza, vectorShape[i].altezza*vectorShape[i].base);
    }

    // esempio di input da tastiera delle misure dello shape
    printf("\n\n");
    printf("Inserisci la misura della base: ");
    scanf("%d", &x.base);
    junk = getchar();
    printf("Inserisci la misura dell'altezza: ");
    scanf("%d", &x.altezza);
    junk = getchar();
    if(x.altezza == x.base)
        printf("Ho in mano un quadrato e la sua area e': %d\n", x.altezza*x.base);
    else
        printf("Ho in mano un rettangolo e la sua area e': %d\n", x.altezza*x.base);
    return 0;
}