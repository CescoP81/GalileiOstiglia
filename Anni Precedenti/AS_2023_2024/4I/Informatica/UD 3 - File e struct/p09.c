/*
    Esempio di lettura di strutture su file binario con funzione fread.
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
    FILE* fpin;

    // inizializzo la struttura in memoria
    p = malloc(sizeof(Persona));

    // apro il file elenco.dat in lettura.
    fpin = fopen("elenco.dat", "rb");

    // ciclo di letture successive sul file di elenco.
    while(fread(p, sizeof(Persona), 1, fpin) > 0){
        printf("%s %s %d\n", p->cognome, p->nome, p->eta);
    }

    // chiusura del file aperto in lettura, da fare sempre per evitare che si corrompa o si danneggi.
    fclose(fpin);
    return(0);
}