/*
    Esempio di utilizzo di una struttura, utilizzando l'operatore typedef possiamo definire un nuovo
    tipo di variabile ed utilizzarlo al pari di altri tipi come int, float, char.

    L'esempio permette la creazione di una variabile p1 di tipo struttura, quindi l'accesso ai campi della
    struttura avviene con l'operatore . (punto)

    La seconda parte invece alloca (funzione di malloc) una struttura in memoria e ne assegna l'indirizzo al 
    puntatore *p2. L'accesso ai campi della struttura avviene con il simbolo '->' (meno maggiore).

    Si suggerisce l'utilizzo della seconda forma dichiarativa, cioè con puntatore, che poi si ricollegherà 
    all'unità didattica delle Liste.
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char nome[20];
    char cognome[20];
    int eta;
}Persona;

int main(){
    Persona p1;
    Persona* p2;

    // inserimento di Persona 1 con p1 dichiarato come variabile strutturata.
    printf("Inserisci nome: ");
    scanf("%s", &(p1.nome));
    fflush(stdin);
    printf("Inserisci cognome: ");
    scanf("%s", &(p1.cognome));
    fflush(stdin);
    printf("Inserisci eta': ");
    scanf("%d", &(p1.eta));
    fflush(stdin);

    printf("Dati persona 1: %s %s %d\n\n", p1.nome, p1.cognome, p1.eta);
    
    //---------------

    // inserimento di Persona 2 con p2 dichiarato come puntatore a struttura.
    p2 = malloc(sizeof(Persona));
    printf("Inserisci nome: ");
    scanf("%s", &(p2->nome));
    fflush(stdin);
    printf("Inserisci cognome: ");
    scanf("%s", &(p2->cognome));
    fflush(stdin);
    printf("Inserisci eta': ");
    scanf("%d", &(p2->eta));
    fflush(stdin);

    printf("Dati persona 2: %s %s %d\n\n", p2->nome, p2->cognome, p2->eta);

    return(0);
}