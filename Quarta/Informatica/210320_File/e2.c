#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// strutture necessarie al programma
typedef struct persona{
    char nome[20];
    int anni;
}Persona;

typedef struct nodo{
    Persona p;
    struct nodo* next;
}Nodo;

// prototipi delle funzioni
/* Aggiunge un nodo in testa alla lista.
@param Nodo** Riferimento alla lista da allocare.
@param char* Stringa del nome della persona.
@param int Anni della persona.
@return void.
*/
void addNodo(Nodo **l, char *_n, int a);
void writeFile(Nodo *l);
void writeFileName(Nodo *l, char *filen);
void leggiFile(Nodo **l);


// main program.
int main(){
    Nodo *lista;
    FILE *fpout;

    // punto 1: Aggiungi alla lista 3 persone (nomi e anni a scelta)
    lista = NULL;
    addNodo(&lista, "Giorgio", 30);
    addNodo(&lista, "Rosa", 40);
    addNodo(&lista, "Alberto", 18);
    
    // punto 2: scrivi la lista attuale sul file.
    writeFile(lista);
    writeFileName(lista,"mio_archivio.bin");

    // punto 3: crea una nuova lista e inizializzala a zero.
    Nodo *lista2;
    lista2 = NULL;

    // punto 4: Leggi da file le diverse persone e crea la nuova lista.
    leggiFile(&lista2);
    
    // punto 5: stampa la nuova lista presente in memoria.
    Nodo *tmp;
    tmp = lista2;
    while(tmp){
        printf("%s %d\n", tmp->p.nome, tmp->p.anni);
        tmp = tmp->next;
    }
    return(0);
}

// definizione delle funzioni.

void addNodo(Nodo **l, char *_n, int a){
    Nodo *tmp;
    tmp = (Nodo*) malloc(sizeof(Nodo));

    strcpy(tmp->p.nome, _n);
    tmp->p.anni = a;

    tmp->next = *l;
    *l = tmp;
}

void writeFile(Nodo *l){
    FILE *fpout;
    fpout = fopen("persone2.bin", "wb");
    while(l){
        fwrite(&(l->p), sizeof(Persona), 1, fpout);
        l = l->next;
    }
    fclose(fpout);
}

void writeFileName(Nodo *l, char *filen){
    FILE *fpout;
    fpout = fopen(filen, "wb");
    while(l){
        fwrite(&(l->p), sizeof(Persona), 1, fpout);
        l = l->next;
    }
    fclose(fpout);
}

void leggiFile(Nodo **l){
    FILE *fpin;
    Persona ptmp;
    fpin = fopen("persone2.bin", "rb");

    while(fread(&ptmp, sizeof(Persona), 1, fpin) != 0){
        addNodo(l, ptmp.nome, ptmp.anni);
    }
    fclose(fpin);
}