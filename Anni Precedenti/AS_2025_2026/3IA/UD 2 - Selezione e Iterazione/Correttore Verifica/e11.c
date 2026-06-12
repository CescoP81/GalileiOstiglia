/*
Realizzare un programma C che permetta di inserire 5 valori interi,
al termine dell’inserimento comunica il valore maggiore inserito e la media dei valori.
*/
#include <stdio.h>

int main(){
    int cnt;    // contatore per il numero di inserimenti (ciclo while)
    int max;    // variabile per memorizzare il maggiore tra i valori.
    int media;  // variabile per la media
    int n;      // variabile per il numero inserito.
    char junk;

    media = 0;
    max = -1;
    cnt = 1;
    while(cnt <= 5){                        // ciclica per inserire 5 valori
        printf("Inserisci un numero: ");    // fase di input del numero
        scanf("%d", &n);
        junk = getchar();
        
        if(n > max)                         // confronto il numero con il max trovato fino ad ora.
            max = n;

        media = media + n;                  // aggiungo il valore alla media (per ora è una somma dei valori)

        cnt = cnt + 1;
    }
    media = media / 5;
    printf("Il valore maggiore inserito: %d, la media dei valori: %d", max, media);
    return(0);
}