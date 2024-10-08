/*
    Applicazione sviluppata in C per la catalogazione di una collezione privata di Dischi.
    Ogni disco è identificato dalle seguenti informazioni:
    - Artista -> Cognome e Nome
    - Titolo
    - Anno
    - Giri -> 45 o 33
    L'applicazione deve permettere le seguenti funzionalità utilizzando come archivio il file binario
    'discografia.dat':
    - [x] Aggiunta di un nuovo Disco alla collezione.
    - [x] Visualizzazione dei Disco della collezione.
    - [x] Ricerca di un Disco basata su Cognome Artista.
    - [x] Ricerca di un Disco basata su Anno o intervallo anni.
    - [x] Modifica dei dati di un Disco.
    - [x] Cancellazione di un Disco dall'elenco discografico.

    NB: il MAIN PROGRAM prevede un menu, uno switch case e la chiamata di una FUNZIONE
    per ogni punto da sviluppare.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// struttura
typedef struct Disco{
    char cognome[20];
    char nome[20];
    char titolo[30]; // acquisire con gets
    int anno;
    int giri;   // può valere solo 33 o 45 (input con controllo)
}Disco;

// Dichiarazione dei prototipi delle funzioni con relativi commenti -> abstract e parametri.
/**
 * Visualizza il menu di navigazione e restituisce la scelta effettuata dall'utente.
 * 1-> Aggiunta disco.
 * 2-> Lista dischi.
 * 3-> Ricerca cognome.
 * 4-> Ricerca per anno.
 * 5-> Modifica dati disco.
 * 6-> Cancellazione disco.
 * 0 -> USCITA.
 * scelta: _
 * @return Valore intero della scelta.
*/
int mainMenu();

void insertNewDisco(Disco*, char*);
void listAllDisco(Disco*, char*);
void searchByCognome(Disco*, char*, char*);
void deleteDisco(Disco*, char*);
void searchByYear(int, int, Disco*, char*);
void updateDisco(Disco*, char*);

// MAIN PROGRAM
int main(){
    int scelta;
    Disco* d;
    FILE *fpout;    //utilizzo per scrivere
    FILE *fpin;     //utilizzo per leggere
    char *cognomeRicerca;
    int annoIniziale, annoFinale;
    
    d = malloc(sizeof(Disco));
    do{
        scelta = mainMenu();
        switch(scelta){
            case 1:{
                // inserimento informazioni del disco
                insertNewDisco(d, "discografia.dat");
                break;
            }
            case 2:{
                // lista dei dischi -> apro il file in lettura e leggo tutti i titolo.
                listAllDisco(d, "discografia.dat");
                break;
            }
            case 3:{
                printf("Cognome da ricercare: ");
                scanf("%s", cognomeRicerca);
                fflush(stdin);
                searchByCognome(d, "discografia.dat", cognomeRicerca);
                break;
            }
            case 4:{
                printf("Ricerca per Anno o Intervallo\n");
                printf("Inserisci Anno iniziale: ");
                scanf("%d", &annoIniziale);
                fflush(stdin);
                printf("Inserisci Anno finale oppure 0: ");
                scanf("%d", &annoFinale);
                fflush(stdin);
                searchByYear(annoIniziale, annoFinale, d, "discografia.dat");
                break;
            }
            case 5:{
                updateDisco(d, "discografia.dat");
                break;
            }
            case 6:{
                printf("Cancellazione di un disco\n");
                deleteDisco(d, "discografia.dat");
                break;
            }
            case 0:{
                printf("Programma Terminato -> USCITA.");
                break;
            }
        }
        system("PAUSE");
    }while(scelta != 0);

    // libero la memoria allocata.
    free(d);
    return(0);
}

// Definizione delle funzioni.
int mainMenu(){
    int s;
    do{
        system("CLS");
        printf("-- MENU --\n");
        printf("1-> Aggiunta disco\n");
        printf("2-> Lista dischi\n");
        printf("3-> Ricerca cognome\n");
        printf("4-> Ricerca per anno\n");
        printf("5-> Modifica dati disco\n");
        printf("6-> Cancellazione disco\n");
        printf("0 -> USCITA\n");
        printf("Scelta: ");
        scanf("%d", &s);
    }while(s<0 || s>6);
    return(s);
}

void insertNewDisco(Disco *_d, char *_filename){
    FILE *fpout;
    
    printf("Cognome Artista: ");
    scanf("%s", _d->cognome);
    fflush(stdin);
    printf("Nome Artista: ");
    scanf("%s", _d->nome);
    fflush(stdin);
    printf("Titolo album: ");
    gets(_d->titolo);
    fflush(stdin);
    printf("Giri: ");
    scanf("%d", &(_d->giri));
    fflush(stdin);
    printf("Anno: ");
    scanf("%d", &(_d->anno));
    fflush(stdin);
                
    fpout = fopen(_filename, "ab");
    fwrite(_d, sizeof(Disco), 1, fpout);
    fclose(fpout);
}

