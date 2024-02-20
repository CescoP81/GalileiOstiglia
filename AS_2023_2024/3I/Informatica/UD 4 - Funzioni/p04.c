/*
    Creare un programma che utilizzando funzioni appositamente create permetta
    le seguenti operazioni:
    - [x] Inserimento di un valore val1 compreso tra 1 e 999.
    - [x] Visualizzazione di tutti i divisori di val1.
    - [x] Calcolo e ritorno al main della somma divisori di val1.
    - [ ] Verifica se val1 è PRIMO (divisibile solo per 1 e per se stesso), la funzione
    ritorna 1 se è primo, 0 se non lo è.
    - [ ] Verifica se val1 è PERFETTO (la somma dei divisori è uguale a se stesso), la funzione
    ritorna 1 se è perfetto, 0 se non lo è. [6 è perfetto -> 1+2+3=6]
    - [ ] Inserimento di un valore val2 compreso tra 1 e 999.
    - [ ] Verifica se val1 e val2 sono numeri amici (o amicali), restituisce 1 se lo sono,
    0 se non lo sono.
    - [ ] Verifica se val1 è un quadrato perfetto, restituisce 1 se lo è, 0 se non lo è.
    Quadrato perfetto: 16, 25, 36, 49, 81, etc...
*/
#include <stdio.h>

/**
 * Funzione per input valore controllato tra minimo e massimo.
 * @param int Valore minimo del range.
 * @param int Valore massimo del range.
 * @return Valore corretto inserito.
*/
int inputValoreControllato(int _min, int _max);

void visualizzaDivisori(int _val);

int sommaDivisori(int _val);

int verificaQuadratoPerfetto(int _val);

// --------------
int main(){
    int val;

    // richiamo prima funzione.
    val = inputValoreControllato(1, 999);

    // richiamo seconda funzione.
    visualizzaDivisori(val);

    // richiamo terza funzione
    printf("Somma dei divisori: %d\n", sommaDivisori(val));
    return(0);
}

int inputValoreControllato(int _min, int _max){
    int valore;

    do{
        printf("Inserisci un valore(compreso tra %d e %d): ", _min, _max);
        scanf("%d", &valore);
        fflush(stdin);
    }while(valore<_min || valore>_max);

    return(valore);
}

void visualizzaDivisori(int _val){
    int divisore;
    divisore = 1;
    while(divisore <= _val){
        if(_val%divisore == 0){
            printf("Divisore: %d\n", divisore);
        }
        divisore = divisore + 1;
    }
}

int sommaDivisori(int _val){
    int divisore;
    int somma;

    divisore = 1;
    somma = 0;
    while(divisore <= _val){
        if(_val%divisore == 0){
            somma = somma + divisore;
        }
        divisore = divisore + 1;
    }
    return(somma);
}

int verificaQuadratoPerfetto(int _val){
    int tmp;    // valore temporaneo, parte da 1 e arriva massimo alla metà di _val

    tmp = 1;
    while(tmp <= _val/2){
        if(_val == (tmp*tmp)){
            return(1);
        }
        tmp = tmp + 1;
    }
    return(0);
}