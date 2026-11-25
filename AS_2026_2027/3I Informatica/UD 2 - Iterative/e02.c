/*
    Author: PRadella F.
    Date: 25.11.2026
    Abstract: Realizza un programma C che richiede in input un valore intero,
    visualizza tutti i valori da 1 al valore inserito.
*/
#include <stdio.h>

int main(){
    int valore;
    int cnt;
    char junk;

    // fase di input iniziale
    printf("Inserisci un valore: ");
    scanf("%d", &valore);
    junk = getchar();

    // fase di stampa dei valori da 1 al valore inserito
    printf("Serie Numerica: ");
    cnt = 1;
    while(cnt <= valore){
        printf("%d ", cnt);
        cnt = cnt + 1; // equivalente a cnt++
    }
    return 0;
}