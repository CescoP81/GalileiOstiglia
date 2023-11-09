/*
    Author: Francesco P.
    Date:   2023.10.26
    file:   231026_02.c
    Desc:   Richiedere in input il perimetro di quadrato,
            calcola e comunicare la lunghezza del lato e l’area.
*/
#include <stdio.h>

int main(){
    int perimetro = 0;
    float lato = 0.0;
    float area = 0.0;

    printf("Inserisci il perimetro del quadrato: ");
    scanf("%d", &perimetro);

    lato = (float)perimetro / 4;
    area = lato * lato;

    printf("Lunghezza lato: %.2f\n", lato);
    printf("Area totale: %.2f\n", area);

    return(0);
}