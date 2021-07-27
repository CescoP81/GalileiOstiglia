#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona{
    char nome[20];
    char cognome[20];
    int anni;    
}Persona;

int main(){
    // mi creo una variabile di tipo Persona
    Persona p1;
    
    // riempio i campi della varibaile Persona.
    strcpy(p1.cognome, "Rossi");
    strcpy(p1.nome, "Giorgio");
    p1.anni = 45;

    // stampo i campi della persona p1.
    printf("%s %s %d", p1.cognome, p1.nome, p1.anni);

    // scrivere su file la persona presente.
    FILE *fpout;
    fpout = fopen("elenco_di_gino.bin", "wb");
        fwrite(&p1, sizeof(Persona), 1, fpout);
    fclose(fpout);

    // verifico il contenuto del file.
    Persona p2;
    FILE *fpin;
    fpin = fopen("elenco_di_gino.bin", "rb");
        fread(&p2, sizeof(Persona), 1, fpin);
    fclose(fpin);
    printf("\n\n%s %s %d", p2.cognome, p2.nome, p2.anni);
    
    return(0);
}