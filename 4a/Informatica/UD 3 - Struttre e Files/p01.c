// #############################
// # Librerie e Costanti       #
// #############################
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 20
#define MAX_ITEMS 10

// struttura definita per il programma
typedef struct{
    char nome[MAX_CHAR];
    char cognome[MAX_CHAR];
    int anno;
}Studente;

// #############################
// #        PROTOTIPI          #
// #############################
/**
 * Aggiunge uno studente al vettore di elenco
 * @param Studente[] Vettore di strutture da usare come elenco
 * @param int* Riferimento al contatore delle strutture inserite / celle vettore utilizzate
 * @param int Numero massimo di strutture utilizzabili.
*/
void addStudente(Studente[], int*, int);
/**
 * Visualizza le strutture riempite nell'elenco
 * @param Studente[] Vettore di strutture da usare come elenco.
 * @param int Numero strutture attualmente presenti in elenco / celle utilizzate del vettore.
*/
void showStudenti(Studente[], int);

// #############################
// #       MAIN PROGRAM        #
// #############################
int main(){
    Studente elenco[MAX_ITEMS];     // vettore per le strutture allocate.
    int cntStudenti;                // contatore degli studenti inseriti.

    cntStudenti = 0;                // azzero il contatore degli studenti inseriti.

    // aggiungo tre studenti con 3 chiamate alla funzuione di add
    addStudente(elenco, &cntStudenti, MAX_ITEMS);
    addStudente(elenco, &cntStudenti, MAX_ITEMS);
    addStudente(elenco, &cntStudenti, MAX_ITEMS);

    // visualizzo gli studenti inseriti chiamando la show
    showStudenti(elenco, cntStudenti);
    return(0);
}

// #############################
// #         FUNZIONI          #
// #############################
void addStudente(Studente x[], int *_cnt, int MAX_ITEM){
    if(*_cnt < MAX_ITEM){
        printf("Nome: ");
        scanf("%s", x[(*_cnt)].nome);
        fflush(stdin);
        printf("Cognome: ");
        scanf("%s", x[(*_cnt)].cognome);
        fflush(stdin);
        printf("Anno: ");
        scanf("%d", &x[(*_cnt)].anno);
        fflush(stdin);
        *_cnt = *_cnt + 1;
    }
    else{
        printf("ERROR! - No Space Available!!\n");
    }
}
void showStudenti(Studente x[], int _cnt){
    int i;
    printf("--ELENCO--\n");
    for(i=0; i<_cnt; i++){
        printf("%d %s %s %d\n", (i+1), x[i].nome, x[i].cognome, x[i].anno);
    }
}