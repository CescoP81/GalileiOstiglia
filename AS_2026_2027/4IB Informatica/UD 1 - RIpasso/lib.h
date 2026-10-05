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