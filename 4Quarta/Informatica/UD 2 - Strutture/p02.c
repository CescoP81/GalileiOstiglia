/*
   realizzare un programma che richiede 3 strutture frazione costituite da {int numeratore; int denominatore}.
   realizzare e funzioni per:
   - inizializzare le 3 frazioni.
   - stampare le tre frazioni.
   - calcolare il valore decimale di una frazione.
   - sommare due frazioni tra loro.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int numeratore;
   int denominatore;
}Frazione;

void initFrazione(Frazione**, int, int);
void printFrazione(Frazione*);
float getFrazioneDecimale(Frazione*);

int main(){
   Frazione *f1;
   initFrazione(&f1, 5, 3);
   printFrazione(f1);
   printf("\nValore decimale: %.2f\n", getFrazioneDecimale(f1));
   return(0);
}

void initFrazione(Frazione **_f, int _n, int _d){
   *_f = (Frazione *) malloc(sizeof(Frazione));
   (*_f)->numeratore = _n;
   (*_f)->denominatore = _d;
}

void printFrazione(Frazione *_f){
   printf("%d/%d", _f->numeratore, _f->denominatore);
}

float getFrazioneDecimale(Frazione *_f){
   return((float)_f->numeratore/_f->denominatore);
}