/*
Realizzare un programma C che richiede l’inserimento di un numero intero positivo, quindi determinare e
comunicare il successivo numero che sia multiplo di 3 e di 4 contemporaneamente.
*/
#include <stdio.h>

int main(){
    int valIn;
    char junk;
    int trovato;

    printf("Inserisci un valore iniziale: ");
    scanf("%d", &valIn);
    junk = getchar();

    trovato = 0;
    while(trovato == 0){
        valIn = valIn + 1;
        if((valIn%3 == 0) && valIn%4 == 0){
            trovato = 1;
        }
    }
    printf("Il successivo multiplo di 3 e 4 e': %d", valIn);
    return(0);
}