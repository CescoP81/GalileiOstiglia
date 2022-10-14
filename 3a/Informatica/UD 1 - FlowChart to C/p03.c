/*  Data: 10/10/22
    Author: Francesco Pradella
    Filename: p03.c
    Abstracty: Realizzare un algoritmo che richiede un numero intero, quindi:
    - visualizza tutti i divisori di tale numero
    - determina quanti divisori sono stati trovati
    - calcola la somma di tali divisori.
*/
#include <stdio.h>

int main(){
    int num;        // variabile per il numero richiesto da tastiera.
    int div;        // variabile per i divisori, la userò nella iterativa.
    int cnt;        // variabile per contare i divisori.
    int somma;      // variabile per la somma totale dei divisori trovati.

    // fase di input del numero da utilizzare
    printf("Inserisci numero: ");
    scanf("%d", &num);
    fflush(stdin);

    // iterativa per i divisori; deve iterare da 1 fino al numero stesso (compreso)
    printf("\n\nDivisori: ");
    cnt = 0;
    somma = 0;
    div = 1;
    while(div <= num){
        if(num % div == 0){         // condizione per stabilire se 'div' divide perfettamente 'num'.
            printf("%d ", div);     // visualizzo il divisore trovato.
            cnt = cnt + 1;          // aumento il contatore 'cnt' dei divisori trovati.
            somma = somma + div;    // aggiungo il divisore trovato alla variabile somma.
        }
        div = div + 1;              // incremento div per proseguire nelle iterazioni.
    }

    printf("\nSono stati trovati %d divisori e la loro somma e': %d", cnt, somma);
    return(0);
}