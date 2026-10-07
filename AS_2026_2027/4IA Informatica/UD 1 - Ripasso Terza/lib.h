/*
    File di dichiarazione prototipi, viene incluso dal file lib.c
*/

/**
 * Carica un vettore con valori random compresi tra un minimo e un massimo
 * passati come argomenti.
 * @param int* Riferimento al vettore.
 * @param int Dimensione del vettore.
 * @param int Valore minimo del range.
 * @param int Valore massimo del range.
 */
void caricaVettore(int _v[], int _dim, int _min, int _max);

/**
 * Visualizza un vettore su singola riga
 * @param int* Riferimento al vettore.
 * @param int Dimensione del vettore.
 */
void stampaVettore(int _v[], int _dim);

/**
 * Calcola e restituisce la media del vettore
 * @param int* Riferimento al vettore.
 * @param int Dimensione del vettore.
 * @return Valore medio calcolato.
 */
float mediaVettore(int _v[], int _dim);

/**
 * Restituisce il valore alla posizione indicata.
 * @param int* Riferimento al vettore.
 * @param int Dimensione del vettore.
 * @param int Indice scelto del vettore.
 * @return -1 se indice non esiste, altrimenti valore contenuto nella cella scelta.
 */
int getValoreAt(int _v[], int _dim, int _index);

/**
 * Stampa a video il sotto array identificato tra index1 e index2,
 * con index1 minore di index2.
 * @param int* Riferimento al vettore.
 * @param int Dimensione del vettore.
 * @param int Indice iniziale.
 * @param int Indice finale.
 * @return true se stampa è possibile, false se stampa non è possibile.
 */
bool stampaSubArray(int _v[], int _dim, int _index1, int _index2);

/**
 * Ordina un vettore in modo crescente o decrescente a scelta dell'utente
 * @param int* Riferimento al vettore
 * @param int Dimensione del vettore
 * @param int Modo di ordinamento 0 decrescente 1 crescente
 */
void ordinaVettore(int _v[], int _dim, int _mode);

//---------------------------

/**
 * Carica una matrice con valori random compresi tra 1 e 25.
 * @param int Numero righe della matrice.
 * @param int Numero colonne della matrice.
 * @param int* Riferimento alla matrice dichiara nel main.
 */
void caricaMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Stampa una matrice di interi
 * @param int Numero righe della matrice.
 * @param int Numero colonne della matrice.
 * @param int* Riferimento alla matrice dichiara nel main.
 */
void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Carica una matrice con 0/1 alternati
 * @param int Numero righe della matrice.
 * @param int Numero colonne della matrice.
 * @param int* Riferimento alla matrice dichiara nel main.
 */
void caricaMatriceScacchiera(int _rows, int _cols, int _m[_rows][_cols]);

/* provare a creare le funzioni per le seguenti richieste:
1. Calcolo del valor medio della matrice.
2. Stampa della matrice con somma totale di ogni singola riga.
3. Somma totale del triangolo inferiore e del triangolo superiore.
*/