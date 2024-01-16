/*
    Esercizio di esempio per la scrittura di singole parole su file.
    Il programma legge delle parole in input e le scrive su un file
    di testo finché non viene inserita la parola "fine".
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fpOut; // out inteso come stream che esce sul file -> in output.
    char str[20];

    // apertura del file da realizzare in scrittura.
    fpOut = fopen("parole.txt", "wt");
    do{
        // input della parola da tastiera.
        printf("Inserisci una parola: ");
        scanf("%s", &str);
        fflush(stdin);

        // scrittura della parola nel file seguita da uno spazio.
        fprintf(fpOut, "%s ", str);
    }while(strcmp(str,"fine") != 0);

    // chiudo lo stream al file, da fare SEMPRE!
    fclose(fpOut);
    return(0);
}