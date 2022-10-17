/*  Data: 17/10/22
    Author: Francesco Pradella
    Filename: p03.c
    Abstracty: Realizzare un algoritmo che richiede un numero in input, successivamente comunica se il numero è PRIMO o se è PERFETTO.  
    def PRIMO: Un numero è primo se divisibile SOLO per 1 e per se stesso (3-7-11-13...)  
    def PERFETTO: Un numero è perfetto se la somma dei suoi divisori, escluso se stesso, è uguale al numero
    (6: 1+2+3=6; 28: 1+2+4+7+14=28; 12: 1+2+3+4+6=16 NO PERFETTO)
*/
#include <stdio.h>

int main(){
    int num;        // variabile per il numero inserito da tastiera.
    int div;        // variabile per la iterativa dei divisori.
    int cntDiv;     // contatore dei divisori trovati.
    int sommaDiv;   // somma totale dei divisori trovati.

    printf("Inserisci N: ");
    scanf("%d", &num);
    fflush(stdin);

    div = 1;
    cntDiv = 0;
    sommaDiv = 0;
    while(div <= num){
        if(num % div == 0){
            cntDiv = cntDiv + 1;
            sommaDiv = sommaDiv + div;
        }
        div = div + 1;
    }

    // test per verificare se il numero è primo, si basa sul contatore dei divisori trovati.
    if(cntDiv <= 2){
        printf("Il numero %d e' primo.\n", num);
    }
    else{
        printf("Il numero %d non e' primo.\n", num);
    }

    // test per verificare se il numero è perfetto, si basa sulla somma totale dei divisori trovati.
    if(sommaDiv == (num*2)){
        printf("Il numero %d e' perfetto.\n");
    }
    else{
        printf("Il numero %d non e' perfetto.\n");
    }
   
    return(0);
}