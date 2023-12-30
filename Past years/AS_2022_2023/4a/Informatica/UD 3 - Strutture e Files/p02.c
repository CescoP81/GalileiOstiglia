#include <stdio.h>
#include <stdlib.h>
#define DIM_PRODOTTI 10
//#define VALUTA 128

typedef struct{
    char nome[20];
    int quantita;
    float prezzoUnitario;
}Prodotto;
// ------------------------------
/**
 * Visualizza il menu delle opzioni offerte dal programma.
 * @param int Contatore degli slot del vettore.
 * @param int Dimensione massima del vettore (celle utilizzabili).
*/
int menuScelta(int, int);
// ------------------------------
int main(){
    int scelta;
    int cntProdotti;
    Prodotto elenco[DIM_PRODOTTI];
    /*do{
        scelta = menuScelta(cntProdotti, DIM_PRODOTTI);
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
            case 0:{
                printf("Programma Terminato");
                break;
            }
            default:{
                printf("Scelta non valida.");
                break;
            }
        }
    }while(scelta != 0);*/
    return(0);
}

// ------------------------------
int menuScelta(int _cnt, int _dim){
    int sc;
    do{
        printf("Slot occupati %d su %d\n", _cnt, _dim);
        printf("----------------------\n");
        printf("1 -> Inserisci prodotto.\n");
        printf("2 -> Visualizza prodotti\n");
        printf("3 -> Calcola totale spesa\n");
        printf("4 -> Cancella prodotto\n");
        printf("0 -> USCITA\n");
        printf("Scelta: ");
        scanf("%d", &sc);
        fflush(stdin);
    }while(sc<0 || sc>4);
    return(sc);
}