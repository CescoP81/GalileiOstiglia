/*
Realizzare la struttura Persona (cognome, anni).
Realizzare un programma che inizializza due vettori da 5 strutture l'uno, realizzati come puntatori,
dopo di che ne crea un terzo, contenente tutti gli elementi del primo e del secondo presi una sola volta.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 2

typedef struct{
    char cognome[20];
    int anni;
}Persona;

int main(){

    Persona* v1;   
    Persona* v2;
    Persona* v3;
    int cnt; // parole inserire in V3.
    
    //Persona v4 ha gia la sua porzione di memoria  v4.anni
    
    //casting
    v1 = (Persona*)malloc(DIM*sizeof(Persona)); 
    v2 = (Persona*)malloc(DIM*sizeof(Persona));
      
    // inserimento dei due vettori di persone.
    for(int i=0; i<DIM; i++){
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

    for(int i=0; i<DIM; i++){
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
    printf("Primo Elenco:\n");
    for(int i=0; i<DIM; i++){
        printf("%s %d\n", (v1+i)->cognome, (v1+i)->anni );
    }

    printf("\nSecondo elenco:\n");
    for(int i=0; i<DIM; i++){
        printf("%s %d\n", (v2+i)->cognome, (v2+i)->anni );
    }

    //fondo i due vettori in un unico vettore
    v3=(Persona*)malloc(2*DIM*sizeof(Persona));

    // 1. ciclo che copia tutto il primo vettore nel terzo vettore.
    cnt = 0;
    for(int i=0; i<DIM; i++){
        *(v3+i) = *(v1+i);
        cnt++;
    }
    // 2. per ogni persona di V2 verifico che non ci sia in V3, in caso affermativo la inserisco in V3.
    int trovato; // mi indicherà se la parola di V2 da inserire in V3 è già presente oppure no.
    for(int i=0; i<DIM; i++){
        trovato = 0;
        for(int j=0; j<cnt; j++){
            if((v3+j)->anni == (v2+i)->anni && strcmp((v3+j)->cognome,(v2+i)->cognome)==0){
                trovato = 1;
            }
        }
        if(trovato == 0){
            *(v3+cnt) = *(v2+i);
            cnt++;
        }
    }
    
    // stampo V3
    printf("\nTerzo elenco:\n");
    for(int i=0; i<cnt; i++){
        printf("%s %d\n", (v3+i)->cognome, (v3+i)->anni );
    }

    return 0;
}


