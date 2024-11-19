#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int nrFigure = 5;

typedef struct{
    int base;
    int altezza;
}Rettangolo;

int main(){
    Rettangolo r[nrFigure];
    int i;
    srand(time(NULL));

    // inizializzo il vettore di figure con valori base e altezza casuali
    for(i=0; i<nrFigure; i++){
        r[i].base = 1 + rand()%10;
        r[i].altezza = 1+ rand()%10;
    }

    // visualizzo le figure generate
    for(i=0; i<nrFigure; i++){
        printf("Figura %d: %dx%d\n", i+1, r[i].base, r[i].altezza);
    }

    printf("\n\n");
    // calcolo delle aree e dei perimetri
    for(i=0; i<nrFigure; i++){
        printf("Figura %d: area=%d 2P=%d\n", i+1, (r[i].base * r[i].altezza), ((r[i].base + r[i].altezza) * 2));
    }

    // verifica se esiste un quadrato tra le figure generate.
    printf("\n\n");
    for(i=0; i<nrFigure; i++){
        printf("Figura: %d -> ", i+1);
        if(r[i].base == r[i].altezza)
            printf("Quadrato!");
        else
            printf(" -- ");
        printf("\n");
    }
    return(0);
}

/*
typedef struct{
    char nome[20];
    char cognome[20];
    struct{
        int anno;
        int mese;
        int giorno;
    }dataNascita;
}Persona;

Persona rubrica[5][5];

rubrica[0].nome;
rubrica[0].cognome;
rubrica[0].dataNascita.anno = 2005;

codice sopra utilizzando strutture e sotto strutture, codice sotto stessa memorizzazione ma
senza l'utilizzo delle strutture, ben più complesso.

char nome[5][20];
char cognome[5][20];
int anno[5];
int mese[5];
int giorno[5];

*/