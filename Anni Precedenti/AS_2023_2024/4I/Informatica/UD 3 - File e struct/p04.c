/*
Programma che richiede parole all'utente ed in caso siano di un numero di caratteri
dispari allora le salva in un file denominato 'parole.txt' separandole da uno spazio.
L'inserimento termina con la parola chiave "fine". Il programma deve comunicare
all'utente quante parole sono inserite nel file, la lunghezza più corta e quella
più lunga.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char DIM=30;


int main(){
    char str[DIM];
    FILE *fpOut;
    FILE *fpIn;
    int cntParole, lMin, lMax;

    fpOut = fopen("parole.txt", "wt");
    
    do{
        // input della parola per l'utente
        printf("Inserisci una parola: ");
        scanf("%s", &str);
        fflush(stdin);

        // strlen -> restituisce la lunghezza di una stringa
        // con %2 verifico se è un numero pari o dispari, mi interessa che sia dispari
        // quindi resto == 1.
        if((strlen(str)%2 == 1) && (strcmp(str,"fine")!=0)){
            // scrivo la parola sul file
            fprintf(fpOut, "%s ", str);
        }
    }while(strcmp(str,"fine") != 0);
    fclose(fpOut);

    // riapertura dell'archivio parole in LETTURA e calcolo dei valori richiesti
    cntParole = 0;
    lMax = 0;
    lMin = DIM;
    int x;

    fpIn = fopen("parole.txt", "rt");
    while(!feof(fpIn)){
        fscanf(fpIn, "%s", &str);
        cntParole++;
        if(strlen(str) > lMax)
            lMax = strlen(str);
        if(strlen(str) < lMin)
            lMin = strlen(str);
    }
    fclose(fpIn);
    cntParole--;
    printf("Numero parole nel file: %d\n", cntParole);
    printf("Lunghezza minima: %d\n", lMin);
    printf("Lunghezza massima: %d\n", lMax);
    return(0);
}