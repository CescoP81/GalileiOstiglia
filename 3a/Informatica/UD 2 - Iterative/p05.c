/*
Date: 12.11.22
Author: Pradella Francesco
Abstract:
Algoritmo che visualizza un intervallo di tabelline a scelta tra i primi 10 numeri
naturali, le altre tabelline sono sostituite da un carattere '#'.
Deve prevedere il controllo sull'input della tabellina scelta.
ES: tabellina_iniziale 5 - tabellina_finale 8 -> Visualizza le tabelline del 5,6,7,8
mentre # per tutte le altre.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(){
    int riga, colonna;  // variabili per i cicli delle tabelline.
    int riga_min, riga_max; // estremi delle tabelline scelte.

    printf("Inserisci tabellina inferiore: ");
    scanf("%d", &riga_min);
    fflush(stdin);

    printf("Inserisci tabellina superiore: ");
    scanf("%d", &riga_max);
    fflush(stdin);

    if((riga_min < riga_max) && (riga_min >=1 && riga_max<=MAX)){
        // eseguo la creazione delle tabellini
        riga=1;
        while(riga <= MAX){
            colonna = 1;
            while(colonna <= MAX){
                if(riga>=riga_min && riga<=riga_max){
                    printf("%4d", (riga * colonna));
                }
                else{
                    printf("   #");
                }
                colonna = colonna + 1;
                
            }
            printf("\n");
            riga = riga + 1;
        }
    }
    else{
        printf("tabelline non visualizzabili, indici non validi.");
    }
    return(0);
}