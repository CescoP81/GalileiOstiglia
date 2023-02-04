#include <stdio.h>

// prototipo.
int fattoriale(int);

// MAIN.
int main(){
    int n = 5;
    int f;

    f = fattoriale(n);
    printf("Fattoriale di %d: %d", n, f);
    return(0);
}
// definizione della funzione.
int fattoriale(int _n){
    int f;
    f = 1;
    while(_n > 0){
        f = f * _n;
        _n = _n - 1;
    }
    return(f);
}