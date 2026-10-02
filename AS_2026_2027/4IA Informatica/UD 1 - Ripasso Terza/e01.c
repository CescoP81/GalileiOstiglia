#include <stdio.h>
#include "lib.c"

#define DIM 10

int main(){
    int vett[DIM];
    int i;
    int tmp;

    caricaVettore(vett, DIM, 5, 25);
    stampaVettore(vett, DIM);
    printf("\n");
    printf("Valore medio del vettore: %.2f\n", mediaVettore(vett, DIM));

    i = 5;
    tmp = getValoreAt(vett, DIM, i);
    if(tmp != -1)
        printf("Valore alla cella di indice %d: %d\n", i, tmp);
    else
        printf("Hei, something goes wrong!");

    return 0;
}