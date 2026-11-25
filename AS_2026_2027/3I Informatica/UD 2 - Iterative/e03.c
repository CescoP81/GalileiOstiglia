/*
    Author: PRadella F.
    Date: 25.11.2026
    Abstract: Realizza un programma C che richiede in input due valori (v1 e v2),
    se v2 è maggiore di v1 allora visualizza tutti i valori compresi tra v1 e v2,
    altrimenti visualizza il messaggio "Serie non disponibile".
*/
#include <stdio.h>

int main(){
    int v1;
    int v2;
    int cnt;
    char junk;

    // fase di input dei due valori
    printf("Inserisci il valore 1: ");
    scanf("%d", &v1);
    junk = getchar();

    printf("Inserisci il valore 2: ");
    scanf("%d", &v2);
    junk = getchar();

    // determino se v2 è maggiore di v1
    if(v2 > v1){
        // condizione vera allora posso fare la serie richiesta
        cnt = v1;
        while(cnt <= v2){
            printf("%d ", cnt);
            cnt = cnt + 1;
        }
    }
    else{
        // cado nell'else quando v1 è uguale oppure minore di v2
        printf("Serie non disponibile!\n");
    }
    return 0;
}