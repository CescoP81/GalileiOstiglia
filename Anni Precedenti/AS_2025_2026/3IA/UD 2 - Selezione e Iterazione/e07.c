/*
    Sviluppo di doppio ciclo innestato
    1  2  3  4  5
    2  4  6  8 10
    3  6  9 12 15
    4  8 12 16 20
    5 10 15 20 25
*/
#include <stdio.h>

int main(){
    int r; // variabile per le righe (ciclo)
    int c; // variabile per le colonne (ciclo)
    int nRows;
    int nCols;
    char junk;

    r = 1;
    while(r <= 5){  // iterativa per le righe
        c = 1;
        while(c <= 5){  // iterativa per le colonne
            printf("%3d", (r*c));
            c = c + 1;
        }
        printf("\n");
        r = r + 1;
    }
    printf("\n\n");
    printf("Inserisci le righe: ");
    scanf("%d", &nRows);
    junk = getchar();
    printf("Inserisci le colonne: ");
    scanf("%d", &nCols);
    junk = getchar();

    r = 1;
    while(r <= nRows){  // iterativa per le righe
        c = 1;
        while(c <= nCols){  // iterativa per le colonne
            printf("%3d", (r*c));
            c = c + 1;
        }
        printf("\n");
        r = r + 1;
    }
    printf("\n\n");

    // doppia iterativa che mostra le coordinare (valori) riga e colonna per ogni singola posizione
    // stampata.
    r = 1;
    while(r <= 5){  // iterativa per le righe
        c = 1;
        while(c <= 5){  // iterativa per le colonne
            printf("(r:%d,c:%d) ", r, c);
            c = c + 1;
        }
        printf("\n");
        r = r + 1;
    }
    printf("\n\n");

    return(0);
}