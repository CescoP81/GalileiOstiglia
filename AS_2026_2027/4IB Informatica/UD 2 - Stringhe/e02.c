#include <stdio.h>
#include "lib_stringhe.c"

#define DIM 20

int main(){
    char str[DIM];
    int i;
    char junk;

    // richiamo la funzione per inizializzare il vettore di caratteri.
    initStringa(DIM, str);

    printf("Inserisci una parola: ");
    scanf("%s", str);
    junk = getchar();

    printf("Parola Inserita: %s\n", str);
    strCharByChar(DIM, str);

    printf("\nLunghezza della stringa %s: %d\n", str, lunghezzaStringa(DIM, str));

    // richiamo della funzione contaVocali.
    

    return 0;
}