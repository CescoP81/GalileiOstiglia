/*
    Creare un programma che richiede l'inserimento di una parola di lunghezza massima 20 char.
    in un secondo momento esegue queste due operazioni:

    1. Richiede un carattere da tastiera e richiama una funzione che ricevendo la parola e il carattere
    restituisce il numero di volte che compare
    es: casa 'a' -> a presente 2 volte.

    2. Richiama una funzione che verifica e restituisce 0 o 1, in base alla presenza
    o meno di lettere doppie.
    es: tosto -> 0 -> nessuna doppia; sotto -> 1 -> Ci sono delle doppie.

    DA FARE CON FUNZIONI!!!
*/
#include <stdio.h>
const int DIM=20;

int main(){
    int a, b;
    char str[DIM];
    char c;
    int tmp;

    printf("a: ");
    scanf("%d", &a);
    fflush(stdin);

    printf("b: ");
    scanf("%d", &b);
    fflush(stdin);

    printf("%d", (a+b));
    printf("\n\n");

    printf("Inserisci una parola: ");
    scanf("%s", str);
    fflush(stdin);

    printf("Inserisci un carattere: ");
    scanf("%c", &c);
    fflush(stdin);

    printf("\n\n%s -> %c", str, c);

    return(0);
}