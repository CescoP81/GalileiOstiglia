/*
    Semplice programma che richiede in input un valore numeri intero, comunica se è
    positivo, negativo, oppure nullo.
*/
#include <stdio.h>

int main(){
    int v;
    char junk;

    // input del valore
    printf("Inserisci un valore intero: ");
    scanf("%d", &v);
    junk = getchar();

    // serie di if per capire com'è il valore inserito.
    if(v > 0){
        printf("Il valore e' positivo!\n");
    }
    if(v == 0){
        printf("Il valore e' nullo!\n");
    }
    if(v < 0){
        printf("Il valore e' negativo!\n");
    }

    if(v > 0){
        printf("Il valore e' positivo!\n");
    }
    else{
        if(v == 0){
            printf("Il valore e' nullo!\n");
        }
        if(v < 0){
            printf("Il valore e' negativo!\n");
        }
    }
    return(0);
}