/*
Realizzare un algoritmo che gestendo l'input di ipotetici studenti (cognome, nome, anno di nascita)
ed un file chiamato classe.bin inserisce gli studenti, li visualizza e permette di ricercare uno studente.

L'inserimento degli studenti dovrebbe essere realizzato in modo tale da avere sempre un file con nominativi
ordinati per cognome.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cognome[20];
    char nome[20];
    char anno[5];
}Studente;

void initStudente(Studente*);
void writeOrderedFile(Studente);
void vediListaFile();


int main(){
    Studente s;     // struttura per le fasi di input da operatore.
    initStudente(&s);
    writeOrderedFile(s);
    vediListaFile();
    return(0);
}

void initStudente(Studente *_s){
    printf("Cognome: ");
    scanf("%s", (*_s).cognome);
    fflush(stdin);
    printf("Nome: ");
    scanf("%s", (*_s).nome);
    fflush(stdin);
    printf("Anno: ");
    scanf("%s", (*_s).anno);
}

void writeOrderedFile(Studente _s){
    Studente tmpIn;
    FILE *fpIn, *fpOut;
    int n, trovato;

    fpIn = fopen("classe.bin", "rb");
    fpOut = fopen("tmp.bin", "wb");

    if(fpIn != NULL){
        trovato = 0;
        //printf("entro1\n");
        while(!feof(fpIn)){
            n = fread(&tmpIn, sizeof(Studente), 1, fpIn);
            if(n > 0){
                if(trovato){
                    fwrite(&tmpIn, sizeof(Studente), 1, fpOut);
                }
                else{
                    if(strcmp(tmpIn.cognome, _s.cognome) < 0){
                        //printf("Scrivo letto da file...");
                        fwrite(&tmpIn, sizeof(Studente), 1, fpOut);
                    }
                    else{
                        printf("Entro 2...");
                        fwrite(&_s, sizeof(Studente), 1, fpOut);
                        fwrite(&tmpIn, sizeof(Studente), 1, fpOut);
                        trovato = 1;
                    }
                }
            }
            if(feof(fpIn) && !trovato)
                fwrite(&_s, sizeof(Studente), 1, fpOut);
        }
        fclose(fpIn);
        fclose(fpOut);
        remove("classe.bin");
        rename("tmp.bin", "classe.bin");
    }
    else{
        fclose(fpIn);
        fclose(fpOut);

        fpOut = fopen("classe.bin", "w");
        fwrite(&_s, sizeof(Studente), 1, fpOut);
        fclose(fpOut);
    }
}

void vediListaFile(){
    Studente x;
    int n;
    FILE *fpIn;

    fpIn = fopen("classe.bin", "rb");
    while(!feof(fpIn)){
        n = fread(&x, sizeof(Studente), 1, fpIn);
        if(n > 0){
            printf("%s %s %s\n", x.cognome, x.nome, x.anno);
        }
    }
    fclose(fpIn);
}