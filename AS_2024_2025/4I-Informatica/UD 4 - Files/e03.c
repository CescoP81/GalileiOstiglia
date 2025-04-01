/*
Dato un file di binario, le cui righe rappresentano ciascuna i dati di una persona secondo il seguente
formato
- cognome (max 30 car)
- nome (max 30 car)
- sesso (singolo car M/F)
- anno di nascita intero
scrivi un programma che permetta di inserire ripetutamente persone ad un file generale chiamato
"contatti.dat', quando viene richiesto dall'utente, generare due file distinti maschi.dat e femmine.dat
contenente i nominativi dei rispettivi sessi.
Ogni volta i file maschi e femmine vengono generati da zero. il file contatti viene gestito in aggiunta.

Utilizzare una struct e le funzioni fread e fwrite per la gestione dei file.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char cognome[30];
    char nome[30];
    char sesso;
    int annoNascita;
}Persona;

void aggiungiPersona(char _filename[], Persona _tmp);
void vediListaContatti(char _filename[]);
void dividiMaschiFemmine(char _filename1[], char _filename2[], char _filename3[]);

int main(){
    int scelta;
    char junk;
    Persona p;

    do{
        printf("1-> Aggiungi persona\n");
        printf("2-> Suddividi maschi-femmine\n");
        printf("3-> Visualizza contatti presenti\n");
        printf("0-> USCITA\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        junk = getchar();

        switch(scelta){
            case 1:{
                printf("Cognome: ");
                scanf("%s", &(p.cognome));
                junk = getchar();
                
                printf("Nome: ");
                scanf("%s", p.nome);
                junk = getchar();

                printf("Sesso: ");
                scanf("%c", &(p.sesso));
                junk = getchar();

                printf("Anno di Nascita: ");
                scanf("%d", &(p.annoNascita));
                junk = getchar();

                //printf("%s %s %c %d\n", p.cognome, p.nome, p.sesso, p.annoNascita);
                aggiungiPersona("contatti2.dat", p);
                break;
            }
            case 2:{
                dividiMaschiFemmine("contatti2.dat", "maschi.dat", "femmine.dat");
                break;
            }
            case 3:{
                vediListaContatti("contatti2.dat");
                break;
            }
            default:{
                if(scelta != 0)
                    printf("\n-- Scelta non valida --\n");
            }
        }
    }while(scelta!=0);
    return(0);
}

void aggiungiPersona(char _filename[], Persona _tmp){
    FILE *pContatti;

    pContatti = fopen(_filename, "ab");
    fwrite(&_tmp, sizeof(Persona), 1, pContatti);
    fclose(pContatti);
}

void vediListaContatti(char _filename[]){
    FILE *pContatti;
    Persona tmp;
    printf("\n\n-- CONTATTI PRESENTI --\n");
    pContatti = fopen(_filename, "rb");
    while(fread(&tmp, sizeof(Persona), 1, pContatti) > 0){
        printf("%s %s %c %d\n", tmp.cognome, tmp.nome, tmp.sesso, tmp.annoNascita);
    }
    fclose(pContatti);
    printf("---\n\n");
}

void dividiMaschiFemmine(char _filename1[], char _filename2[], char _filename3[]){
    FILE *pContatti;
    FILE *pMaschi;
    FILE *pFemmine;
    Persona tmp;
    int cntM, cntF;

    pContatti = fopen(_filename1, "rb");
    pMaschi = fopen(_filename2, "wb");
    pFemmine = fopen(_filename3, "wb");

    cntM = 0;
    cntF = 0;
    while(fread(&tmp, sizeof(Persona), 1, pContatti) > 0){
        if(tmp.sesso == 'm' || tmp.sesso == 'M'){
            fwrite(&tmp, sizeof(Persona), 1, pMaschi);
            cntM++;
        }
        if(tmp.sesso == 'f' || tmp.sesso == 'F'){
            fwrite(&tmp, sizeof(Persona), 1, pFemmine);
            cntF++;
        }
    }
    fclose(pContatti);
    fclose(pMaschi);
    fclose(pFemmine);
    printf("\n--Maschi %d - Femmine %d--\n\n", cntM, cntF);
}