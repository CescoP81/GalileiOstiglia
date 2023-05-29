#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Funzione che ricevuto un numero ritorna la somma delle cifre che lo compongono.
 * @param int Numero da elaborare.
 * @return Somma delle cifre del numero
*/
int sommaCifre(int);

int main(){
    int N;
    int r;
    srand(time(NULL));

    // inserimento da parte dell'utente del numero base
    do{
        printf("Inserisci N: ");
        scanf("%d", &N);
        fflush(stdin);
    }while(N<1 || N>999);

    // ciclo di ricerca di un numero che rispetti le richieste dell'esercizio.
    do{
        r = 1 + rand()%999;
    }while((sommaCifre(N) != sommaCifre(r)) || (N==r));

    // stampa del numero random generato che rispetta le richieste.
    printf("Numero trovato: %d", r);

    return(0);
}

int sommaCifre(int _x){
    int s=0;
    while(_x>0){
        s = s + (_x%10);
        _x = _x / 10;
    }
    return(s);
}