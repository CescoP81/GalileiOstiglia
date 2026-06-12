#include <stdio.h>
#include "mialib.c" // carico la libreria personalizzata con le funzioni scritte da me.

int main(){
    int num = 20;
    // Eseguo un test di chiamata della funzione nextPrimo
    printf("Prossimo primo di %d: %d\n", num,  nextPrimo(num));
    // Eseguo un test di chiamata della funzione prevPrimo
    printf("Primo precedente a %d: %d\n", num, prevPrimo(num));
    // Eseguo un test di chiama della funzione visualizzaPrimi
    visualizzaPrimi(15, 10);
        
    return(0);
}