/*
Realizzare un programma C che permetta di inserire 3 valori da tastiera,
comunica il valore massimo e minimo inserito e per ognuno dei tre valori
visualizza la scomposizione in fattori primi.
*/
#include <stdio.h>

int main(){
    int num;        // variabile per il numero inserito.
    int fattore;    // fattori primo che divide il numero inserito.
    char junk;

    printf("Inserisci un numero: ");
    scanf("%d", &num);
    junk = getchar();

    fattore = 2;        // se partissi da 1 sarebbe un ciclo infinito.
    while(num > 1){
        if(num % fattore == 0){     // se il numero è multiplo del fattore, stampo il fattore e divido il numero per il fattore.
            printf("%d ", fattore);
            num = num / fattore;
        }
        else{                       // se fattore non divide il numero, passo al fattore successivo.
            fattore = fattore + 1;
        }
    }
    return(0);
}