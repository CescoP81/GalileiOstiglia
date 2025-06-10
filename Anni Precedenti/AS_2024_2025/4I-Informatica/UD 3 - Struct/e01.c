#include <stdio.h>
#include <stdlib.h>
//const int DIM = 25;

typedef struct{
    char cognome[25];
    char nome[25];
    int anni;
}Persona;

int main(){
    Persona p;
    char junk;

    // input di una persona
    printf("Cognome: ");
    scanf("%s", &(p.cognome));
    junk = getchar();

    printf("Nome: ");
    scanf("%s", &(p.nome));
    junk = getchar();

    printf("Anni: ");
    scanf("%d", &(p.anni));
    junk = getchar();

    // visualizzo i dati nella struttura come controllo dell'avvenuto input.
    printf("\n%s %s %d\n", p.cognome, p.nome, p.anni);

    return(0);
}