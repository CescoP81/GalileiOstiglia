/*  Contenuto del file LIB.H
    - contiene i prototipi e la documentazione delle funzioni
    che verrano poi sviluppate nel file lib.c
*/

/**
 * Inizializza un vettore con un valore iniziale.
 * @param int Dimensione del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore iniziale da impostare.
 */
void initVettore(int _dim, int _v[], int _value);

/**
 * Stampa i valori di un vettore su una singola riga.
 * @param int Dimensione del vettore
 * @param int* Riferimento al vettore
 */
void stampaVettore(int _dim, int _v[]);

/**
 * Popola un vettore con valori casuali compresi tra min e max.
 * @param int Dimensione del vettore
 * @param int* Rifrerimento al vettore
 * @param int Valore minimo del range
 * @param int Valore massimo del range
 */
void caricaVettore(int _dim, int _v[], int _min, int _max);

/**
 * Calcola e restituisce la media degli elementi del vettore
 * @param int Dimensione del vettore
 * @param int* Riferimento al vettore
 * @return Valore della media (La funzione NON STAMPA AL SUO INTERNO)
 */
float mediaVettore(int _dim, int _v[]);

/**
 * Determina e stampa i valori minimo e massimo presenti nel vettore.
 * @param int Dimensione del vettore.
 * @param int* Riferimento al vettore.
 */
void minimoMassimoVettore(int _dim, int _v[]);

/**
 * Ordina un vettore in modo crescente o decrescente con scelta dell'utente
 * @param int Dimensione del vettore.
 * @param int* Riferimento al vettore.
 * @param int Modo di ordinamento [0->Decrescente 1->Crescente]
 */
void ordinaVettore(int _dim, int _v[], int _modo);

//=========================================================================

/**
 * Inizializza una matrice di interi con valori random compresi tra min e max.
 * @param int Dimensione righe
 * @param int Dimensione colonne
 * @param int* Riferimento alla matrice
 * @param int Valore minimo del range
 * @param int Valore massimo del range
 */
void initMatrice(int _rows, int _cols, int _m[_rows][_cols], int _min, int _max);

/**
 * Stampa una matrice di interi
 * @param int Dimensione righe
 * @param int Dimensione colonne
 * @param int* Riferimento alla matrice
 */
void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Determina e restituisce il valore medio della matrice
 * @param int Dimensione righe.
 * @param int Dimensione colonne.
 * @param int* Riferimento alla matrice.
 */
float mediaMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Matrice scacchiera: riempie una matrice con numeri 1/0 in modo alternato simulando una scacchiera.
 * @param int Dimensione righe.
 * @param int Dimensione colonne.
 * @param int* Riferimento alla matrice.
 */
void matriceScacchiera(int _rows, int _cols, int _m[_rows][_cols]);