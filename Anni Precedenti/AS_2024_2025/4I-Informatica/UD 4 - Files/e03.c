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

UPDATE:
- Aggiungere opzione di modifica di un contatto nell'elenco generale. 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char cognome[30];
    char nome[30];
    char sesso;
    int annoNascita;
}Persona;
/**
 * Aggiunge una struttura al file generale di elenco.
 * @param char[] Nome del file da utlizzare come elenco generale. 
 * @param Persona Struttura contenente le informazioni da scrivere sul file.
 */
void aggiungiPersona(char _filename[], Persona _tmp);
/**
 * Visualizza la lista dei nominativi presenti nel file generale. 
 * @param char[] Nome del file da utlizzare come elenco generale.
 */
void vediListaContatti(char _filename[]);

int vediContaContatti(char _filename[]);
/**
 * Funzione che copia i nominativi in due file distinti in base al sesso. ù
 * @param char[] Nome del file da utlizzare come elenco generale.
 * @param char[] Nome del file da utlizzare come elenco MASCHI.
 * @param char[] Nome del file da utlizzare come elenco FEMMINE.
 */
void dividiMaschiFemmine(char _filename1[], char _filename2[], char _filename3[]);

int cancellaContatto(char _filename[], int _index);

int main(){
    int scelta;
    char junk;
    Persona p;
    int cnt;
    int deleteIndex;

    do{
        printf("1-> Aggiungi persona.\n");
        printf("2-> Suddividi maschi-femmine.\n");
        printf("3-> Visualizza contatti presenti.\n");
        printf("4-> Cancella contatto.\n");
        printf("0-> USCITA.\n");
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
                //vediListaContatti("contatti2.dat");
                cnt = vediContaContatti("contatti2.dat");
                printf("Contatti presenti: %d\n\n", cnt);
                break;
            }
            case 4:{
                cnt = vediContaContatti("contatti2.dat");
                printf("Nr. contatto da cancellare: ");
                scanf("%d", &deleteIndex);
                junk = getchar();
                if(deleteIndex>0 && deleteIndex<=cnt){
                    cancellaContatto("contatti2.dat", deleteIndex);
                    printf("-- Contatto cancellato e File aggiornato --\n");
                    vediContaContatti("contatti2.dat");
                    printf("\n");
                }
                else
                    printf("Indice del contatto non trovato.\n\n");
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

int vediContaContatti(char _filename[]){
    FILE *pContatti;
    Persona tmp;
    int cntContatti;
    printf("\n\n-- CONTATTI PRESENTI --\n");
    pContatti = fopen(_filename, "rb");
    cntContatti = 0;
    while(fread(&tmp, sizeof(Persona), 1, pContatti) > 0){
        cntContatti++;
        printf("%d->\t%s %s %c %d\n", cntContatti, tmp.cognome, tmp.nome, tmp.sesso, tmp.annoNascita);
    }
    fclose(pContatti);
    printf("---\n");
    return(cntContatti);
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

int cancellaContatto(char _filename[], int _index){
    FILE *fpIn;
    FILE *fpOut;
    int cnt;
    Persona tmp;

    cnt = 0;
    fpIn = fopen(_filename, "rb");
    fpOut = fopen("temp.dat", "wb");

    while(fread(&tmp, sizeof(Persona), 1, fpIn) > 0){
        cnt++;
        if(cnt != _index)
            fwrite(&tmp, sizeof(Persona), 1, fpOut);
    }
    fclose(fpIn);
    fclose(fpOut);

    fpIn = fopen("temp.dat", "r");
    fpOut = fopen(_filename, "wb");
    while(fread(&tmp, sizeof(Persona), 1, fpIn) > 0){
        fwrite(&tmp, sizeof(Persona), 1, fpOut);
    }
    fclose(fpIn);
    fclose(fpOut);
}