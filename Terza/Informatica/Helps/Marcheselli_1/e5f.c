#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "e5.h"

void initVettore(int _v[], int _length)
{
    srand(time(NULL));
    int i;

    for (i = 0; i < _length; i++)
        _v[i] = rand() % 10 + 1;
}

void stampaVet(int _v[], int _length)
{
    int i;

    for (i = 0; i < _length; i++)
    {
        printf("%3d", _v[i]);
    }
}

float mediaVet(int _v[], int _length)
{
    int somma;
    float media;
    int i;

    somma = 0;
    for (i = 0; i < _length; i++)
        somma = somma + _v[i];

    media = (float)somma / _length;
    return (media);
}

/*Per calcolare la varianza si sommano i quadrati delle differenze
 tra i valori xi della distribuzione X e il valore medio fratto il numero di valori
 */
float varianzaVet(int _v[], int _length)
{
    float varianza;
    int somma_quadrati;
    int i;

    somma_quadrati = 0;
    for (i = 0; i < _length; i++)
    {
        somma_quadrati = somma_quadrati + pow(_v[i] - mediaVet(_v, _length), 2);
    }
    varianza = (float)somma_quadrati / _length;
    return (varianza);
}