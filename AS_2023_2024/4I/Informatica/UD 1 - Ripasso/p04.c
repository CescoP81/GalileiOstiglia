/*
    Programma di gestione matrice
    - [x] Inizializzazione matrice 5x5 con valori random tra 1 e 15.
    - [x] Stampa della matrice.
    - [x] Ricerca del valore massimo.
    - [x] Ricerca del valore minimo.
    - [x] Media della matrice.
    - [x] Calcolo e stampa della media dei valori pari e media dei valori dispari.
    - [x] Ordinamento crescente di ogni riga.
    - [x] Calcolo e stampa della somma di ogni colonna.
    - [x] Sostituzione di un valore 'src' con un altro 'dst' in tutta la matrice.
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

/**
 * Ricerca del valore massimo
 * @param int[][] matrice da utilizzare
 * @param int numero di righe
 * @param int numero delle colonne
 * @return Valore massimo trovato nella matrice.
*/
int ricercaValoreMassimo(int [][DIM], int, int);

/**
 * Ricerca del valore minimo
 * @param int[][] matrice da utilizzare
 * @param int numero di righe
 * @param int numero delle colonne
 * @return Valore minimo trovato nella matrice.
*/
int ricercaValoreMinimo(int [][DIM], int, int);

/**
 * Calcola e restituisce la media dei valori presenti nella matrice.
 * @param int[][] matrice da utilizzare
 * @param int numero di righe
 * @param int numero delle colonne
 * @return Valore medio calcolato.
*/
float mediaMatrice(int [][DIM], int, int);

/**
 * Calcola e restituisce la media dei valori presenti nella matrice.
 * @param int[][] matrice da utilizzare
 * @param int numero di righe
 * @param int numero delle colonne
 * @return Valore medio calcolato.
*/
void mediaPariDispariMatrice(int [][DIM], int, int);

/**
 * Somma per ogni singola colonna.
 * @param int[][] matrice da utilizzare
 * @param int numero di righe
 * @param int numero delle colonne
*/
void sommaSingolaColonna(int [][DIM], int, int);

/**
 * Sostituisce un valore src con dst all'interno della matrice.
 * @param int[][] matrice da utilizzare
 * @param int numero di righe
 * @param int numero delle colonne
 * @param int Numero da ricercare.
 * @param int Numero sostitutivo.
*/
void sostituisciValoreMatrice(int[][DIM], int, int, int, int);

int main(){
    int mat[DIM][DIM];
    srand(time(NULL));

    // punto 1
    initMatrice(mat, DIM, DIM, 1, 15);
    // punto 2
    stampaMatrice(mat, DIM, DIM);
    printf("\n");
    // punto 3
    printf("Valore massimo: %d\n", ricercaValoreMassimo(mat,DIM,DIM));
    // punto 4
    printf("Valore massimo: %d\n", ricercaValoreMinimo(mat,DIM,DIM));
    // punto 5
    printf("Valore medio della matrice: %.2f\n", mediaMatrice(mat,DIM,DIM));
    // punto 6
    mediaPariDispariMatrice(mat, DIM, DIM);
    printf("\n");
    // punto 7
    ordinamentoRigheCrescente(mat, DIM, DIM);
    stampaMatrice(mat, DIM, DIM);
    printf("\n");
    // punto 8
    sommaSingolaColonna(mat, DIM, DIM);
    printf("\n");
    // punto 9 per provarlo ricerca i valori 5 e sostituisce con 99 così è facile da vedere.
    sostituisciValoreMatrice(mat, DIM, DIM, 5, 99);
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

int ricercaValoreMassimo(int _mat[][DIM], int _r, int _c){
    int max;
    int i, j;

    max = _mat[0][0];
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            if(_mat[i][j] > max){
                max = _mat[i][j];
            }
        }
    }
    return(max);
}

int ricercaValoreMinimo(int _mat[][DIM], int _r, int _c){
    int min;
    int i, j;

    min = _mat[0][0];
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            if(_mat[i][j] < min){
                min = _mat[i][j];
            }
        }
    }
    return(min);
}

float mediaMatrice(int _mat[][DIM], int _r, int _c){
    int somma;
    int i, j;
    float media;

    somma = 0;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            somma = somma + _mat[i][j];
        }
    }

    media = (float)somma / (_r*_c);
    return(media);
}

void mediaPariDispariMatrice(int _mat[][DIM], int _r, int _c){
    int sPari, sDispari;        // variabili per le somme pari e dispari
    int cntPari, cntDispari;    // contatori dei valori pari e dispari trovati.
    float mPari, mDispari;      // variabili per le medie risultanti.
    int i,j;

    sPari = 0;                  // azzero le variabili somma e contatori.
    sDispari = 0;
    cntPari = 0;
    cntDispari = 0;

    for(i=0; i<_r; i++){        // scorro tutta la matrice e per ogni valore determino se pari o dispari.
        for(j=0; j<_c; j++){
            if(_mat[i][j]%2 == 0){
                sPari = sPari + _mat[i][j];
                cntPari++;
            }
            else{
                sDispari = sDispari + _mat[i][j];
                cntDispari++;
            }
        }
    }

    mPari = (float)sPari / cntPari;             // calcolo le due medie e poi le stampo.
    mDispari = (float)sDispari / cntDispari;

    printf("Media dei %d valori pari trovati: %.2f\n", cntPari, mPari);
    printf("Media dei %d valori dispari trovati: %.2f\n", cntDispari, mDispari);
}

void sommaSingolaColonna(int _mat[][DIM], int _r, int _c){
    int i, j;
    int sColonna;
    stampaMatrice(_mat, _r, _c);
    for(i=0; i<_c; i++){
        printf("---");
    }
    printf("\n");
    for(i=0; i<_c; i++){
        sColonna = 0;
        for(j=0; j<_r; j++){
            sColonna = sColonna + _mat[j][i];
        }
        printf("%3d", sColonna);
    }
}

void sostituisciValoreMatrice(int _mat[][DIM], int _r, int _c, int _src, int _dst){
    int i, j;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            if(_mat[i][j] == _src)
                _mat[i][j] = _dst;
        }
    }
}