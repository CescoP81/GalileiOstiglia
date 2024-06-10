#include <stdio.h>

void stampa(int);

int main(){
    void (*pStampa)(int);
    pStampa = stampa;
    stampa(18);
    printf("\n");
    pStampa(12);
    return(0);
}

void stampa(int n){
    printf("%d",n);
}