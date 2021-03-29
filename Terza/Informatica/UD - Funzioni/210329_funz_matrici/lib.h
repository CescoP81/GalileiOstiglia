#define _R 10
#define _C 10 
/* Funzione che inizializza una matrice con valori random
@param int[][] Riferimento alla matrice da inizializzare.
@param int Numero di righe
@param int Numero di colonne.
@return void.*/
void initMatrice(int _m[][_C], int _r, int _c);

/* Funzione che una matrice numerica.
@param int[][] Riferimento alla matrice da inizializzare.
@param int Numero di righe
@param int Numero di colonne.
@return void.*/
void stampaMatrice(int _m[][_C], int _r, int _c);

/* Funzione che una matrice numerica.
@param int[][] Riferimento alla matrice da inizializzare.
@param int Numero di righe
@param int Numero di colonne.
@return float Valore medio calcolato sulla matrice.*/
float mediaMatrice(int _m[][_C], int _r, int _c);

/* Funzione che determina la posizione del valor minimo.
@param int[][] Riferimento alla matrice da inizializzare.
@param int Numero di righe
@param int Numero di colonne.
@param int* Variabile per l'indici di riga trovato.
@param int* Variabile per l'indici di colonna trovato.
@return float Valore medio calcolato sulla matrice.*/
void ricercaMinimoMatrice(int _m[][_C], int _r, int _c, int *x, int *y);