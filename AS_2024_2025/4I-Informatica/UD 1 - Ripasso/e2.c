/*
Creare un programma che gestisca una matrice di interi da 4 righe e 5 colonne,
inizializzandola con numeri random compresi tra 5 e 25.
quindi:
- stampa la matrice.
- calcola la media totale della matrice.
- cacola il valore maggiore di ogni riga e lo visualizza.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int RIGHE = 4;
const int COLONNE = 5;

int main(){
    srand(time(NULL)); // inizializzo il motore dei numeri random.
    int mat[RIGHE][COLONNE];
    int i, j; // variabili per i cicli iterativi (for).
    int totale;
    float media;
    int max;

    // inizializzo la matrice con valori casuali
    for(i=0; i<RIGHE; i++){
        for(j=0; j<COLONNE; j++){
            mat[i][j] = 5 + (rand()%(25-5+1)); // 5 + rand= 0 <-> 20
        }
    }

    // punto 1: stampa della matrice
    for(i=0; i<RIGHE; i++){
        for(j=0; j<COLONNE; j++){
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }

    // punto 2: media totale della matrice
    totale = 0;
    for(i=0; i<RIGHE; i++){
        for(j=0; j<COLONNE; j++){
            totale = totale + mat[i][j];
        }
    }
    printf("\nSomma totale: %d\n", totale);
    media = (float)totale / (RIGHE*COLONNE);
    printf("Media della matrice: %.2f\n\n", media);

    // punt 3: maggiore di ogni riga.
    for(i=0; i<RIGHE; i++){
        max = mat[i][0];
        for(j=1; j<COLONNE; j++){
            if(mat[i][j] > max)
                max = mat[i][j];
        }
        printf("riga: %d -> massimo: %d\n", i, max);
    }
    return(0);
}