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
 * @param char* Riferimento al vettore.
 * @return Numero di lettere che compongono la stringa (-1 se stringa non misurabile).
 */
int lunghezzaStringa(char _str[]);

/**
 * Calcola e restituisce il numero di VOCALI presenti nella stringa
 * _str[i] == 'a'; // "a" sbagliato.
 * @param char* Riferimento alla stringa
 * @return Numero di vocali presenti nella stringa.
 */
int contaVocali(char _str[]);

/**
 * Verifica proprietà PALINDROMA: Una parola si dice palindroma se è possibile leggerla al contrario.
 * es: RADAR, OTTO, OSSO... (per ulteriori parole chiedere a Google)
 * @param char* Riferimento alla stringa.
 * @return 1 se palindroma, 0 se non parlindroma.
 */
int isPalindroma(char _str[]);

/**
 * Verifica se una parola è palindroma oppure no.
 * @param char* Stringa di riferimento
 * @return 1/0 se è palindroma oppure no
 */
int isPalindroma(char _str[]);

/**
 * Conta per ogni singola lettere quante volte compare nella parola passata.
 * @param char* Riferimento alla parola da analizzare.
 */
void contaLettere(char _str[]);

/**
 * Verifica se due stringhe sono l'una l'anagramma dell'altra.
 * @param char* Riferimento alla prima stringa.
 * @param char* Riferimento alla seconda stringa.
 * @return 1 Anagramma presente, 0 Anagramma non presente.
 */
int isAnagramma(char _str1[], char _str2[]);