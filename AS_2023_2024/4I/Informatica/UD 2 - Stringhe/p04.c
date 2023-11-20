/**
 * Esempio di utilizzo di un vettore di stringhe, concettualmente è una matrice di caratteri dove 
 * ogni singola riga rappresenta una stringa.
 * Commentando il codice da riga 15 a riga 30 comprese, dopo averlo provato, sviluppare i seguenti punti:
 * - [ ] Acquisire 5 stringhe da tastiera.
 * - [ ] Stampare le 5 stringhe inserite come verifica.
 * - [ ] Per ogni stringa stampare la sua lunghezza.
 * - [ ] Determinare e stampare la stringa più lunga e la stringa più corta.
 * - [ ] Verificare se tra le parole sono presenti palindrome.
 * - [ ] Inserita una lettera da tastiera, determinare la parola che la contiene più volte.
 * - [ ] Modificare l'iniziale di ogni parola mettendola in maiuscolo.
 * - [ ] Visualizzare ogni parola al contrario.
*/
#include<stdio.h>
#include "lib.c"

const int DIM = 30;
const int ROWS = 10;

int main(){
    char parole[ROWS][DIM];
    int i;

    // inizializzo ogni singola riga come fossero stringhe singole.
    for(i=0; i<ROWS; i++){
        initStringa(parole[i], DIM);
    }

    // acquisisco tre stringhe da tastiera.
    for(i=0; i<3; i++){
        inputStringa(parole[i]);
    }

    // stampo a video le prime tre stringhe acquisite.
    for(i=0; i<3; i++){
        printf("%d -> %s\n", i, parole[i]);
    }
    printf("\n");
    return(0);
}