void listAllDisco(Disco *_d, char *_filename){
    FILE *fpin;
    int cnt;
    fpin = fopen(_filename,"rb");
    cnt = 1;
    while(fread(_d, sizeof(Disco), 1, fpin)){
        printf("%d -> %s %s con: '%s' - %d giri - Anno: %d\n", cnt, _d->cognome, _d->nome, _d->titolo, _d->giri, _d->anno);
        cnt = cnt + 1;
    }
    fclose(fpin);
}

void searchByCognome(Disco *_d, char *_filename, char *_cognome){
    FILE *fpin;
    int cnt;
    fpin = fopen(_filename,"rb");
    cnt = 0;
    while(fread(_d, sizeof(Disco), 1, fpin)){
        if(strcmp(_d->cognome, _cognome) == 0){
            cnt = cnt + 1;
            printf("%d -> %s %s con: '%s' - %d giri - Anno: %d\n", cnt, _d->cognome, _d->nome, _d->titolo, _d->giri, _d->anno);
        }
    }
    printf("Risultati totali trovati: %d\n", cnt);
    fclose(fpin);
}

void deleteDisco(Disco *_d, char *_filename){
    FILE *fpin, *fpout;
    int discoScelto;
    int cnt;

    // visualizzo la lista dischi presenti nel file, sfrutto la funzione già sviluppata.
    listAllDisco(_d, _filename);
    printf("Nr. disco da cancellare: ");
    scanf("%d", &discoScelto);
    fflush(stdin);

    // copio sul file temporaneo tmp.dat tutti i disci MENO quello scelto.
    fpin = fopen(_filename, "rb");
    fpout = fopen("tmp.dat", "wb");
    cnt = 0;
    while(fread(_d, sizeof(Disco), 1, fpin)){
        cnt = cnt + 1;
        if(cnt != discoScelto)
            fwrite(_d, sizeof(Disco), 1, fpout);
    }
    fclose(fpin);
    fclose(fpout);

    // ricopio tmp su discografia.
    fpin = fopen("tmp.dat", "rb");
    fpout = fopen(_filename, "wb");
    while(fread(_d, sizeof(Disco), 1, fpin)){
        fwrite(_d, sizeof(Disco), 1, fpout);
    }
    fclose(fpin);
    fclose(fpout);
}

void searchByYear(int _start, int _end, Disco *_d, char *_filename){
    FILE *fpin;
    fpin = fopen(_filename, "rb");

    // ricerco per intervallo, devono essere specificati due anni e il vincolo
    // è che start deve essere minore o uguale a end.
    if(_start != 0 && _end!=0 && _start<=_end){
        while(fread(_d, sizeof(Disco), 1, fpin)){
            if(_d->anno >= _start && _d->anno<=_end){
                printf("%s %s %s %d %d\n", _d->cognome, _d->nome, _d->titolo, _d->giri, _d->anno);
            }
        }
    }
    else{
        // se viene specificato solo l'anno iniziale, cerco per anno specifico.
        if(_start != 0 && _end==0){
            while(fread(_d, sizeof(Disco), 1, fpin)){
                if(_d->anno == _start){
                    printf("%s %s %s %d %d\n", _d->cognome, _d->nome, _d->titolo, _d->giri, _d->anno);
                }
            }
        }
        else{
            printf("Specifica anni non valida.");
        }
    }
    fclose(fpin);
}

void updateDisco(Disco *_d, char *_filename){
    FILE *fpin, *fpout;
    int nrDisco;
    int cnt;
    printf("Seleziona il disco da modificare per numero:\n");
    listAllDisco(_d, _filename);
    printf("\nDisco numero: ");
    scanf("%d", &nrDisco);
    fflush(stdin);

    fpin = fopen(_filename, "rb");
    fpout = fopen("tmp.dat", "wb");
    cnt = 0;
    while(fread(_d, sizeof(Disco), 1, fpin)){
        cnt++;
        if(cnt != nrDisco){
            fwrite(_d, sizeof(Disco), 1, fpout);
        }
        else{
            printf("== Nuovi dati del disco ==\n");
            printf("Cognome Artista: ");
            scanf("%s", _d->cognome);
            fflush(stdin);
            printf("Nome Artista: ");
            scanf("%s", _d->nome);
            fflush(stdin);
            printf("Titolo album: ");
            gets(_d->titolo);
            fflush(stdin);
            printf("Giri: ");
            scanf("%d", &(_d->giri));
            fflush(stdin);
            printf("Anno: ");
            scanf("%d", &(_d->anno));
            fflush(stdin);
            // scrivo i nuovi dati nel file temporaneo.
            fwrite(_d, sizeof(Disco), 1, fpout);
        }
    }
    // chiudo entrambi i file, nel foput cioè temp.dat ho i vecchi dati e la modifica fatta,
    // devo ricopiarlo su discrografia.dat
    fclose(fpin);
    fclose(fpout);

    // riapro i due file e ricopio il contenuto di temp dentro a discografia.
    // ricopio tmp su discografia.
    fpin = fopen("tmp.dat", "rb");
    fpout = fopen(_filename, "wb");
    while(fread(_d, sizeof(Disco), 1, fpin)){
        fwrite(_d, sizeof(Disco), 1, fpout);
    }
    fclose(fpin);
    fclose(fpout);
}