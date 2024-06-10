// sezione delle librerie
#include <stdio.h>
// sezione delle costanti (se ce ne sono)

/* sezione dei prototipi delle funzioni con relativa Documentazione
    Dichiarazione delle funzioni.*/

/**
 * Funzione di stampa valore a video
 * @param int Valore da stampare
*/
void stampaNumero(int);
/**
 * Funzione che visualizza i divisori di un numero
 * @param int Numero di cui visualizzare i divisori.
*/
void divisoriNumero(int);

// Sezione del MAIN PROGRAM
int main(){
    int v;

    v = 18;
    stampaNumero(v);
    printf("\n\n");
    
    divisoriNumero(v);
    printf("\n");
    divisoriNumero(25);
    printf("\n");
    divisoriNumero(48);
    printf("\n");
    divisoriNumero(12);
    printf("\n");    
    
    return(0);
}

// Sezione di definizione delle funzioni.
void stampaNumero(int _x){
    printf("Valore: %d", _x);
}

void divisoriNumero(int _x){
    int div;
    for(div=1; div<=_x; div++){
        if(_x%div == 0)
            printf("%d ", div);
    }
}