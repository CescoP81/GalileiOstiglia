#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char cognome[20];
    int anni;
}Persona;

int main(){
    FILE *fpin;
    FILE *fpout;
    Persona p;
    int scelta;

    do{
        printf("1-> Inserimento Persona.\n");   // chiedo una persona e registro i dati sul file.
        printf("2-> Lettura persone.\n");       // leggo da file e visualizzo tutte le persone.
        printf("3-> Ricerca per cognome.\n");   // chiede un cognome e lo ricerca tra le persone del file.
        printf("0-> USCITA.\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        fflush(stdin);

        switch(scelta){
            case 1:{
                // inserimento dei dati della persona.
                printf("Nome: ");
                scanf("%s", p.nome);
                fflush(stdin);
                printf("Cognome: ");
                scanf("%s", p.cognome);
                fflush(stdin);
                printf("Anni: ");
                scanf("%d", &p.anni);
                fflush(stdin);

                fpout = fopen("rubrica.bin", "rb");         // Determino se il file esiste o meno sul disco.
                if(!fpout){
                    fpout = fopen("rubrica.bin", "wb");     // se non c'è allora lo creo e lo chiudo subito.
                    fclose(fpout);
                }
                else{
                    fclose(fpout);                          // se esiste chiudo lo stream.
                }

                fpout = fopen("rubrica.bin","ab");          // apro il file in AGGIUNTA
                fwrite(&p, sizeof(Persona), 1, fpout);      // scrivo la persona inserita
                fclose(fpout);                              // chiudo il file.
                break;
            }
            case 2:{
                printf("Rubrica presente:\n");
                fpin = fopen("rubrica.bin","rb");           // apro il file in lettura.
                fread(&p, sizeof(Persona), 1, fpin);        // leggo una struttura.
                while(!feof(fpin)){
                    printf("%s \t %s \t %d\n", p.nome, p.cognome, p.anni);
                    fread(&p, sizeof(Persona), 1, fpin);
                }
                fclose(fpin);
                break;
            }
            case 3:{
                char csrc[20];
                int trovato;
                printf("Inserisci cognome: ");
                scanf("%s", csrc);
                fflush(stdin);

                trovato = 0;
                fpin = fopen("rubrica.bin", "rb");
                fread(&p, sizeof(Persona), 1, fpin);
                while(!feof(fpin)){
                    if(strcmp(csrc, p.cognome) == 0){
                        printf("%s %s %d\n", p.nome, p.cognome, p.anni);
                        trovato = 1;
                    }
                    fread(&p, sizeof(Persona), 1, fpin);
                }
                fclose(fpin);
                if(!trovato)    printf("Nessuna persona trovata con cognome %s.\n\n", csrc);
                break;
            }
        }
    }while(scelta != 0);
    return(0);
}