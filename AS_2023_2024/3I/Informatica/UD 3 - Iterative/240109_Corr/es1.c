/*
Realizza un programma C che richiede valori in input da tastiera positivi e maggiori di zero, ad ogni
inserimento visualizza la somma dei valori inseriti e se il valore inserito è pari o dispari. La sequenza di
inserimento termina quando viene inserito un valore minore o uguale a zero.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int valore;
    int sommaValori;

    sommaValori = 0;
    do{
        printf("Inserisci un valore: ");
        scanf("%d", &valore);
        fflush(stdin);

        if(valore > 0){
            sommaValori = sommaValori + valore;
            printf("La somma attualmente vale: %d\n", sommaValori);
            if(valore%2 == 0)
                printf("Il valore %d inserito e' pari.\n\n", valore);
            else
                printf("Il valore %d inserito e' dispari.\n\n", valore);
        }
    }while(valore > 0);
    
    printf("Sequenza terminata, grazie.");
    return(0);
}