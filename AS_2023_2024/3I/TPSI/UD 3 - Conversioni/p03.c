#include <stdio.h>

int main(){
    int hex[4];
    int i;
    int numeroDecimale;

    // inserimento numero iniziale a base 10
    printf("Inserisci un numero decimale: ");
    scanf("%d", &numeroDecimale);
    fflush(stdin);

    // conversione da base 10 a base 16 (esadecimale).
    for(i=0; i<4; i++){
        hex[i] = numeroDecimale % 16;
        numeroDecimale = numeroDecimale / 16;
    }

    // visualizzazione del numero esadecmale
    // lo si visualizza partendo dalla cella n-1 fino a 0 compreso.
    for(i=3; i>=0; i--){
        //printf("%d ", hex[i]);
        if(hex[i]>=0 && hex[i]<=9) printf("%d", hex[i]);

        if(hex[i] == 10) printf("A");
        if(hex[i] == 11) printf("B");
        if(hex[i] == 12) printf("C");
        if(hex[i] == 13) printf("D");
        if(hex[i] == 14) printf("E");
        if(hex[i] == 15) printf("F");
    }


    return(0);
}