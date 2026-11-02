/* FILE DEI SOLI PROTOTIPI */

/**
 * Inizializza un vettore con valori random comrpesi tra min e max,
 * se min è maggiore o uguale a max, allora il vettore viene inizializzato
 * con valore costante -1.
 * @param int Dimensione del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore minimo del random.
 * @param int Valore massimo del random.
 */
void initVettore(int _dim, int _v[], int _min, int _max);

void stampaVettore(int _dim, int _v[]);

/**
 * Ricerca e sistituisce valori
 * @param int Dimensione del vettore
 * @param int* Riferimento al vettore
 * @param int Valore da ricercare
 * @param int Valore Sostituto/Somma
 */
void ricercaSostituisci(int _dim, int _v[], int _v1, int _v2);

/**
 * Ricerca e comunica la posizione del valore massimo del vettore
 * @param int Dimensione del vettore.
 * @param int* Riferimento al vettore
 * @return Numero di volte in cui compare il valore massimo.
 */
int massimoVettore(int _dim, int _v[]);

/**
 * Trova valori adiacenti uguali, ritorna 1 se verifica positiva altrimenti ritorna zero.
 * @param int Dimensione del vettore
 * @param int* Riferimento al vettore
 * @return Vero/falso se trovo o meno valori uguali adiacenti
 */
int trovaDoppi(int _dim, int _v[]);