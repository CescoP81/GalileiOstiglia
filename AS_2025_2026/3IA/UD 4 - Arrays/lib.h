/* header contentente solamente i prototipi e relativa documentazione
     delle funzioni di libreria. */

/**
 * [IT] Inizializza un vettore di interi con valori casuali da 1 a 10.
 * 
 * [EN] Init an array with random values between 1 an 10
 * @param int* Array reference.
 * @param int Array length.
 */
void initVettore(int _vet[], int _dim);

/**
 * [IT] Visualizza un vettore di valori interi.
 * 
 * [EN] Print an array of integer values
 * @param int* Array reference.
 * @param int Array length.
 */
void stampaVettore(int _vet[], int _dim);

/**
 * [IT] Stampa un vettore in formato grafico, rettangolando secondo i codice della tabella
 * ASCII in modo da realizzare le singole celle, sotto alle celle sono visualizzati
 * gli indici del vettore.
 * 
 * [EN] Print an array in a "graphical mode" where each cell has a border outside.
 * Following the array a line with indexes is printed.
 * @param int* Array reference.
 * @param int Array length.
 */
void stampaVettoreGrafico(int _vet[], int _dim);

/**
 * UTILIZZA CARATTERI COMPATIBILI CON GITHUB CODESPACE (primi 127 caratteri della ASCII table)
 * 
 * [IT] Stampa un vettore in formato grafico, rettangolando secondo i codice della tabella
 * ASCII in modo da realizzare le singole celle, sotto alle celle sono visualizzati
 * gli indici del vettore.
 * 
 * [EN] Print an array in a "graphical mode" where each cell has a border outside.
 * Following the array a line with indexes is printed.
 * @param int* Array reference.
 * @param int Array length.
 */
void stampaVettoreGraficoBasic(int _vet[], int _dim);
/**
 * [IT] Richiede l'inserimento manuale dei valori nel vettore con il vincolo che siano compresi tra min e max
 * [EN] ...
 * 
 * @param int* Array reference.
 * @param int Array length.
 * @param int Min value allowed
 * @param int Max value allowed
 */
void inputManualeArray(int _vet[], int _dim, int _min, int _max);

// --- Funzioni per e03.c ---

/**
 * Funzione che converte un numero intero in un array binario.
 * 
 * @param int Numero da convertire.
 * @param int[] Riferimento al vettore 'binario'.
 * @param int Dimensione del vettore.
 * @return 0/1 in caso affermativo o negativo dell'avvenuta conversione.
 */
int convertiBinario(int _n, int _v[], int _dim);

/**
 * Stampa un vettore di bit in formato binario.
 * 
 * @param int[] Riferimento al vettore.
 * @param int Dimensione del vettore.
 */
void stampaBinario(int _v[], int _dim);
/**
 * Stampa un vettore binario indicando la potenza di ogni singolo bit.
 * 
 * @param int[] Riferimento al vettore.
 * @param int Dimensione del vettore.
 */
void stampaBinarioBasic(int _vet[], int _dim);
/**
 * Funzione che realizza la somma tra bin1 e bin2 in bin3
 * 
 * @param int[] Vettore binario 1 - Primo numero
 * @param int[] Vettore binario 2 - Secondo numero
 * @param int[] Vettore binario 3 - Vettore risultante
 * @param int Dimensione in bit dei vettori.
 * @return 1/0 in caso affermativo o negativo che la funzione abbia generato overflow.
 */
int sommaBinaria(int _bin[], int _bin2[], int _bin3[], int _dim);