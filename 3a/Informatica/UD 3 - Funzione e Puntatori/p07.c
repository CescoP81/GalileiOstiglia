#include <stdio.h>

/**
 * Funzione che calcola la potenza di un numero.
 * @param int Base della potenza.
 * @param int Esponente della potenza.
 * @return Valore determinato.
*/
int potenza(int, int);

int main(){
    int a,b;
    int p;

    a = 5;
    b = 3;

    p = potenza(a, b);
    printf("Il valore di %d^%d: %d", a, b, p);
    return(0);
}
// ------------------------------------
int potenza(int _base, int _esponente){
    int p;
    p = 1;
    while(_esponente > 0){
        p = p * _base;
        _esponente = _esponente - 1;
    }
    return(p);
}