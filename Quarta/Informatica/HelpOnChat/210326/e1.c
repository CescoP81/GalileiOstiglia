/* Chiarimento dubbi sui file 
    Operazioni di:
    - scrittura / creazione file.
    - lettura.
    - aggiunta.
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct libro{
    char titolo[30];
    float prezzo;
    int pagine;
}Libro;

void salvaLibroSuFile(Libro _l, char _nomefile[]); // salva una struttura libro su file.
void caricaLibriDaFile(char _nomefile[]); // visualizza il contenuto del file.
void cercaTitoloSuFile(char _nomefile[], char _titolo[]); // ricerca sul file un libro con il titolo specificato.
void backupLibreria(char _nomefile[], char _bkpfile[]); // esegue una copia del contenuto dal primo file al secondo file.

int main(){
    Libro lib; // singola variabile di tipo libro.

    strcpy(lib.titolo, "Oggi come domani");
    lib.prezzo = 12.99;
    lib.pagine = 120;
    salvaLibroSuFile(lib, "libreria.bin");
    caricaLibriDaFile("libreria.bin");

    printf("\n\n");
    strcpy(lib.titolo, "Giorni di gloria");
    lib.prezzo = 8.50;
    lib.pagine = 85;
    salvaLibroSuFile(lib, "libreria.bin");

    printf("\n\n");
    strcpy(lib.titolo, "Pierino e il lupo");
    lib.prezzo = 20.75;
    lib.pagine = 140;
    salvaLibroSuFile(lib, "libreria.bin");

    caricaLibriDaFile("libreria.bin");

    printf("\n\n");
    cercaTitoloSuFile("libreria.bin", "Giorni di gloria");

    backupLibreria("libreria.bin", "libreria2.bin");
    return(0);
}

void salvaLibroSuFile(Libro _l, char _nomefile[]){
    FILE *fpout;

    // determino se il file esiste oppure no
    fpout = fopen(_nomefile, "rb");
    if(fpout != NULL){
        fclose(fpout); // chiudo il file aperto ed esistente, e lo riapro in AGGIUNTA.

        fpout = fopen(_nomefile, "ab");
        fwrite(&_l, sizeof(Libro), 1, fpout);
        fclose(fpout);
    }
    else{
        fpout = fopen(_nomefile, "wb");
        fwrite(&_l, sizeof(Libro), 1, fpout);
        fclose(fpout);
    }
}

void caricaLibriDaFile(char _nomefile[]){
    FILE *fpin;
    Libro tmp;

    fpin = fopen(_nomefile, "rb");
        while(fread(&tmp, sizeof(Libro), 1, fpin)){
            printf("%s %.2f %d\n", tmp.titolo, tmp.prezzo, tmp.pagine);
        }
    fclose(fpin);
}

void cercaTitoloSuFile(char _nomefile[], char _titolo[]){
    FILE *fpin;
    Libro tmp;
    int trovato;

    fpin = fopen(_nomefile, "rb");
        trovato = 0;
        while(fread(&tmp, sizeof(Libro), 1, fpin)){
            if(strcmp(tmp.titolo, _titolo) == 0){
                printf("Trovato: %s %.2f %d", tmp.titolo, tmp.prezzo, tmp.pagine);
                trovato = 1;
            }
        }
    fclose(fpin);

    if(trovato == 0){ // if(!trovato)
        printf("Nessun libro con il titolo '%s' trovato", _titolo);
    }
}

void backupLibreria(char _nomefile[], char _bkpfile[]){
    FILE *fpin;
    FILE *fpout;
    Libro tmp;
    int cnt;

    fpin = fopen(_nomefile, "rb");
    fpout = fopen(_bkpfile, "wb");
    cnt = 0;
    while(fread(&tmp, sizeof(Libro), 1, fpin)){
        cnt++;
        fwrite(&tmp, sizeof(Libro), 1, fpout);
    }
    fclose(fpin);
    fclose(fpout);

    printf("\n\nBackup Creato, %d libri salvati.", cnt);
}