#include <stdio.h>
#include "lib.c"

int main(){
    Shape figura;

    inputShape(&figura);

    printf("Base: %d, Altezza: %d\n", figura.b, figura.h);

    return 0;
}