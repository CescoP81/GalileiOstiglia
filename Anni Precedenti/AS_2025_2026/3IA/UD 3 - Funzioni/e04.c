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
    // richiamo la funzione che in modo ricorsivo scompone il valore 134 come 1 3 4
    estraiCifra(134);

    printf("\n\n");
    // richiamo la funzione che in modo ricorsivo converte il valore 12 base 10 -> in -> 1100 base 2
    convertiBinario(1756); //1100

    printf("\n\n");
    int x, y;
    x = 5;
    y = 15;
    if(scambiaValori(&x, &y) == true){
        printf("I valori sono stati scambiati x: %d, y: %d\n", x, y);
    }
    else{
        printf("I valori NON sono stati scambiati x: %d, y: %d\n", x, y);
    }
    return(0);
}