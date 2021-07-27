#include <stdio.h>
#include <stdlib.h>
#include "nodo.c"

int main(){
    Nodo* testa = NULL;

    printf("testa: %d\n",testa);
    // Push ad inizio lista, quindi modificano la testa esistente.
    /*testa = pushTesta(testa,16);
    testa = pushTesta(testa,8);
    testa = pushTesta(testa,4);
    printf("\n\ntesta: %d\n",testa);
    stampaLista(testa);*/

    // Push in coda
    testa = pushCoda(testa, 5);
    testa = pushCoda(testa, 7);
    testa = pushCoda(testa, 9);
    printf("\n\ntesta: %d\n",testa);
    stampaLista(testa);
    printf("Nodi presenti: %d\n", contaNodi(testa));
    printf("Somma dei valori nei nodi: %d\n\n", sommaLista(testa));

    testa = pushPosizione(testa, 1, 18);
    stampaLista(testa);
    printf("Nodi presenti: %d\n\n", contaNodi(testa));

    testa =pushPosizione(testa, 3, 99);
    stampaLista(testa);
    printf("Nodi presenti: %d\n\n", contaNodi(testa));

    testa =pushPosizione(testa, 2, 100);
    stampaLista(testa);
    printf("Nodi presenti: %d\n\n", contaNodi(testa));

    testa =pushPosizione(testa, 7, 200);
    stampaLista(testa);
    printf("Nodi presenti: %d\n\n", contaNodi(testa));

    testa =pushPosizione(testa, 17, 200);
    stampaLista(testa);
    printf("Nodi presenti: %d\n\n", contaNodi(testa));
    return(0);
}