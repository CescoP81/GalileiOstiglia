/*
    Author: Pradella Francesco
    Date: 27.10.2022
    Abstract:
    Realizzare un programma C sull’utilizzo delle strutture dati Vettore e Matrice definendo le funzioni che seguono e facendone un test nel main:
    a)initMatrice() → Inizializza una matrice 6x6 con valori casuali compresi tra 1 e 99, evitando valori in un range inserito dall’utente nel main e passato alla funzione.
    b)StampaMatrice() → Stampa la matrice a video.
    c)SwapValori() → scambia due celle della matrice, il main passa i relativi indici, solo se il valore della prima cella è maggiore della seconda. Ritorna al main se lo scambio è avvenuto oppure no.
    d)LoadVettore() → carica un vettore di 6 elementi da tastiera con valori univoci.
    e)ComparaVettoreMatrice() → Compara i valori del vettore con quelli della matrice e ritorna il numero di valori che sono non comuni (valori del vettore che non compaiono mai nella matrice).
    Tutti i punti devono essere svolti con funzione, nel main deve essere effettuata almeno una chiamata di test per ogni funzione. Le funzioni non eseguono output a video.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 6

/**
 * Inizializza una matrice con valori random compresi tra 1 e 99 evitando il range passato come parametri
 * @param int[][] Matrice da utilizzare.
 * @param int Numero di righe.
 * @param int Numero di colonne.
 * @param int Valore iniziale range.
 * @param int Valore finale del range.
*/
void initMatrice(int [][DIM], int, int, int, int);
/**
 * Visualizza una matrice a video
 * @param int[][] Matrice da utilizzare.
 * @param int Numero di righe.
 * @param int Numero di colonne.
*/
void stampaMatrice(int [][DIM], int, int);
/**
 * Scambia due celle della matrice
 * @param int[][] Matrice da utilizzare.
 * @param int Numero di righe.
 * @param int Numero di colonne.
 * @param int Indice Riga - Prima cella
 * @param int Indice Colonna - Prima cella
 * @param int Indice Riga - Seconda cella
 * @param int Indice Colonna - Prima cella
 * @return int 1-Scambio Avvenuto; 0-Scambio fallito
*/
int swapCelleMatrice(int [][DIM], int, int, int, int, int, int);
/**
 * Carica un vettore di 6 elementi con valori univoci.
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore
*/
void loadVettore(int[], int);
/**
 * Compara un vettore con una matrice e restituisce il numero di valori del vettore che non compaiono mai nella matrice.
 * @param int[] Vettore da utilizzare
 * @param int Dimensione del vettore
 * @param int[][] Matrice da utilizzare
 * @param int Numero di righe
 * @param int Numero di colonne
 * @return int Numero di valori del vettore che non compaiono nella matrice.
*/
int comparaVettoreMatrice(int[], int, int [][DIM], int, int);


int main(){
    int mat[DIM][DIM];
    int vet[DIM];

    // Chiamata punto a.
    initMatrice(mat, DIM, DIM, 10, 20);
    // chiamata punto b.
    stampaMatrice(mat, DIM, DIM);
    // chiamata punto c
    if(swapCelleMatrice(mat, DIM, DIM, 1, 1, 5, 5))
        printf("Scambio avvenuto");
    else
        printf("Scambio non possibile");
    printf("\n\n");
    // chiamata punto d
    loadVettore(vet, DIM);
    printf("\n");
    printf("Sono stati trovati %d valori su %d del vettore che non compaiono nella matrice", comparaVettoreMatrice(vet, DIM, mat, DIM, DIM), DIM);
    return(0);
}

// punto a)
void initMatrice(int _m[][DIM], int _r, int _c, int _start, int _end){
    int i, j;
    srand(time(NULL));
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            do{
                _m[i][j] = 1 + (rand()%99);
            }while(_m[i][j]>=_start && _m[i][j]<=_end); // se il valore random è interno al range, lo rigenera.
        }
    }
}
// punto b)
void stampaMatrice(int _m[][DIM], int _r, int _c){
    int i, j;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            printf("%3d", _m[i][j]);
        }
        printf("\n");
    }
}
// punto c)
int swapCelleMatrice(int _m[][DIM], int _r, int _c, int _indexR1, int _indexC1, int _indexR2, int _indexC2){
    int tmp;
    if(_m[_indexR1][_indexC1] > _m[_indexR2][_indexC2]){
        tmp = _m[_indexR1][_indexC1];
        _m[_indexR1][_indexC1] = _m[_indexR2][_indexC2];
        _m[_indexR2][_indexC2] = tmp;
        return(1);
    }
    return(0);
}
// punto d)
void loadVettore(int _v[], int _dim){
    int i, j;
    int trovato;

    for(i=0; i<_dim; i++){
        do{
            // fase di richiesta di un valore
            printf("Inserisci il valore [%d]: ", i+1);
            scanf("%d", &_v[i]);
            fflush(stdin);
            // fase di ricerca del valore nel vettore
            trovato = 0;
            for(j=0; j<i; j++){
                if(_v[i] == _v[j])
                    trovato = 1;
            }
            if(trovato)
                printf("\n !! VALORE GIA' PRESENTE !! \n");
        }while(trovato);
    }
}
// punto e)
int comparaVettoreMatrice(int _v[], int _dim, int _m[][DIM], int _r, int _c){
    int cnt;    // contatore dei valori del vettore che non vengono mai trovati nella matrice.
    int i; // indice che uso sul vettore.
    int h,k;// indici che uso sulla matrice.
    int trovato;

    cnt = 0;
    for(i=0; i<_dim; i++){
        trovato = 0;
        for(h=0; h<_r; h++){
            for(k=0; k<_c; k++){
                if(_v[i] == _m[h][k])
                    trovato = 1;
            }
        }
        if(!trovato)
            cnt = cnt + 1;
    }
    return(cnt);
}