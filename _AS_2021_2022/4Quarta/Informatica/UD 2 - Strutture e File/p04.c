/* Programma che esegue le seguenti funzioni utilizzando le strutture
- Inizializzazione di una nuova struttura.
- Visualizzazione di tutte le strutture.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
   char razza[15];
   char nome[15];
   float peso;
}Animale;
/**
 * @brief inizializza una struttura animale, 
 * 
 */
void initAnimale(Animale**,int*, char*, char*, float);

int main(){
   Animale *a;
   //Animale b; 
   //a = &b

   initAnimale(&a,"criceto", "gino", 2.5);
   printf("%s %s %.2f",(*a).razza,a->nome,a->peso);
   /*Richiamando consecutivamente tre volte la funzione InitAnimale
   inizializzare altri tre animali quindi ottenendo un vettore di animali.
   Visualizzare con un ciclo iterativo tutti e 4 gli animali presenti
   */
}

void initAnimale(Animale **_a, char *_r, char *_n, float _p){
   *_a = (Animale*)malloc(sizeof(Animale));
   strcpy((*_a)->razza, _r);
   strcpy((*_a)->nome, _n);
   (*_a)->peso = _p;
}