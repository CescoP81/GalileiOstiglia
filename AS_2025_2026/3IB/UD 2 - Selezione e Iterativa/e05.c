/*
    Creo un programma che richiede un numero intero positivo e comunica
    a video tutti i valori compresi tra il valore inserito e 50.
*/
#include <stdio.h>

int main(){
    int val; // variabile per il valore in input.
    int tmp; // variabile per la iterativa richiesta.
    char junk;

    // acquisizione del valore iniziale, input dell'utente.
    printf("Inserisci un valore(minore di 50): ");
    scanf("%d", &val);
    junk = getchar();

    if(val < 50){
        // se la risposta è vera allora posso fare l'iterativa.
        printf("\nValori possibili: ");
        tmp = val;
        while(tmp <= 50){
            printf("%d ", tmp);
            tmp = tmp + 1;
        }

        printf("\nValori pari: ");
        tmp = val;
        while(tmp <= 50){
            if(tmp%2 == 0){
                printf("%d ", tmp);
            }
            tmp = tmp + 1;
        }

        printf("\nValori dispari: ");
        tmp = val;
        while(tmp <= 50){
            if(tmp%2 != 0){
                printf("%d ", tmp);
            }
            tmp = tmp + 1;
        }

        // stampa di tutti i valori pari, divisbili per 3.
        printf("\nPari e multipli di 3: ");
        tmp = val;
        while(tmp <= 50){
            if((tmp%2 == 0) && (tmp%3 == 0)){
                printf("%d ", tmp);
            }
            tmp = tmp + 1;
        }
    }
    else{
        printf("\nSerie numerica non realizzabile...");
    }
    return(0);
}
/*
compilazione: gcc nomedefile.c
per eseguire: ./a.out
*/