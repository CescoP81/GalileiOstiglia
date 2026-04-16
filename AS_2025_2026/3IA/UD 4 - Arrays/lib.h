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