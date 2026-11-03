/*  Realizzare un programma che verifica se una parola inserita da tastiera è PALINDROMA oppure no.
    -> Cercare su Google la proprietà palindroma
    -> Sviluppare un algoritmo appropriato che la verifica.
    -> La verifica della palindroma deve essere fatta con una funzione.
*/
#include <stdio.h>
#include "lib_stringhe.c"

#define DIM 20

int main(){
    char parola[DIM];
    char junk;

    initStringa(DIM, parola);

    printf("Inserisci una parola: ");
    scanf("%s", parola);
    junk = getchar();

    if(isPalindroma(DIM, parola) == 1){
        printf("La parola %s puo' essere letta anche al contrario!\n");
    }
    else{
        printf("La parola %s NON puo' essere letta anche al contrario!!\n");
    }
    
    return 0;
}