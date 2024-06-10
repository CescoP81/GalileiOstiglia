// FILE HEADER CON LE INTESTAZIONI DEI PROTOTIPI E BASTA

/**
 * Initialize a string to empty string with all '\0'.
 * @param char[] Reference to string(Array of char).
*/
void initStringa(char[], int);
/**
 * Request a string as input.
 * @param char[] Reference to string(Array of char).
*/
void inputStringa(char[]);
/**
 * Count and return the number of characters of the string.
 * @param char[] Reference to string(Array of char).
 * @return Number of characters.
*/
int lunghezzaStringa(char[]);
/**
 * Count and return the number of occurencies of a specific letter.
 * @param char[] Reference to string (Array of char).
 * @param char The selectec letter.
 * @return Number of occurencies 
*/
int contaLetteraStringa(char[], char);
/**
 * Count and return the number of all vocals
 * @param char[] Reference to string (Array of char)
 * @return Numbers of vocals.
*/
int contaVocaliStringa(char[]);
/**
 * Find and replace a specific letter with another one.
 * @param char[] Reference to string (Array of char).
 * @param char Letter to find and replace.
 * @param char New letter to use.
*/
void sostituisciCarattereStringa(char[], char, char);
/**
 * Print a string reversed.
 * @param char[] Reference to string (Array of char)
*/
void stampaContrarioStringa(char[]);
/**
 * Tests whether a string is equal to its opposite
 * @param char[] Reference to string (Array of char).
 * @return 1->True / 0->False 
*/
int verificaPalindroma(char[]);

// -- Realizzate per p03.c --
/**
 * Recursive printing of a string
 * @param char[] Reference to string.
 * @param int Starting index.
*/
void stampaStringaRicorsiva(char[], int);
/**
 * Counting of uppercase and lowercase chatarters.
 * @param char[] Reference to string.
*/
void contaMaiuscoleMinuscole(char[]);
/**
 * Check for double letters
 * @param char[] Reference to string.
*/
int verificaDoppie(char[]);
/** 
 * First letter capitalized
 * @param char[] Reference to string.
*/
void primaLetteraMaiuscola(char[]);
/**
 * Count of each single letter, uppercase and lowercase letter increment the same counter
 * @param char[] Reference to string.
*/
void contaSingoleLettere(char[]);
/**
 * Create a second string as the first reversed
 * example:
 * str_1 = ciao - str_2 = oaic
 * @param char[] Reference to the original string.
 * @param char[] Reference to the reversed string.
*/
void stringaInversa(char[], char[]);
/**
 * Check if the second string is an anagram of the first one
 * @param char[] Reference to first string.
 * @param char[] Reference to second string.
*/
int verificaAnagrammi(char[], char[]);
/**
* Genera un anagramma di str e lo restituisce in str_2
* @param char[] Riferimento a stringa orginale _str
* @param char[] Riferimento alla stringa anagramma _str2
*/
void generaAnagramma(char[], char[]);