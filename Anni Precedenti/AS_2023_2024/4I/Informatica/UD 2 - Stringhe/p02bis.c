/*
    creare un programma C che sfruttando la conoscenza delle stringhe permetta le seguenti
    funzioni:
    - [x] Inizializzazione di una stringa vuota.
    - [x] Inserimento di una stringa da tastiera.
    - [x] Conteggio delle lettere della stringa.
    - [x] Conteggio di una lettera inserita da tastiera.
    - [x] Conteggio di quante vocali compaiono nella stringa.
    - [x] Sostituzione di una lettera src con una lettera sostitutiva dst.
    - [x] Visualizzazione di una stringa al contrario.
    - [x] Verifica se una parola inserita è palindroma.

    Ogni singolo punto è da realizzare con una specifica funzione, relativi parametri
    passati per valore/riferimento e con ritorno void o non-void.

    DIFFERISCE DA P02.C PER L'USO DELLA LIBRERIA CONTENENTE LE FUNZIONI SVILUPPATE.
*/
#include <stdio.h>
#include "lib.c"    // include il file con la definizione delle funzioni.

const int DIM=21;
int main(){
    char str[DIM];

    initStringa(str, DIM);
    inputStringa(str);
    printf("Stringa Inserita: %s.\n", str);
    printf("Lunghezza della stringa: %d.\n", lunghezzaStringa(str));
    printf("La lettera a compare %d volta/volte.\n", contaLetteraStringa(str, 'a'));
    printf("Nella stringa %s sono presenti %d vocali.\n", str, contaVocaliStringa(str));
    sostituisciCarattereStringa(str, 'a', 'z');
    printf("Stringa Inserita: %s.\n", str);
    printf("Stringa al contrario: ");
    stampaContrarioStringa(str);
    if(verificaPalindroma(str) == 1)
        printf("\nLa parola e' palindroma.");
    else
        printf("La parola NON E' palindroma.");
    return(0);
}