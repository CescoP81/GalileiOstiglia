// sezione delle INCLUDE -> librerie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
// sezione PROTOTIPI -> DICHIARAZIONE DELLE FUNZIONI.

/**
 * Check whether a number is prime or not.
 * @param int Number to test.
 * @return boolean true/false.
 */
bool verificaPrimo(int _n);

// sezione MAIN PROGRAM
int main(){
    int valore;
    int junk;
    for(valore=1; valore <= 25; valore++){
        if(verificaPrimo(valore))
            printf("%d -> Primo\n", valore);
    }
    return(0);
}
// SEZIONE DELLE FUNZIONI -> DEFINIZIONE DELLE FUNZIONI
bool verificaPrimo(int _n){
    int div;    // variabile per i divisori del numero passato come parametro.
    int cnt;    // contatore per i divisori trovati del numero passato come parametro.

    cnt = 0;
    for(div=1; div<=_n; div++){
        if(_n%div == 0) // ho trovato un divisore! -> incremento il contatore
            cnt++;
    }

    if(cnt<=2)
        return(true);
    else
        return(false);
}