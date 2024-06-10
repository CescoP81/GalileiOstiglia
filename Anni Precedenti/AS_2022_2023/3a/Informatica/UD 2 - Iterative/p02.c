/*
Date: 12.11.22
Author: Pradella Francesco
Abstract:
Algoritmo che somma i valori
 inseriti dall'utente finche l'utente non comunica di voler terminare.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int val;
    int somma;
    int risposta;

    somma = 0;
    do{
        // eseguo una pulizia schermo.
        system("CLS");
        // richiesta valore
        printf("Inserisci un valore: ");
        scanf("%d", &val);
        fflush(stdin);

        // sommo il valore alla somma attuale
        somma = somma + val;    // somma += val;

        // chiedo all'utente cosa intende fare
        // con controllo sull'input della risposta!
        do{
        printf("Premi 1->Continuare; 0-> Terminare: ");
        scanf("%d", &risposta);
        fflush(stdin);
        }while(risposta<0 || risposta>1);
    }while(risposta == 1); // oppure 'risposta != 0' oppure 'risposta'

    // comnunico la somma dei valori
    printf("\nSomma dei valori inseriti: %d", somma);
    return(0);
}