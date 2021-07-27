/*
    Realizzare un programma che permetta di:
    1. Inserire un un nuovo libro nell'elenco (1 libro per volta e MAX 20 LIBRI).
    2. Ricercare un libro per titolo.
    3. Ricercare un libro per fascia di prezzo p_min<=x<=p_max (es. 5.50 <-> 10.99).
    0. USCITA
*/
#include <stdio.h>
#include <conio.h>
#define DIM 20

typedef struct{
    char titolo[40];
    char autore[40];
    int n_pagine;
    float prezzo;    
}Libro;

int vediElenco(Libro[], int);
int ricercaTtitolo(Libro[], char[], int);

int main(){
    Libro l;
    Libro elenco[DIM];

    do{
        ...menu...
        switch(){
            case 1:{
                // inserimento nuovo libro.
                if(se posto disponibile)
                    inserisco Libro.
                else
                    messaggio posto finito.
                
            }
        }
    }while()
}

int ricercaTtitolo(Libro el[], char t[], int dimensione){
    strcmp(el[i].titolo, t) == 0 //-> titoli uguali
}