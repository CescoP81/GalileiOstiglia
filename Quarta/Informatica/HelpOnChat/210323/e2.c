#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona{
    char nome[20];
    char cognome[20];
    int anni;    
}Persona;

typedef struct nodo{
    Persona p;
    struct nodo *next;
}Nodo;

void addNodoTesta(Nodo **l, char c[], char n[], int a);
void stampaLista(Nodo *l);
void salvaLista(Nodo *l);   // su file
void caricaLista(Nodo **l); // da file
void modificaPersona(Nodo *l, char c[], char n[], int a);
void modificaPersona2(Nodo *l, char src[]);

int main(){
    Nodo *lista;
    lista = NULL;
    char parola[20];

    // aggiungo tre nodi, quindi 3 persone alla lista
    addNodoTesta(&lista, "Rossi", "Giorgio", 45);
    addNodoTesta(&lista, "Verdi", "Alessio", 33);
    addNodoTesta(&lista, "Bianchi", "Luigi", 26);

    // stampo la lista presente in memoria.
    stampaLista(lista);

    modificaPersona(lista, "Rossi","Giorgio", 20);
    modificaPersona(lista, "Bianchi","Luigi", 88);

    printf("\n\n");
    stampaLista(lista);
    printf("\n\n");

    printf("Nominativo da cercare: ");
    scanf("%s", parola);
    fflush(stdin);
    modificaPersona2(lista, parola);
    printf("\n");
    stampaLista(lista);

    // salvare su file la lista presente in memoria.
    salvaLista(lista);

    printf("\n\n");

    // ricaricare la lista da file.
    Nodo *lista2;
    lista2 = NULL;
    caricaLista(&lista2);

    printf("\n\n");
    stampaLista(lista2);

    return(0);
}

void addNodoTesta(Nodo **l, char c[], char n[], int a){
    Nodo *newHead;
    newHead = (Nodo*) malloc(sizeof(Nodo));
    /*
        se Persona *p dentro al Nodo
        newHead->p = (Persona *) malloc(sizeof(Persona));

        strcpy(newHead->p->cognome, "rossi");
    */

    strcpy((newHead->p).cognome, c);
    strcpy((newHead->p).nome, n);
    (newHead->p).anni = a;

    newHead->next = *l;
    *l = newHead;
}

void stampaLista(Nodo *l){
    while(l != NULL){
        printf("%s %s %d\n", l->p.cognome, l->p.nome, l->p.anni);
        l = l->next;
    }
}

void salvaLista(Nodo *l){
    FILE *fpout;
    fpout = fopen("elenco_del_prade.bin", "wb");
    while(l != NULL){
        fwrite(&(l->p), sizeof(Persona), 1, fpout);
        l = l->next;
    }
    fclose(fpout);
}

void caricaLista(Nodo **l){
    Persona tmp;    // struttura temporanea che contiene i dati letti dal file.
    Nodo *newHead;
    FILE *fpin;
    fpin = fopen("elenco_del_prade.bin", "rb");

    while(fread(&tmp, sizeof(Persona), 1, fpin) != 0){
        printf("%s, %s, %d", tmp.cognome, tmp.nome, tmp.anni);
        
        newHead = (Nodo*) malloc(sizeof(Nodo));
        strcpy(newHead->p.cognome, tmp.cognome);
        strcpy(newHead->p.nome, tmp.nome);
        newHead->p.anni = tmp.anni;

        newHead->next = *l;
        *l = newHead;
    }

    fclose(fpin);
}

void modificaPersona(Nodo *l, char c[], char n[], int a){
    while(l != NULL){
        if(strcmp(l->p.cognome, c) == 0 && strcmp(l->p.nome, n) == 0)
            l->p.anni = a;
        l = l->next;
    }
}

void modificaPersona2(Nodo *l, char src[]){
    while(l != NULL){
        if(strcmp(l->p.cognome, src)==0 || strcmp(l->p.nome, src)==0){
            printf("Cognome: ");
            scanf("%s", (l->p.cognome));
            fflush(stdin);
            printf("Nome: ");
            scanf("%s", (l->p.nome));
            fflush(stdin);
            printf("Anni: ");
            scanf("%d", &(l->p.anni));
            fflush(stdin);
        }
        l = l->next;
    }
}