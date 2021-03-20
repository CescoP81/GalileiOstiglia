#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct persona{
    char nome[20];
    int anni;
}Persona;

typedef struct nodo{
    Persona p;
    struct nodo* next;
}Nodo;

void addNodo(Nodo **l, char *_n, int a);
void writeFile(Nodo *l);

void leggiFile(Nodo **l);

int main(){
    Nodo *lista;
    FILE *fpout;

    lista = NULL;
    addNodo(&lista, "Giorgio", 30);
    addNodo(&lista, "Rosa", 40);
    addNodo(&lista, "Alberto", 18);
    writeFile(lista);

    Nodo *lista2;
    lista2 = NULL;

    leggiFile(&lista2);
    Nodo *tmp;
    tmp = lista2;
    while(tmp){
        printf("%s %d\n", tmp->p.nome, tmp->p.anni);
        tmp = tmp->next;
    }
    return(0);
}

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

void leggiFile(Nodo **l){
    FILE *fpin;
    Persona ptmp;
    fpin = fopen("persone2.bin", "rb");

    while(fread(&ptmp, sizeof(Persona), 1, fpin) != 0){
        addNodo(l, ptmp.nome, ptmp.anni);
    }
    fclose(fpin);
}