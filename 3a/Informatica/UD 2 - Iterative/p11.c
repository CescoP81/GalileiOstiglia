#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RANGE 1
#define MAX_RANGE 20

int main(){
    int numeroRandom;           // variabile per il numero generato.
    int numeroUtente;           // variabile per il numero del giocatore.
    int indovinato;             // FLAG/BANDIERINA per stabilire se ho indovinato il numero
    int numeroTentativi;        // contatore del numero di tentativi effettuati.
    srand(time(NULL));

    // 1. genero il numero da indovinare
    numeroRandom = MIN_RANGE + (rand()%(MAX_RANGE - MIN_RANGE + 1));

    indovinato = 0;             // lampadina spenta
    numeroTentativi = 0;
    do{
        // richiesta valore al giocatore
        numeroTentativi = numeroTentativi + 1;
        printf("Inserisci un numero: ");
        scanf("%d", &numeroUtente);
        fflush(stdin);
        if(numeroUtente == numeroRandom){
            printf("HAI INDOVINATO con %d TENTATIVI!!", numeroTentativi);
            indovinato = 1;
        }
        else{
            if(numeroUtente > numeroRandom)
                printf("Troppo Alto!!\n");
            if(numeroUtente < numeroRandom)
                printf("Troppo Basso!!\n");
        }
    }while(indovinato == 0);
    printf("\n\nGrazie per aver Giocato con me!");
    return(0);
}