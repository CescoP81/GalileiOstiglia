#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char titolo[30];
    char autore[30];
    int nrPagina;
    float prezzo;
}Libro;
// == prototipi funzioni ==
/**
 * Inserisci un nuovo libro passato come parametro nel file libreria.dat
 * @param Libro Struttura libro da inserire.
 * @param char[] Stringa con il nome file della libreria .dat
*/
void addNewBook(Libro, char[]);
/** Stampa il contenuto del file di libreria.
 *  @param char[] Nome file della libreria .dat
 * 
*/
void printLibreria(char[]);
/**
 * Esporta l'intera libreria in un unico file CSV.
 * @param char[] Stringa nome file della libreria.
 * @param char[] Stringa nome file esportato in csv.
*/
void exportToCsv(char[], char[]);
void exportSingleLetterCSV(char[], char[]);


// === MAIN PROGRAM ==
int main(){
    int scelta;     // variabile per la scelta utente nel menu.
    Libro l;        // struttura per memorizzare i dati in input da tastiera o da file.
    FILE *fpout;    // puntatore a file in scrittura.
    FILE *fpin;     // puntatore a file in lettura.
    do{
        printf("-- MENU --\n");
        printf("1. Inserisci nuovo libro.\n");
        printf("2. Stampa libreria\n");
        printf("3. Esporta in formato CSV\n");
        printf("4. Esporta singoli file cvs (un file per ogni lettera alfabeto)\n");
        printf("0. USCITA\n");
        printf("scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:{
                // richiedo i dati del libro.
                printf("Titolo: ");
                scanf("%s", l.titolo);
                printf("Autore: ");
                scanf("%s", l.autore);
                printf("Numero Pagine: ");
                scanf("%d", &l.nrPagina);
                printf("Prezzo: ");
                scanf("%s", &l.prezzo);
                fflush(stdin);
                
                addNewBook(l, "libreria.dat");
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
        }

    }while(scelta != 0);
    return(0);
}
// == Sviluppo funzioni ==
void addNewBook(Libro _l, char _filename[]){
    FILE *fpout;    // puntatore a file in scrittura.
    fpout = fopen(_filename, "a+b");
    fwrite(&_l, sizeof(Libro), 1, fpout);
    fclose(fpout);
}