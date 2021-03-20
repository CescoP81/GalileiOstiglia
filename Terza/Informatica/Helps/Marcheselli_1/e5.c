
#include <stdio.h>
#include "e5f.c"

#define DIM 20

int main()
{
    int vet[DIM];

    initVettore(vet, DIM);

    printf("\nValori:\n");
    stampaVet(vet, DIM);

    printf("\nMedia: %.2f\n", mediaVet(vet, DIM));

    printf("Varianza dei valori: %.3f\n", varianzaVet(vet, DIM));

    return (0);
}