/*
Realizza un programma C che richiede l’input di due valori ‘a’ e ‘b’ interi positivi con ‘a’ minore di ‘b’.
Il programma calcola il prodotto a*b con somme successive e lo comunica a video.
*/
#include <stdio.h>

int main(){
    int a, b;
    int cntSomme;
    int prodotto;

    do{
        printf("Inserisci a: ");
        scanf("%d", &a);
        fflush(stdin);

        printf("Inserisci b: ");
        scanf("%d", &b);
        fflush(stdin);
    }while(a>=b);

    prodotto = 0;
    cntSomme = 1;
    while(cntSomme <= b){
        prodotto = prodotto + a;
        cntSomme = cntSomme + 1;
    }

    printf("Il prodotto %d*%d vale: %d", a, b, prodotto);
    return(0);
}