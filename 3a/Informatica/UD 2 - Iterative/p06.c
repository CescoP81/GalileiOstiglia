#include <stdio.h>
#include <stdlib.h>

#define MIN 1
#define MAX 999

int main(){
    int val; // variabile per il valore inserito dall'utente.
    int div; // variabile per il ciclo dei divisori.
    int somma_div; // somma dei divisori per algoritmo num perfetto.
    int cnt_div; // contatore dei divisori trovati.

    // ciclo per inserimento di un numero corretto al mio programma
    do{
        printf("Inserisci un valore: ");
        scanf("%d", &val);
        fflush(stdin);
    }while(val < MIN || val > MAX);

    // ciclo determina numero primo
    cnt_div = 0;
    div = 1;
    while(div <= val){
        if(val%div == 0){
            cnt_div = cnt_div + 1;
        }
        div = div + 1;
    }
    if(cnt_div <= 2)
        printf("Il numero %d e' primo!\n", val);
    else
        printf("Il numero %d non e' primo.\n", val);
    
    // ciclo determina numero perfetto
    somma_div = 0;
    div = 1;
    while(div < val){
        if(val%div == 0){
            somma_div = somma_div + div;
        }
        div = div + 1;
    }
    if(somma_div == val){
        printf("%d e' perfetto con somma divisori %d.\n", val, somma_div);
    }
    else{
        printf("%d non e' perfetto con somma divisori %d.\n", val, somma_div);
    }
    
    return(0);
}