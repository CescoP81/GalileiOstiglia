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
/**
 * Aggiunge un contatto al file di elenco.
 * @param char[] Nome del file da utilizzare come elenco.
 * @param Contatto Struttura contenente i dati da scrivere nel file.
 */
void addContact(char filename[], Contatto c);
/**
 * Visualizza i contatti presenti nel file di elenco
 * @param char[] Nome del file da utilizzare come elenco.
 */
void showContacts(char filename[]);
/**
 * Ricerca contatti basandosi su un anno passato come parametro.
 * @param char[] Nome del file da utilizzare come elenco.
 * @param int Anno su cui basare la ricerca dei contatti.
 * @return Numero di contatti trovati nell'elenco con l'anno specificato.
 */
int searchByYear(char filename[], int _year);

int main(){
    Contatto c1;
    int scelta;
    int anno;
    int trovati;

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
                scanf("%d", &(c1.annoNascita));

                addContact("elenco.dat", c1);
                break;
            }
            case 2:{
                printf("\n\n-- ELENCO CONTATTI --\n");
                showContacts("elenco.dat");
                printf(" ------\n\n");
                break;
            }
            case 3:{
                printf("Inserisci anno di ricerca: ");
                scanf("%d", &anno);
                fflush(stdin);

                trovati = searchByYear("elenco.dat", anno);
                if(trovati){
                    printf("Risultati trovati: %d contatti.\n", trovati);
                }
                else
                    printf("Nessun contatto trovato.\n");
                
                    printf(" ------\n\n");
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

void addContact(char filename[], Contatto c){
    FILE *fpOut;
    fpOut = fopen(filename, "ab");
    fwrite(&c, sizeof(Contatto), 1, fpOut);
    fclose(fpOut);
}

void showContacts(char filename[]){
    FILE *fpIn;
    Contatto tmp;
    fpIn = fopen(filename, "rb");
    fread(&tmp, sizeof(Contatto), 1, fpIn);
    while(!feof(fpIn)){
        printf("%s %s %d\n", tmp.cognome, tmp.nome, tmp.annoNascita);
        fread(&tmp, sizeof(Contatto), 1, fpIn);
    }
    fclose(fpIn);
}

int searchByYear(char filename[], int _year){
    FILE *fpIn;
    Contatto tmp;
    int trovato = 0;

    fpIn = fopen(filename, "rb");
    fread(&tmp, sizeof(Contatto), 1, fpIn);
    while(!feof(fpIn)){
        if(tmp.annoNascita == _year){
            printf("%s %s %d\n", tmp.cognome, tmp.nome, tmp.annoNascita);
            trovato++;
        }
        fread(&tmp, sizeof(Contatto), 1, fpIn);
    }
    fclose(fpIn);
    return(trovato);
}