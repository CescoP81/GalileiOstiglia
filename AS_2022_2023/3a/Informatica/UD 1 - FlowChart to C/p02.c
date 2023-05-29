/*  Data: 10/10/22
    Author: Francesco Pradella
    Filename: p02.c
    Abstracty: Realizzare un algoritmo che richiede un numero intero, quindi
    visualizza tutti i divisori di tale numero.
*/
#include <stdio.h>

int main(){
    int num; // variabile per il numero inserito d tastiera.
    int cnt; // variabile per il ciclo iterativo dei divisori.

    // fase di input
    printf("Inserisci N: ");
    scanf("%d", &num);
    fflush(stdin);

    // ciclo iterativo per i divisori.
    cnt = 1;
    while(cnt <= num){
        if(num%cnt == 0){
            printf("%d ", cnt);
        }
        cnt = cnt + 1;
    }
    getchar();
    return(0);
}