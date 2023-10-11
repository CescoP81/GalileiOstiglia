/*
    Programma di gestione matrice
    - Inizializzazione matrice 5x5 con valori random tra 1 e 15.
    - Stampa della matrice.
    - Ricerca del valore massimo.
    - Ricerca del valore minimo.
    - Media della matrice.
    - Calcolo e stampa della media dei valori pari e media dei valori dispari.
    - Ordinamento crescente di ogni riga.
    - Calcolo e stampa della somma di ogni colonna.
    - Sostituzione di un valore 'src' con un altro 'dst' in tutta la matrice.
    ## ogni punto è una funzione!
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int DIM=5;

/**
 * @brief inizializza la matrice con valori random compresi tra 1 e 15
 * @param int[][] matrice da utilizzare
 * @param int numero delle righe
 * @param int numero delle colonne
 * @param int numero minimo
 * @param int numero masssimo
*/
void initMatrice(int [][DIM], int, int, int, int);

/**
 * @brief stampa la matrice
 * @param int[][] matrice da usare
 * @param int numero delle righe
 * @param int numero delle colonne
*/
void stampaMatrice(int [][DIM], int, int);

/**
 * @brief ordina la riga in ordine crescente
 * @param int[][] matrice da utilizzare
 * @param int numero di righe
 * @param int numero delle colonne
*/
void ordinamentoRigheCrescente(int [][DIM], int, int);

int main(){
    int mat[DIM][DIM];
    srand(time(NULL));
    
    initMatrice(mat, DIM, DIM, 1, 15);
    stampaMatrice(mat, DIM, DIM);
    printf("\n");
    ordinamentoRigheCrescente(mat, DIM, DIM);
    stampaMatrice(mat, DIM, DIM);
    return(0);
}

void initMatrice(int _mat[][DIM], int _r, int _c, int min, int max){
    int i, j;

    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            _mat[i][j]=min + rand()%(max-min+1);
        }
    }
}

void stampaMatrice(int _mat[][DIM], int _r, int _c){
    int i, j;
    printf("stamp la matrice: \n");    
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            printf("%3d", _mat[i][j]);
        }
        printf("\n");
    }
}

void ordinamentoRigheCrescente(int _mat[][DIM], int _r, int _c){
    int i, j;   //indici usati sulla stessa riga 
    int x;  //indice di riga
    int tmp;
    
    for(x=0; x<_r; x++){
        for(i=0; i<_c-1; i++){
            for(j=i; j<_c; j++){
                if(_mat[x][i]>_mat[x][j]){
                    tmp=_mat[x][i];
                    _mat[x][i]=_mat[x][j];
                    _mat[x][j]=tmp;
                }
            }
        }
    }
}