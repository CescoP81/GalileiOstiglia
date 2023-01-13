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
/**
 * Modifica i dati di uno studente scelto per indice
 * @param Studente[] Vettore di strutture da usare come elenco.
 * @param int Indice dello studente scelto.
 * @param int Contatore studenti presenti.
 * @return int 1/0 se possibile la modifica oppure no.
*/
int modifyStudente(Studente[], int, int);
/**
 * Cancella uno studente scelto per indice
 * @param Studente[] Vettore di strutture da usare come elenco.
 * @param int Indice dello studente scelto.
 * @param int Contatore studenti presenti.
 * @return int 1/0 se possibile la modifica oppure no.
*/
int deleteStudente(Studente[], int, int*);
/**
 * Ricerca uno studente partendo dal cognome
 * @param Studente[] Vettore di strutture da usare come elenco.
 * @param char* Stringa cognome da ricercare.
 * @param int Contatore studenti presenti.
*/
void searchStudente(Studente[], char*, int);

/**
 * Funzione che compara alfabeticamente due stringhe.
 * @param char* Riferimento stringa 1
 * @param char* Riferimento stringa 2
 * @return int -1 se st1<st2; 0 se st1=st2; +1 se st1>st2
*/
int comparaStringhe(char*, char*);
// #############################
// #       MAIN PROGRAM        #
// #############################
int main(){
    Studente elenco[MAX_ITEMS];     // vettore per le strutture allocate.
    int cntStudenti;                // contatore degli studenti inseriti.
    int indexStudente;
    char *cognome="Rossi";

    cntStudenti = 0;                // azzero il contatore degli studenti inseriti.

    // aggiungo tre studenti con 3 chiamate alla funzuione di add
    addStudente(elenco, &cntStudenti, MAX_ITEMS);
    addStudente(elenco, &cntStudenti, MAX_ITEMS);
    addStudente(elenco, &cntStudenti, MAX_ITEMS);

    // Visualizzo gli studenti inseriti chiamando la show
    showStudenti(elenco, cntStudenti);

    // Modifica di uno studente
    showStudenti(elenco, cntStudenti);
    printf("Inserisci nr. studente: ");
    scanf("%d", &indexStudente, cntStudenti);
    fflush(stdin);
    if(modifyStudente(elenco, indexStudente, cntStudenti))
        printf("Aggiornamento studente avvenuto!\n");
    else
        printf("Indice non valido\n");
    showStudenti(elenco, cntStudenti); // stampa di controllo dopo la chiamata della modifica studente.
    
    // cancellazione dello studente con indice 2
    printf("\n- Cancellazione studente con indice 2 -\n");
    if(deleteStudente(elenco, 2, &cntStudenti))
        printf("Cancellazione avvenuta!");
    else
        printf("Indice non presente!\n");
    showStudenti(elenco, cntStudenti);

    printf("\n- Ricerca studente 'Rossi' -\n");
    searchStudente(elenco, cognome, cntStudenti);
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
        printf("#%d - %s %s %d\n", (i+1), x[i].nome, x[i].cognome, x[i].anno);
    }
}
int modifyStudente(Studente x[], int _indexStudente, int _cntStudenti){
    // verifico che l'indice scelto sia effettivamente utilizzato.
    if((_indexStudente > 0) && (_indexStudente < _cntStudenti)){
        printf("Nuovo nome: ");
        scanf("%s", x[_indexStudente-1].nome);
        fflush(stdin);
        printf("Nuovo cognome: ");
        scanf("%d", x[_indexStudente-1].cognome);
        fflush(stdin);
        printf("Nuovo anno: ");
        scanf("%d", &x[_indexStudente-1].anno);
        fflush(stdin);
        return(1);
    }
    else
        return(0);
}
int deleteStudente(Studente x[], int _indexStudente, int *_cntStudenti){
    int i;
    if((_indexStudente > 0) && (_indexStudente < *_cntStudenti)){
        for(i=_indexStudente-1; i<*_cntStudenti; i++){
            x[i] = x[i+1];
        }
        (*_cntStudenti)--;
        return(1);
    }
    else    
        return(0);
}
void searchStudente(Studente x[], char *_Cognome, int _cntStudenti){
    int i;
    for(i=0; i<_cntStudenti; i++){
        if(comparaStringhe(x[i].cognome, _Cognome) == 0)
            printf("%s %s %d\n", x[i].cognome, x[i].nome, x[i].anno);
    }
}

// ereditate dalle stringhe
int comparaStringhe(char *_str1, char *_str2){
    int i;
    i=0;
    while(*(_str1+i)!='\0' && *(_str2+i)!='\0'){
        if(*(_str1+i) > *(_str2+i))
            return(1);
        if(*(_str1+i) < *(_str2+i))
            return(-1);
        i++;
    }
    if(*(_str1+i)=='\0' && *(_str2+i)=='\0')
        return(0);
    else{
        if(*(_str1+i)!='\0')
            return(1);
        if(*(_str2+i)!='\0')
            return(0);
    }
}