/*
Realizza un programma C che richiede in input tre valori interi maggiori di zero,
determina e comunica il valore minimo e massimo.
*/
#include <stdio.h>

int main(){
    int v1;     // variabile per il primo valore
    int v2;     // variabile per il secondo valore.
    int v3;     // variabile per il terzo valore.
    char junk;  // variabile per pulire il buffer di tastiera dopo le scsanf()
    int min;    // variabile per determinare il valore minimo.
    int max;    // variabile per determinare il valore massimo.

    // fase di input
    printf("Inserisvi V1: ");
    scanf("%d", &v1);
    junk = getchar();

    printf("Inserisci il V2: ");
    scanf("%d", &v2);
    junk = getchar();

    printf("Inserisci V3: ");
    scanf("%d", &v3);
    junk = getchar();

    if((v1>0) && (v2>0) && (v3>0)){ // test se tutti e tre i valori sono maggiori di zero, quindi validi.
        //printf("--entro in if generale\n");
        min = v1;
        if(v2 < min)
            min = v2;
        if(v3 < min){
            //printf("Entro in test v3-min\n");
            min = v3;
        }
        
        max = v1;
        if(v2 > max)
            max = v2;
        if(v3 > max)
            max = v3;

        printf("Il valore minimo: %d; il valore massimo: %d\n", min, max);
    }
    else{
        printf("Uno o piu' valori non sono maggiori di zero.\n");
    }
    return(0);
}