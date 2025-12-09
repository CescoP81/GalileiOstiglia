/*
    Utilizzando le iterative innestate realizza i seguenti schemi grafici:
    1:
    +
    + +
    + + +
    + + + +
    + + + + +

    2:
    + + + + +
      + + + + 
        + + + 
          + + 
            +

    3:
    + + + + +
    + - - - +
    + - - - +
    + - - - +
    + + + + +
    
    4:
    +
      +
        +
          +
            +
    
    Realizzarli prima come 5x5 e poi con valori righe e colonne richiesti all'utente.     
*/
#include <stdio.h>

int main(){
    int r;
    int c;

    printf("Esercizio 1: \n");
    r = 1;
    while(r <= 5){
        c = 1;
        while(c <= r){
            printf("+ ");
            c = c + 1;
        }
        printf("\n");
        r = r + 1;
    }
    printf("\n\n");
    printf("Esercizio 2: \n");
    r = 1;
    while(r <= 5){
        c = 1;
        while(c <= 5){
            if(c >= r){
                printf("+ ");
            }
            else{
                printf(" ");
            }
            c = c + 1;
        }
        printf("\n");
        r = r + 1;
    }

    printf("\n\n");
    printf("Esercizio 3:\n");
    // ciclica della parte altaù
    c = 1;
    while(c <= 5){
        printf("+ ");
        c = c + 1;
    }
    printf("\n");
    r = 1;
    while(r <= 3){
        c = 1;
        while(c <= 5){
            if((c==1) || (c== 5)){
                printf("+ ");
            }
            else{
                printf("- ");
            }
            c = c + 1;
        }
        printf("\n");
        r = r + 1;
    }
    c = 1;
    while(c <= 5){
        printf("+ ");
        c = c + 1;
    }
    printf("\n\n");
    printf("Eserzicio 4:\n");
    r = 1;
    while(r <= 5){
        c = 1;
        while(c <= 5){
            if(c == r){
                printf("+ ");
            }
            else{
                printf("  ");
            }
            c = c + 1;
        }
        printf("\n");
        r = r + 1;
    }
    return(0);
}