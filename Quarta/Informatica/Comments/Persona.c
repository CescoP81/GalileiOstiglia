#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cognome[20];
    int anni;
}Persona;

/* Inizializza una person con dati specifici.
@param Persona * riferimento alla struttura Persona.
@param char[] stringa del cognome.
@param int anni della persona.
*/
void setPersona(Persona *p, char c[], int a){
    strcpy(p->cognome, c);
    p->anni = a;    
}

/* Stampa a video una singola struttura persona.
@param Persona* riferimento alla struttura da stampare
*/
void stampaPersona(Persona *p){
    printf("%s %d\n", p->cognome, p->anni);
}