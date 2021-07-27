/*
Realizzare la struttura Persona (cognome, anni).
Realizzare un programma che inizializza due vettori da 5 strutture l'uno, realizzati come puntatori,
dopo di che ne crea un terzo, contenente tutti gli elementi del primo e del secondo presi una sola volta.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cognome[20];
    int anni;
}Persona;

int main(){

    Persona* v1;   
    Persona* v2;
    Persona* v3;
    
    //Persona v4 ha gia la sua porzione di memoria  v4.anni
    
    //casting
    v1 = (Persona*)malloc(5*sizeof(Persona)); 
    v2 = (Persona*)malloc(5*sizeof(Persona));
      
    // inserimento dei due vettori di persone.
    for(int i=0; i<5; i++){
        int Eta;
        char Cognome[20];

        printf("Cognome: ");
        scanf("%s", Cognome);
        fflush(stdin);

        printf("Eta': ");
        scanf("%d", &Eta);
        fflush(stdin);

        (v1+i)->anni = Eta;
        strcpy((v1+i)->cognome, Cognome);    
    }

    for(int i=0; i<5; i++){
        int Eta;
        char Cognome[20];

        printf("Cognome: ");
        scanf("%s", Cognome);
        fflush(stdin);

        printf("Eta': ");
        scanf("%d", &Eta);
        fflush(stdin);

        (v2+i)->anni = Eta;
        strcpy((v2+i)->cognome, Cognome);    
    }

    // stampo i due vettori persone.
    for(int i=0; i<5; i++){
        printf("%s %d\n", (v1+i)->cognome, (v1+i)->anni );
    }

    for(int i=0; i<5; i++){
        printf("%s %d\n", (v2+i)->cognome, (v2+i)->anni );
    }


    //fondo i due vettori in un unico vettore
    v3=(Persona*)malloc(10*sizeof(Persona));

    // 1. ciclo che copia tutto il primo vettore nel terzo vettore.

    // 2. per ogni persona di V2 verifico che non ci sia in V3, in caso affermativo la inserisco in V3.
    
    

    return 0;
}

