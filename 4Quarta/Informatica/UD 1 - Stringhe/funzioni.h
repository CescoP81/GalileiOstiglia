// FILE CON I PROTOTIPI DELLE FUNZIONI.

/**
 * Determina la lunghezza di una stringa passata come parametro, basandosi sul terminatore '\0'
 * @param char[] Stringa da utilizzare
 * @return int Lunghezza della stringa.
 */
int strLength(char []);

/**
 * Determina la lunghezza di una stringa passata come parametro, basandosi sul terminatore '\0'
 * @param char[][] Matrice di stringhe da utilizzare
 * @return int Numero di righe che compongono la matrice.
 */
int getIndexMaxLength(char [][DIM], int);

/* --- PASSAGGIO ALL'USO DEI PUNTATORI ---*/
/**
 * Restituisce la lunghezza di una stringa basandosi sul terminatore '\0'
 * @param char* Puntatore alla stringa.
 * @return int Lunghezza della stringa.
 */
int getStringLength(char *);
/**
 * Restituisce il numero di occorrenze di un carattere in una stringa.
 * @param char* Puntatore alla stringa.
 * @param char Carattere da ricercare.
 * @return int Numero di occorrenze trovate.
 */
int getOccurenciesOf(char *, char);
/** Restituisce la lettera che compare più volte, se due lettere hanno lo stesso numero di contatore, stampa l'ultima trovata.
 * @param char* Puntatore alla stringa.
 * @return char Lettera determinata.
 */
char getCharMostPresent(char*);
/**
 * Determina se una parola è palindroma oppure no
 * @param char* Puntatore alla stringa.
 * @return int 1 se la regola è verificata, altrimenti 0
 */
int checkStrPalindroma(char *);
/**
 * Restituisce il numero di parole che compongono una frase, come separatore utilizza lo spazio.
 * @param char* Puntatore alla stringa.
 * @return int Numero di parole presenti.
 */
int getNumberOfWords(char*);

