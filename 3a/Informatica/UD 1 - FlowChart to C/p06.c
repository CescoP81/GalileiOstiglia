/*  Data: 22/10/22
    Author: Francesco Pradella
    Filename: p06.c
    Abstracty: Esercizio nr. 8 pag. 153
*/
#include <stdio.h>

int main(){
    int ore;        // variabile per le ore inserite dall'utente.
    int minuti;     // variabile per i minuti inseriti dall'utente.
    int secondi;    // variabile per i secondi inseriti dall'utente.
    int secTotali;  // variabile per i secondi totali calcolati dall'algoritmo.

    ore = 0; minuti = 0; secondi = 0; secTotali = 0;

    // fase di input valori
    printf("Ore: ");
    scanf("%d", &ore);
    fflush(stdin);

    printf("Minuti: ");
    scanf("%d", &minuti);
    fflush(stdin);

    printf("Secondi: ");
    scanf("%d", &secondi);
    fflush(stdin);

    // fase di calcolo e output del risultato.
    secTotali = secondi + (minuti*60) + (ore*3600);
    printf("Secondi totali: %d", secTotali);

    return(0);
}