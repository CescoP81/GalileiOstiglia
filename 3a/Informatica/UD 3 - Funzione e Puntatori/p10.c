/*
    Realizzare un algoritmo che richiede l'input di un valore da tastiera compreso tra due estremi definiti,
    il valore inserito viene utilizzato per generare N valor random e per ogni valore vengono visualizzati
    i divisori.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Funzione che richiede un valore in input compreso tra due estremi.
 * @param int Valore minimo.
 * @param int Valore massimo.
 * @return Valore inserito da tastiera.
*/
int inputValore(int, int);

/**
 * Funzione che genera un numero random compresto tra due estremi.
 * @param int Valore minimo
 * @param int Valore massimo
 * @return Valore random generato.
*/
int generaRandomIntervallo(int, int);

/**
 * Funzione che visualizza tutti i divisori di un numero passato come parametro.
 * @param int Valore da utilizzare.
*/
void visualizzaDivisori(int);

void f(int);

int main(){
    int n;  // numero che viene inserito dall'utente.
    int cnt;
    int r;
    srand(time(NULL));
    /*
    n = inputValore(4, 20);
    cnt = 1;
    while(cnt <= n){
        r = generaRandomIntervallo(20, 50);
        visualizzaDivisori(r);
        cnt++;
    }*/
    f(inputValore(4,20));
    return(0);
}

void f(int _n){
    int cnt;
    cnt = 1;
    while(cnt <= _n){
        visualizzaDivisori(generaRandomIntervallo(20,50));
        cnt++;    
    }
}

int inputValore(int _min, int _max){
    int numero;
    do{
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        fflush(stdin);
    }while(numero<_min || numero>_max);

    return(numero);
}

int generaRandomIntervallo(int _min, int _max){
    int random;
    random = _min + rand()%(_max - _min + 1);

    return(random);
}

void visualizzaDivisori(int _val){
    int div;
    
    div = 1;
    printf("%d: ", _val);
    while(div <= _val){
        if(_val%div == 0)
            printf("%d, ", div);
        div = div + 1;
    }
    printf("\n");
}