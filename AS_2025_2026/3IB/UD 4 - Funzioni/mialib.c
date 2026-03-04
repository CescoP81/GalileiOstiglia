/* CONTIENE LA DEFINIZIONE DELLE FUNZIONI, INCLUDE mialib.h */
#include <stdio.h>
#include "mialib.h"

void vediDivisori(int _n){
    int div;
    div = 1;
    while(div <= _n){
        if(_n%div == 0){
            printf("%d ", div);
        }
        div = div + 1;
    }
}