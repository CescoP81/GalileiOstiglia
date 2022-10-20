/*
    Realizzare un programma che inizializza una matrice 5x5 di interi quindi esegue le seguenti funzioni:
   - [ ] Caricamento dei valori nella matrice random con valori compresi tra 5 e 25.
   - [ ] Stampa della matrice per righe.
   - [ ] Stampa della matrice per colonne.
   - [ ] Calcolo della media della matrice.
   - [ ] Calcolo del totale di una riga della matrice (riga indicata per indice).
   - [ ] Ricerca della riga con media maggiore.
   - [ ] Ricerca di un vettore di 5 elementi interi all'interno della matrice.
   */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DIM 5
// spazio prototipi
/**
 * @brief Funzione che inizializza una matrice
 * @param int[][] Matrice da utilizzare
 * @param int Numero di righe
 * @param int Numero di colonne
 * @param int Estremo inferiore del range
 * @param int Estremo superiore del range
*/
void initMatrice(int [][DIM], int, int, int, int);
/**
 * @brief Funzione che stampa una matrice
 * @param int[][] Matrice da utilizzare
 * @param int Numero di righe
 * @param int Numero di colonne
*/
void stampaMatrice(int [][DIM], int, int);
/**
 * Stampa della matrice per colonne
 * @brief Funzione che stampa una matrice
 * @param int[][] Matrice da utilizzare
 * @param int Numero di righe
 * @param int Numero di colonne
*/
void stampaPerColonne(int [][DIM], int, int);
/**
 * @brief Funzione che calcola e restituisce al main la media aritmetica della matrice
 * @param int[][] Matrice da utilizzare
 * @param int Numero di righe
 * @param int Numero di colonne
 * @return float Media aritmetica della matrice
*/
float mediaMatrice(int [][DIM], int, int);
/**
 * @brief Funzione che restituisce il totale di una riga della matrice scelta per indice.
 * @param int[][] Matrice da utilizzare
 * @param int Numero di righe
 * @param int Numero di colonne
 * @param int Indece ASSOLUTO della riga scelta
 * @return int Totale della riga
*/
int totaleRigaMatrice(int [][DIM], int, int, int);
/**
 * @brief Funzione che determina l'indice della riga con media maggiore
 * @param int[][] Matrice da utilizzare
 * @param int Numero di righe
 * @param int Numero di colonne
 * @return int Indice di riga con media maggiore
*/
int rigaConMediaMaggiore(int[][DIM], int, int);
/**
 * @brief Funzione che ricerca un vettore di 5 elementi tra le righe della matrice
 * @param int[][] Matrice da utilizzare
 * @param int Numero di righe
 * @param int Numero di colonne
 * @param int[] Vettore da confrontare con ogni singola riga.
 * @return int 1 Vettore trovato / 0 Vettore non trovato.
*/
int cercaVettoreInMatrice(int [][DIM], int, int, int[]);


// MAIN PROGRAM
int main(){
    int m[DIM][DIM];
    int v[DIM];
    int i;
    int sommaRiga;

    initMatrice(m, DIM, DIM, 0, 10);
    stampaMatrice(m, DIM, DIM);
    printf("\n\n");
    stampaPerColonne(m, DIM, DIM);
    printf("\n\n");
    printf("Media della matrice: %.2f", mediaMatrice(m, DIM, DIM));
    printf("\n\n");
    sommaRiga = totaleRigaMatrice(m, DIM, DIM, 6);
    if(sommaRiga != -1)
        printf("Somma della riga 4: %d", sommaRiga);
    printf("\n\n");
    printf("Riga con media maggioree': %d", rigaConMediaMaggiore(m,DIM, DIM)+1); // aggiungo 1 all'indice restituito per comodità dell'utente.
    printf("\n\n");
    for(i=0; i<DIM; i++){
        printf("Inserisci il valore [%d]: ", i+1);
        scanf("%d", &v[i]);
        fflush(stdin);
    }
    if(cercaVettoreInMatrice(m, DIM, DIM, v))
        printf("Vettore trovato come riga nella matrice.");
    else
        printf("Vettore non presente come riga della matrice.");
    printf("\n\n");
    return(0);
}

// definizione delle funzioni
void initMatrice(int _m[][DIM], int _r, int _c, int _min, int _max){
    int i, j;
    srand(time(NULL));

    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            _m[i][j] = _min + rand()%(_max-_min+1);
        }
    }
}
void stampaMatrice(int _m[][DIM], int _r, int _c){
    int i, j;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            printf("%3d", _m[i][j]);
        }
        printf("\n");
    }
}
void stampaPerColonne(int _m[][DIM], int _r, int _c){
    int i,j;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            printf("%3d", _m[j][i]);
        }
        printf("\n");
    }
}
float mediaMatrice(int _m[][DIM], int _r, int _c){
    int somma;
    int i,j;
    
    somma = 0;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            somma = somma + _m[i][j];
        }
    }

    return((float)somma/(_r*_c));
}
int totaleRigaMatrice(int _m[][DIM], int _r, int _c, int _index){
    int somma;
    int i, j;
    if(_index<0 || _index>=_r){
        return(-1); // l'indice scelto è esterno alle dimensioni della matrice
    }
    else{
        somma = 0;
        for(j=0;j<_c; j++)
            somma = somma + _m[_index][j];
        return(somma);
    }
}
int rigaConMediaMaggiore(int _m[][DIM], int _r, int _c){
    int i, j;       // indici per muovermi sulla matrice
    int media;      // media calcolata sulla singola riga
    int mediaMax;   // media massima trovata fino a quel momento.
    int indexMax;   // indice della riga che media massima

    media = 0;
    mediaMax = 0;
    indexMax = 0;
    for(i=0; i<_r; i++){
        media = 0;
        for(j=0; j<_c; j++){
            media = media + _m[i][j];
        }
        media = media / _c;

        if(media > mediaMax){
            mediaMax = media;
            indexMax = i;
        }
    }
    return(indexMax);
}
int cercaVettoreInMatrice(int _m[][DIM], int _r, int _c, int _v[]){
    int i, j;
    int trovato;
    int cntTrovati;

    trovato = 0;
    for(i=0; i<_r; i++){
        cntTrovati = 0;
        for(j=0; j<_c; j++){
            if(_v[j] == _m[i][j])
                cntTrovati++;
        }
        //printf("--\n %d", cntTrovati);        // esempio di debug inline.
        if(cntTrovati == _c)
            trovato = 1;
    }
    return(trovato);
}
