#include <stdio.h>
#include <string.h>
#include "lib.h"

void inputShape(Shape* _x){
    int base;
    int altezza;
    char junk;

    printf("Inserisci una base: ");
    scanf("%d", &base);
    junk = getchar();

    printf("Inserisci un'altezza: ");
    scanf("%d", &altezza);
    junk = getchar();

    _x->b = base;         // (*_x).b = base;
    _x->h = altezza;      // (*_x).h = altezza;
}

void printShape(Shape _x){
    printf("Base: %d, Altezza: %d\n\n", _x.b, _x.h);
}