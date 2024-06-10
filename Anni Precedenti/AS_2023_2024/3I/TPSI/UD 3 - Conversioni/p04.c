/*
    Realizzare un programma che richiede all'utente un numero decimale compreso tra
    1 e 255, una base in cui convertirlo compresa tra 2 e 10.
    L'algoritmo converte il numero decimale nella base scelta mettendo i
    resti delle divisioni nelle celle del rispettivo vettore.
*/
#include <stdio.h>

int main(){
    int numeroDecimale;     // variabile per il numero iniziale scelto dall'utente compreso tra 1 e 255.
    int baseConversione;    // variabile per la base scelta dall'utente compresa tra 2 e 10
    int conversione[8];     // vettore dei resti derivati dalla conversione, 8 celle perchè 8 è il numero di bit 
                            // che mi servono per convertire il numero decimale massimo (255) con la base di conversione
                            // più piccola cioè 2.
    int i;                  // variabile per i cicli di conversione e stampa.

    // step 1: inserimento del valore da convertire compreso tra 1 e 255, controllare l'input.
    do{
        printf("Inserisci numero da convertire(1-255): ");
        scanf("%d", &numeroDecimale);
        fflush(stdin);
    }while(numeroDecimale<1 || numeroDecimale>255);

    // step 2: inserimento del valore della base di conversione compreso tr 2 e 10, controllare l'input.
    do{
        printf("Inserisci la base di conversione(2-10): ");
        scanf("%d", &baseConversione);
        fflush(stdin);
    }while(baseConversione<2 || baseConversione>10);

    // step 3: conversione secondo la base scelta e memorizzazione dei resti della divisione nelle varie celle del vettore.
    for(i=0; i<8; i=i+1){
        conversione[i] = numeroDecimale % baseConversione;
        numeroDecimale = numeroDecimale / baseConversione;
    }

    // step 4: stampa del vettore dei resti, cioè del numero convertito secondo la base scelta.
    printf("\nNumero convertito: ");
    for(i=7; i>=0; i=i-1){
        printf("%d ", conversione[i]);
    }

    return(0);
}