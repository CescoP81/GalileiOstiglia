#include <stdlib.h>
#include <stdio.h>

typedef struct {  // typedef fà diventare Studente un nuovo tipo di variabile da usare come int,float, char...
    char nome[20];
    char cognome[20];
    int anno_nascita;
}Studente;

void stampaStudente(Studente);

int main(){
    Studente s; // s è la variabile strutturata secondo la forma Studente

    printf("Nome: ");
    scanf("%s", s.nome);
    fflush(stdin);
    printf("Cognome: ");
    scanf("%s", s.cognome);
    fflush(stdin);
    printf("Anno: ");
    scanf("%d", &s.anno_nascita);

    //printf("\n\n%s %s %d", s.nome, s.cognome, s.anno_nascita);
    stampaStudente(s);

    return(0);
}

void stampaStudente(Studente _x){
    printf("\n\n%s %s %d", _x.nome, _x.cognome, _x.anno_nascita);  
}