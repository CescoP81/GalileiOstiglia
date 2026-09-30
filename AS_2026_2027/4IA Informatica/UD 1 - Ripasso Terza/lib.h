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
