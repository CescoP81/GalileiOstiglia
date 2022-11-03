/*  Data: 03/11/22
    Author: Francesco Pradella
    Filename: p09.c
    Abstracty: Richiedere due numeri da tastiera (val1 e val2), se val1 è maggiore di val2 scambiarli quindi visualizzare tutti i numeri presenti tra val1 e val2.
*/
#include <stdio.h>

int main(){
    int val1;
    int val2;
    int tmp;
    int cnt;

    printf("Inserisci val1: ");
    scanf("%d", &val1);
    fflush(stdin);
    printf("Inserisci val2: ");
    scanf<("%d", &val2);
    fflush(stdin);

    if(val1 > val2){    // se val1 è maggiore di val2 li scambio con l'utilizzo di una variabile temporanea
        tmp = val1;
        val1 = val2;
        val2 = tmp;
    }

    // faccio la ciclica per vedere i numeri compresi tra val1 e val2, estremi compresi
    cnt = val1;
    while(cnt <= val2){
        printf("%d ", cnt);
        cnt = cnt + 1;
    }

    return(0);
}