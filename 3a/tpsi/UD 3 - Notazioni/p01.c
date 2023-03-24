/*  Programma di conversione di un numero intero in base 10 a numero binario su 8 DIM bit. */
#include <stdio.h>

#define DIM 8

int main(){
    int bin[DIM];
    int n;
    int i;

    // richiedo il numero da convertire da decimale a binario
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    fflush(stdin);

    // eseguo la conversione per divisioni successive tenendo il resto.
    // il peso dei resti ottenuti è posizionato nel vettore in modo concorde con gli indici del vettore.
    for(i=0; i<DIM; i++){
        bin[i] = n%2;
        n = n/2;
    }

    // stampo il numero convertito, visualizzo il vettore partendo dalla cella DIM-1, la più significativa.
    // stampa del vettore al contrario per avere la corretta visualizzazione.
    printf("Numero in binario: ");
    for(i=DIM-1; i>=0; i--){
        printf("%d", bin[i]);
    }

    return(0);
}