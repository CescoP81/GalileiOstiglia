/*
Realizzare un programma C che richieda ripetutamente l’inserimento di 10 valori,
per ogni valore comunica a video i divisori primi e determina il numero totale di divisori.
Es: n=12 → 1,2,3 sono divisori primi ma sono presenti 6 divisori in totale. (12 è divisibile per 1,2,3,4,6,12) 
*/
#include <stdio.h>

int main(){
    int cntValori;      // contatore valori inseriti dall'utente
    int val;            // valore inserito in input dall'utente
    int div;            // variabile per i divisori di un numero.
    int cntDivTotale;   // contatore generale dei divisori trovati(primi e non primi) per un numero.
    int divPrimo;       // variabile per determinare i divisori del divisore trovato.
    int cntDiv;         // contatore divisori trovati per verifica del Primo.
    char junk;

    cntValori = 1;
    while(cntValori <= 10){
        printf("Inserisci un valore: ");
        scanf("%d", &val);
        junk = getchar();

        div = 1;
        cntDivTotale = 0;
        while(div <= val){
            if(val % div == 0){
                cntDivTotale = cntDivTotale + 1;
                divPrimo = 1;
                cntDiv = 0;
                while(divPrimo <= div){
                    if(div % divPrimo == 0){
                        cntDiv = cntDiv + 1;
                    }
                    divPrimo = divPrimo + 1;
                }
                if(cntDiv <= 2){
                    printf("Divisore: %d e' primo\n", div);
                }
            }
            div = div + 1;
        }
        printf("Divisori totali: %d\n\n", cntDivTotale);
        cntValori = cntValori + 1;
    }
    return(0);
}