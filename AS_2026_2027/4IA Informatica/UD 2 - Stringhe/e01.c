/*  Data: 21.10.26
    Author: F. Pradella
    Description: Introduzione all'uso delle stringhe.*/
#include <stdio.h>

#define DIM 20

int main(){
    //  dichiaro una stringa.
    char str[DIM];
    //  dichiaro variabili di uso comune
    int i;
    char junk;
    //  dichiaro una variabile per calcolare la lunghezza.
    int len;

    /* inizializzo ogni cella del vettore di caratteri con '\0' o terminatore di stringa.*/
    for(i=0; i<DIM; i++)
        str[i] = '\0';
    
    /*  Acquisisco una singola parola.
        ATTENZIONE: con la scanf due parole non vengono acquisite, si ferma allo spazio tra le due.
        "ciao mamma" -> la scanf acquisisce solo "ciao" e poi inserisci '\0'
    */
    printf("Inserisci una parola: ");
    scanf("%s", str);
    junk = getchar();

    /*  Visualizzo la parola contenuta nel vettore str usando %s,
        la printf si ferma quando trova un '\0'.
    */
    printf("1. Parola inserita: %s\n", str);

    /*  Calcolo la lunghezza della stringa contenuta in str,
        sfrutto un ciclo finche non trovo il carattere terminatore '\0'
    */
    len = 0;
    while(str[len] != '\0'){
        len++;
    }
    printf("2. Lunghezza stringa: %d\n", len);

    /*  Visualizzo la stringa al contrario
        ATTENZIONE non parto dalla cella DIM-1 ma da len-1 e visualizzo un singolo carattere alla volta.
    */
    printf("3. Stringa capovolta: ");
    for(i=len-1; i>=0; i--){
        printf("%c", str[i]);
    }
    printf("\n");

    printf("3bis. Stringa capovolta: ");
    for(i=0; i<len; i++){
        printf("%c", str[len-i-1]);
    }
    printf("\n");


    /*  ORA SVILUPPIAMO LE FUNZIONI...
        quindi creiamo di nuovo lib.c e lib.h specializzati sulle stringhe.
        PER IL MOMENTO le funzioni di libreria <string.h> NON CI SERVONO, CE LE CREIAMO!
    */
    return 0;
}