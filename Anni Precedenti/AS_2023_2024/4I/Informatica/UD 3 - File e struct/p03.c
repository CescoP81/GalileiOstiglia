/*
    Esempio di lettura di valori da file, utilizzanod %d nella fscanf
    così come farei a video e da tastiera.
    NB: Il file DEVE contenere solo numeri interi con %d e in virgola si %f.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fpIn; // input da file, lo stream lo intendo dal file al pc.
    char str[20];
    int somma;
    int num;

    fpIn = fopen("parole.txt", "rt");
    somma = 0;
    while(!feof(fpIn)){
        // leggo una parola dal file.
        fscanf(fpIn, "%d", &num);
        somma = somma + num;
        // stampo la parola letta e messa in str, a video.
        printf("%d\n", num);
    }
    printf("Somma totale: %d", somma);
    fclose(fpIn);
    return(0);
}