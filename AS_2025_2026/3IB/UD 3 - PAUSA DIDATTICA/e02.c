/*
Realizza un programma C che richiede un valore N intero da tastiera, se compreso tra 1 e 15,
genera N numeri casuali e per i numeri pari mostra anche i divisori.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n; // valore iniziale;
    int random; // variabile per i valori random generati.
    int cnt; // contatore dei numeri generati.
    int div; // variabile per il ciclo dei divisori in caso di numero pari.
    char junk;
    srand(time(NULL));

    printf("Inserisci un valore: ");
    scanf("%d", &n);
    junk = getchar();

    if(n>=1 && n<=15){
        for(cnt = 1; cnt <= n; cnt++){
            random = 1 + rand()%100;
            if(random%2 == 0){
                printf("%d PARI: ", random);
                div = 1;
                while(div <= random){
                    if(random%div == 0){
                        printf("%d ", div);
                    }
                    div++;
                }
            }
            else{
                printf("%d DISPARI.", random);
            }
            printf("\n");
        }
    }
    return(0);
}