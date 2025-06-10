#include <stdlib.h>
#include <stdio.h>
#include <time.h>


const int N = 21;

typedef struct Nodo{
    int valore;
    struct Nodo* next;
}Nodo;


/**
 * Genera una lista di n elementi con valori interi compresi tra 1 e 25
 * @param int numero di nodi da creare
 * @return puntatore alla testa della lista generata
 */
Nodo* generaLista(int n);

/**
 * Visualizza la lista
 * @param Nodo* Riferimento alla testa della lista
 */
void vediLista(Nodo *_testa);

/**
 * Calcola e restituisce la media dei valori presenti nella lista
 * @param Nodo* Riferimento alla testa della lista
 * @return media dei valori
 */
int mediaLista(Nodo *_testa);

/**
 * Salva tutti i valori presenti nella lista in un file
 * @param Nodo* Riferimento alla testa della lista
 * @param char[] Nome del file su cui salvare i dati
 */
void salvaSuFile(Nodo *_testa, char _nome[]);

/**
 * Carica i dati da un file su una lista. Genera una nuova lista cancellando quella preesistente, se esiste.
 * @param char[] Nome del fil e da cui caricare i dati
 * @return Puntatore alla testa della lista
 */
Nodo caricaDaFile(char _nome[]);

int main(){

    srand(time(NULL));

    char x = '1';
    int f = 0;
    char trash = ' ';
    char fileName[N];
    Nodo *point = 0;
    
    while(x != '0'){
        printf("1 - GENERA: Crea una lista in cui inserire valori casuali tra 1 e 25\n");
        printf("2 - VISUALIZZA: Mostra la lista a schermo\n");
        printf("3 - MEDIA: Calcola la media dei valori e restituiscila al main\n");
        printf("4 - SAVE: Salva i dati della lista su un file\n");
        printf("5 - OPEN: Crea una nuova lista caricando i dati da un file\n");
        printf("0 - Esci\n");
        scanf("%c", &x);
        scanf("%c", &trash);

        switch(x){
            case '1':
                printf("Inserisci la dimensione della lista: ");
                scanf("%d", &f);
                scanf("%c", &trash);
                printf("\n");
                point = generaLista(f);
            break;
            case '2':
                printf("Lista completa:\n");
                vediLista(point);
            break;
            case '3':
                //printf("La media di tutti i valori presenti nella lista e' %d\n", mediaLista(point));
            break;
            case '4':
                printf("Inserisci il nome del file su cui caricare i dati: ");
                gets(fileName);
                //salvaSuFile(point, fileName);
            break;
            case '5':
                printf("Inserisci il nome del file da cui caricare i dati: ");
                gets(fileName);
                //caricaDaFile(fileName);
            break;
            case '0':
                printf("Shutting down...\n");
            break;
        }
        printf("\n\n --- x = %c ---\n\n", x);
    }
    return 0;
}

/*## SVILUPPO FUNZIONI ## */

/*Nodo* generaLista(int n){
    Nodo *tmp;
    Nodo *testa;

    for(int i = 0; i < n; i++){
        tmp = malloc(sizeof(Nodo)); 
        tmp->valore = rand() % 25 + 1;
        printf("valore inserito: %d\n", tmp->valore);
        tmp->next = testa;
    }
    return testa;
}*/
Nodo* generaLista(int n){
    Nodo *tmp;
    Nodo *testa=0;
    int i;

    for(i=1; i<=n; i++){
        tmp = malloc(sizeof(Nodo));
        tmp->next = testa;
        tmp->valore = rand() % 25 + 1;
        printf("%d - ", tmp->valore); // stampa per controllo che esegua appunto N valori random, poi puoi commentarla
        testa = tmp;
    }
    return(testa);
}

void vediLista(Nodo *_testa){
    Nodo* tmp;
    // visualizzo la lista esistente con un ciclo
    tmp = _testa;                // faccio puntare TMP alla TESTA attuale della lista.
    printf("Testa: %d\n", tmp);
    while(tmp != NULL){
        printf("Addr: %d - Valore: %d - Next: %d\n", tmp, tmp->valore, tmp->next);
        tmp = tmp->next;
    }
}