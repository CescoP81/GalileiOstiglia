/*
    Applicazione sviluppata in C per la catalogazione di una collezione privata di Dischi.
    Ogni disco è identificato dalle seguenti informazioni:
    - Artista -> Cognome e Nome
    - Titolo
    - Anno
    - Giri -> 45 o 33
    L'applicazione deve permettere le seguenti funzionalità utilizzando come archivio il file binario
    'discografia.dat':
    - [ ] Aggiunta di un nuovo Disco alla collezione.
    - [ ] Visualizzazione dei Disco della collezione.
    - [ ] Ricerca di un Disco basata su Cognome Artista.
    - [ ] Ricerca di un Disco basata su Anno o intervallo anni.
    - [ ] Modifica dei dati di un Disco.
    - [ ] Cancellazione di un Disco dall'elenco discografico.

    NB: il MAIN PROGRAM prevede un menu, uno switch case e la chiamata di una FUNZIONE
    per ogni punto da sviluppare.
*/
#include <stdlib.h>
#include <stdio.h>
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

// MAIN PROGRAM
int main(){
    int scelta;
    Disco* d;
    
    d = malloc(sizeof(Disco));
    do{
        scelta = mainMenu();
        switch(scelta){
            case 1:{
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
            case 5:{
                break;
            }
            case 6:{
                break;
            }
            case 0:{
                printf("Programma Terminato -> USCITA.");
                break;
            }
        }
        system("PAUSE");
    }while(scelta != 0);
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
        printf("4-> Ricerca per anno");
        printf("5-> Modifica dati disco\n");
        printf("6-> Cancellazione disco\n");
        printf("0 -> USCITA\n");
        printf("Scelta: ");
        scanf("%d", &s);
    }while(s<0 || s>6);
    return(s);
}