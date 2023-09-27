/*
    Applicazione per l'inserimento di 5 persone indentificate da Nome, Cognome, Residenza e memorizzate
    su un file binario 'elenco.dat' e su un file formato CSV (Comma Separated Values).
    IL programma utilizza Strutture, Scrittura su file binari, Scrittura su file di testo.

    Nome,Cognome,Paese
    Maria,Rossi,Ostiglia,
    Marta,Bianchi,Revere,
    Luigi,Neri,Libiola
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    char cognome[30];
    char paese[30];
}Persona;

int main(){
    Persona elenco[3];
    int i;
    FILE *fpOut;

    // inserimento del vettore di strutture
    for(i=0; i<3; i++){
        printf("Inserisci nome: ");
        scanf("%s", elenco[i].nome);
        fflush(stdin);

        printf("Inserisci cognome: ");
        scanf("%s", elenco[i].cognome);
        fflush(stdin);

        printf("Inserisci paese: ");
        scanf("%s", elenco[i].paese);
        fflush(stdin);
    }

    // verifico stampando l'elenco
    for(i=0; i<3; i++)
        printf("%s %s %s \n", elenco[i].nome, elenco[i].cognome, elenco[i].paese);

    // salvataggio dei dati in formato binario su file .dat
    fpOut = fopen("elenco.dat", "wb");
    for(i=0; i<3; i++)
        fwrite(&elenco[i], sizeof(Persona), 1, fpOut);
    fclose(fpOut);

    // salvataggio dei dati in formato testuale con file .csv
    fpOut = fopen("elenco.csv", "wt");
    fprintf(fpOut,"Nome,Cognome,Paese,\n");
    for(i=0; i<3; i++)
        fprintf(fpOut,"%s,%s,%s,\n", elenco[i].nome, elenco[i].cognome, elenco[i].paese);
    fclose(fpOut);
    return(0);
}
