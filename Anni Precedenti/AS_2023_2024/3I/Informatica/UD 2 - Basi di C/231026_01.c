/*
    Author: Francesco P.
    Date:   2023.10.26
    file:   231026_01.c
    Desc:   Richiedere in input il raggio di una circonferenza,
            quindi calcolare e comunicare area e perimetro.
*/
#include <stdio.h>

int main(){
    const float PI = 3.14;
    int raggio = 0;
    float area = 0;
    float perimetro = 0;

    printf("Inserisci un raggio: ");
    scanf("%d", &raggio);

    area = PI * raggio * raggio;
    perimetro = PI * raggio * 2;

    printf("Area: %.2f\n", area);
    printf("Perimetro: %.2f\n", perimetro);

    return(0);
}