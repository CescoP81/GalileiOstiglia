/*
    creare un programma C che sfruttando la conoscenza delle stringhe permetta le seguenti
    funzioni:
    - [] Inizializzazione di una stringa vuota.
    - [] Inserimento di una stringa da tastiera.
    - [] Conteggio delle lettere della stringa.
    - [] Conteggio di una lettera inserita da tastiera.
    - [] Conteggio di quante vocali compaiono nella stringa.
    - [] Sostituzione di una lettera src con una lettera sostitutiva dst.
    - [] Visualizzazione di una stringa al contrario.
    - [] Verifica se una parola inserita è palindroma.

    Ogni singolo punto è da realizzare con una specifica funzione, relativi parametri
    passati per valore/riferimento e con ritorno void o non-void. 
*/
#include <stdio.h>

const int DIM=21;
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

int main(){
    return();
}