/*
    v1
    Gino 18
    Alberto 23
    Rosa 56

    v2
    Luca 45
    Anna 45
    Rosa 56

    v3
    Gino
    Alberto
    Rosa
    Luca
    Anna
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 3

typedef struct{
    char c[15];
    int a;
}Persona;

void funzione(int [], int);

int main(){
    Persona* v1;
    Persona* v2;
    Persona* v3;
    int i, cnt, trovato;

    v1 = (Persona*) malloc(DIM * sizeof(Persona));
    v2 = (Persona*) malloc(DIM * sizeof(Persona));
    v3 = (Persona*) malloc(2* DIM * sizeof(Persona));

    funzione
}