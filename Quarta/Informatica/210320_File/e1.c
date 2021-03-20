#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct persona{
    char nome[20];
    int anni;
}Persona;

int main(){
    Persona p1;
    Persona p2;
    Persona p3;
    FILE *fpout; // puntatore a file aperto in scrittura.
    FILE *fpin; // puntatore ad un file aperto in lettura.

    strcpy(p1.nome, "Alberto");
    p1.anni = 30;

    strcpy(p2.nome, "Rosa");
    p2.anni = 35;

    strcpy(p3.nome, "Simone");
    p3.anni = 27;

    // aprire il file su cui scrivere
    fpout = fopen("persone.bin", "wb"); // se il file esiste già, viene azzerato, altrimenti viene creato.
        fwrite(&p1, sizeof(Persona), 1, fpout);
        fwrite(&p2, sizeof(Persona), 1, fpout);
        fwrite(&p3, sizeof(Persona), 1, fpout);
    fclose(fpout);


    Persona p[3];
    int i;
    fpin = fopen("persone.bin", "rb");
    i=0;
    while(!feof(fpin)){       
        fread(&p[i], sizeof(Persona), 1, fpin);
        i++;
    }
    fread(p, sizeof(Persona), 3, fpin);

    fclose(fpin);

    for(i=0; i<3; i++)
        printf("%s %d\n", p[i].nome, p[i].anni);

    return(0);
}