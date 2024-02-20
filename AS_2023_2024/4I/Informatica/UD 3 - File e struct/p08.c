/*
    Esempio di scrittura di strutture su file binario con funzione fwrite.
    riutilizzo sempre il puntatore p dopo aver scritto la struttura sul file.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    char cognome[20];
    int eta;
}Persona;

int main(){
    Persona* p;
    FILE* fpout;

    p = malloc(sizeof(Persona));        // alloco una struttura in memoria.
    fpout = fopen("elenco.dat", "wb");  // apro un file binario in scrittura.

    // richiedo i dati di una persona 1
    printf("Inserisci nome: ");
    scanf("%s", &(p->nome));
    fflush(stdin);
    printf("Inserisci cognome: ");
    scanf("%s", &(p->cognome));
    fflush(stdin);
    printf("Inserisci eta': ");
    scanf("%d", &(p->eta));
    fflush(stdin);
    // scrivo la persona su file
    fwrite(p, sizeof(Persona), 1, fpout);

    //--

    // richiedo i dati di una persona 2
    printf("Inserisci nome: ");
    scanf("%s", &(p->nome));
    fflush(stdin);
    printf("Inserisci cognome: ");
    scanf("%s", &(p->cognome));
    fflush(stdin);
    printf("Inserisci eta': ");
    scanf("%d", &(p->eta));
    fflush(stdin);
    // scrivo la persona su file
    fwrite(p, sizeof(Persona), 1, fpout);

    //--

    // richiedo i dati di una persona 3
    printf("Inserisci nome: ");
    scanf("%s", &(p->nome));
    fflush(stdin);
    printf("Inserisci cognome: ");
    scanf("%s", &(p->cognome));
    fflush(stdin);
    printf("Inserisci eta': ");
    scanf("%d", &(p->eta));
    fflush(stdin);
    // scrivo la persona su file
    fwrite(p, sizeof(Persona), 1, fpout);
      
    // chiudere il file o averlo incompleto.
    fclose(fpout);  
    return(0);
}