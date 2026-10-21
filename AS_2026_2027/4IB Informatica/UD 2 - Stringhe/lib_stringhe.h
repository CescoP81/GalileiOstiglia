/* SONO PRESENTI SOLO I PROTOTIPI DELLE FUNZIONI */

/**
 * Inizializza un vettore di caratteri con '\0' in tutte le celle
 * @param int   Dimensione del vettore
 * @param char* Riferimento al vettore di caratteri.
 */
void initStringa(int _dim, char _str[]);

/**
 * Stampa una stringa char-by-char
 * @param int   Dimensione del vettore
 * @param char* Riferimento al vettore
 */
void strCharByChar(int _dim, char _str[]);

/**
 * Calcola e restituisce la lunghezza di una stringa.
 * @param int   Dimensione del vettore.
 * @param char* Riferimento al vettore.
 * @return Numero di lettere che compongono la stringa (-1 se stringa non misurabile).
 */
int lunghezzaStringa(int _dim, char _str[]);

/**
 * Calcola e restituisce il numero di VOCALI presenti nella stringa
 * @param int   Dimensione del vettore
 * @param char* Riferimento alla stringa
 * @return Numero di vocali presenti nella stringa.
 */
int contaVocali(int _dim, char _str[]);