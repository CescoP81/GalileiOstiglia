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

/**
 * Conta il numero di occorrenze per ogni lettera
 * @param char* Riferimento alla parola
 */
void contaInteroAlfabeto(char _str[]);

/**
 * Verifica se due parole sono una l'anagramma dell'altra. es: REMO e MORE
 * @param char* Riferimento alla prima parola
 * @param char* Riferimento alla seconda parola
 * @return Vero/falso
 */
bool isAnagramma(char _str1[], char _str2[]);