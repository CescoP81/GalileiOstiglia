/*
Algoritmo che visualizza a video le prime 10 tabelline.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int riga;       // successivamente chiameremo i per le righe
    int colonna;    // successivamente chiameremo j per le colonne

    system("CLS");
    riga = 1;
    while(riga <= 10){
        colonna = 1;
        while(colonna <= 10){
            printf("%4d", (riga*colonna));
            colonna = colonna + 1;
        }
        printf("\n");
        riga = riga + 1;
    }
    return(0);
}