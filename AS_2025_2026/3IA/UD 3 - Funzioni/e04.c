#include <stdio.h>
#include "mialib.c"

int main(){
    int a;
    a = 7;

    printf("A: %d - Addr: %p\n", a, &a);
    raddoppiaValore(&a);    // richiamo funzione con parametro passato per riferimento.
    printf("A: %d\n", a);

    printf("\n\n");
    int b = 5;
    int h = 8;
    int ar, pe;
    // richiamo funzione con passaggio di parametri misto valore e riferimento.
    calcolaAreaPerimetro(b, h, &ar, &pe);
    printf("Rettangolo %dx%d; area: %d, perimetro: %d\n", b, h, ar, pe);

    printf("\n\n");
    estraiCifra(134);

    printf("\n\n");
    convertiBinario(1756); //1100
    return(0);
}