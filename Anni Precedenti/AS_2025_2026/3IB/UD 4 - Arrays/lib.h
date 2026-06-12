// Contiene solamente i prototipi delle funzioni sviluppate nel file 'lib.c' e relativa documentazione.

/**
 * [IT] Funzione che inizializza un vettore con valori random compresi tra 1 e 99. 
 * [EN] Function that initializes a vector with random values ​​between 1 and 99.
 * 
 * @param int[] Reference to the vector to use.
 * @param int Size of the vector in use.
 */
void inizializzaVettoreRandom(int _vet[], int _dim);
/**
 * [IT] Stampa un vettore di interi su singola riga.
 * [EN] Prints a vector of integers on a single line.
 * 
 * @param int[] Reference to the vector to use.
 * @param int Size of the vector in use.
 */
void stampaVettore(int _vet[], int _dim);
/**
 * [IT] Calcola e restituisce la media dei valori di vettore di interi.
 * [EN] Calculates and returns the average of the values ​​of an integer vector.
 * 
 * @param int[] Reference to the vector to use.
 * @param int Size of the vector in use.
 * @return The avarage value.
 */
float getMediaVettore(int _vet[], int _dim);
// da realizzare...

/**
 * [IT] Restituisce il valore massimo che compare nel vettore.
 * [IT] Returns the maximum value that appears in the vector.
 * 
 * @param int[] Reference to the vector to use.
 * @param int Size of the vector in use.
 * @return The max value.
 */
int getValoreMassimo(int _vet[], int _dim);

int getValoreMinimo(int _vet[], int _dim);
/**
 * [IT] Determina se un numero è primo oppure no; 0 non primo, 1 primo.
 */
int isPrimo(int _val);
/**
 * [IT] Stampa i soli valori primi presenti nel vettore
 */
void stampaValoriPrimi(int _vet[], int _dim);