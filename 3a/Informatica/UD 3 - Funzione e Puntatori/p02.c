#include <stdio.h>

/**
 * Conta e stampa il numero di divisori di un valore ricevuto come paramatro
 * @param int Valore di cui contare i divisori.
*/
void contaDivisori(int);

/**
 * Verifica se un numero ricevuto come parametro è primo oppure no.
 * @param int Numero da verificare.
*/
void verificaPrimo(int);

/**
 * Verifica se un numero ricevuto come parametro è perfetto oppure no
 * @param int Numero da verificare.
*/
void verificaPerfetto(int);

/**
 * Determina e stampa il valore massimo tra 3 valori ricevuti come parametri
 * @param int Valore 1
 * @param int Valore 2
 * @param int Valore 3
*/
void valoreMassimo(int, int, int);

//------------
int main(){
    contaDivisori(12);
    printf("\n\n");
    
    verificaPrimo(19);
    printf("\n");
    verificaPrimo(16);
    printf("\n\n");
    
    verificaPerfetto(28);
    printf("\n");
    verificaPerfetto(36);
    printf("\n\n");

    valoreMassimo(12, 7, 19);
    printf("\n");
    valoreMassimo(9, 1, 4);
    printf("\n");
    valoreMassimo(1, 18, 6);
    return(0);
}

//------------ funzioni ---------------
void contaDivisori(int _x){
    int div;
    int cnt;

    cnt = 0;
    for(div=1; div<=_x; div++){     // ciclo di conteggio divisori.
        if(_x%div == 0)
            cnt = cnt + 1;
    }
    printf("Numero di divisori di %d: %d", _x, cnt);
}

void verificaPrimo(int _x){
    int div;
    int cnt;

    cnt = 0;
    for(div=1; div<=_x; div++){
        if(_x%div == 0)
            cnt = cnt + 1;
    }

    if(cnt <= 2)
        printf("Il numero %d e' primo.", _x);
    else
        printf("Il numero %d, non e' primo.", _x);
}

void verificaPerfetto(int _x){
    int div;
    int sommaDiv;

    sommaDiv = 0;
    for(div=1; div<_x; div++){
        if(_x%div == 0)
            sommaDiv = sommaDiv + div;
    }

    if(sommaDiv == _x)
        printf("Il numero %d e' perfetto.", _x);
    else
        printf("Il numero %d non e' perfetto.", _x);
}

void valoreMassimo(int _v1, int _v2, int _v3){
    int max;
    max = _v1;

    if(_v2 > max) max = _v2;
    if(_v3 > max) max = _v3;

    printf("Valore massimo: %d.", max);
}