/**
 * Realizzare sulla base della struttura dell'esercizio 1 un piccolo programma che gestendo un file
 * di contatti permetta di realizzare le seguenti operazioni
 * 1. Aggiunta di un nuovo nominativo (senza controllo di esistenza)[nomeFile, struttura da scrivere].
 * 2. Visualizzazione di i contatti presenti nel file. [nomeFile]
 * 3. Ricerca di contatti per anno di nascita (mostra tutti quelli dell'anno indicato). [nomeFile, annoDiRicerca]
 * 
 * Il programma è da svilupparsi con uno switch-case, per ogni case viene richiamata una funzione. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char cognome[20];
    int annoNascita;
}Contatto;

// == prototipi ==
void addNominativo(char filename[], Contatto c);

int main(){
    Contatto c1;
    int scelta;

    do{
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza contatti\n");
        printf("3. Ricerca per anno di nascita\n");
        printf("0. USCITA\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        fflush(stdin);

        switch(scelta){
            case 1:{
                printf("Cognome: ");
                scanf("%s", c1.cognome);
                fflush(stdin);
                printf("Nome: ");
                scanf("%s", c1.nome);
                fflush(stdin);
                printf("Anno di nascita: ");
                scanf("%d", c1.annoNascita);

                addNominativo("elenco.dat", c1);
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            default:{
                printf("Scelta non valida!\n\n");
                break;
            }
        }

    }while(scelta != 0);

    return(0);
}

void addNominativo(char filename[], Contatto c){
    FILE *fpOut;
    fpOut = fopen(filename, "ab");
    fwrite(&c, sizeof(Contatto), 1, fpOut);
    fclose(fpOut);
}