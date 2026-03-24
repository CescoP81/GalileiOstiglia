#include <stdio.h>
#include "mialib.c"

int main(){
    int a;
    a = 7;

    printf("A: %d - Addr: %p\n", a, &a);
    raddoppiaValore(&a);
    printf("A: %d\n", a);

    printf("\n\n");
    int b = 5;
    int h = 8;
    int ar, pe;

    calcolaAreaPerimetro(b, h, &ar, &pe);
    printf("Rettangolo %dx%d; area: %d, perimetro: %d\n", b, h, ar, pe);
    return(0);
}