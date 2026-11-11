/*  PROTOTIPI DELLE FUNZIONI 
    SVILUPPATE PER GESTIRE LE STRINGHE
*/

/**
 * Inizializza un vettore di caratteri a '\0'
 * @param int Dimensione del vettore
 * @param char* Riferimento al vettore
 */
void initStringa(int _dim, char _str[]);

/**
 * Calcola restituisce la lunghezza della stringa
 * @param char* Riferimento al vettore.
 * @return Lunghezza calcolata.
 */
int lunghezzaStringa(char _str[]);

/**
 * Stampa una stringa al contrario
 * @param char* Riferimento al vettore
 */
void stampaContrario(char _str[]);

/**
 * Conta quante volte compare un carattere nella stringa
 * @param char* Riferimento al vettore
 * @param char Lettera da ricercare
 * @return Numero di occorrenze trovato
 */
int contaCarattere(char _str[], char _src);