/*
    Author: Francesco P.
    Date:   2023.10.26
    file:   231026_03.c
    Desc:   Richiedere in input la misura delle basi e l’altezza di un trapezio,
            calcolare e comunicare l’area.
*/
#include <stdio.h>

int main(){
    int baseMin = 0;
    int baseMag = 0;
    int altezza = 0;
    float area = 0.0;

    printf("Inserisci base minore: ");
    scanf("%d", &baseMin);
    printf("Inserisci base maggiore: ");
    scanf("%d", &baseMag);
    printf("Inserisci l'altezza: ");
    scanf("%d", &altezza);

    area = (float)(baseMin + baseMag) * altezza / 2;

    printf("Area calcolata: %.2f\n", area);

    return(0);
}