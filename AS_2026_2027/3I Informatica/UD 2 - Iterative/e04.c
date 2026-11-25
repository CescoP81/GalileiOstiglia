/*
    Author: PRadella F.
    Date: 25.11.2026
    Abstract: Realizza un programma C che richiede un valore in input, 
    visualizza tutti i valori PARI compresi tra il valore inserito e 100.
*/
#include <stdio.h>

int main(){
    int valore;
    int cnt;
    char junk;

    // fase di input valore iniziale
    printf("Inserisci un valore: ");
    scanf("%d", &valore);
    junk = getchar();

    // stampa di tutti i valori PARI compresi tra valore e 100.
    if(valore < 100){   // determino se posso creare la serie numerica.
        cnt = valore;
        while(cnt <= 100){
            if(cnt%2 == 0){
                printf("%d ", cnt);
            }
            cnt = cnt + 1;
        }
    }
    else{   // se il numero inserito è uguale o maggiore di 100, allora non posso realizzare la serie.
        printf("Serie non disponibile!\n");
    }

    return 0;
}