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