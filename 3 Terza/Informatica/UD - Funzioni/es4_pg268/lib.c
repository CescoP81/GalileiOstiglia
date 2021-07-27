#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void initTemperature(int _tmin[], int _tmax[], int _length){
    int i;
    srand(time(NULL));
    // genero le temperaure minime comprese tra 0 e 10 gradi
    for(i=0; i<_length; i++)
        _tmin[i] = rand()%11;
    
    // genero le temperature massime comprese tra 15 e 30 gradi
    for(i=0; i<_length; i++)
        _tmax[i] = rand()%(30-15+1) + 15;
}

void stampaTemperature(int _temp[], int _length){
    int i;
    for(i=0; i<_length; i++)
        printf("%3d", _temp[i]);
}

float tmp_media(int _tmp[], int _length){
    int i;
    int somma;
    float media;

    somma = 0;
    for(i=0; i<_length; i++)
        somma = somma + _tmp[i];
    
    media = (float)somma / _length;
    return(media);
}

int deltaMinore(int _tmin[], int _tmax[], int _length){
    int differenza;
    int diff_minore;
    int indice_diff_minore;
    int i;

    diff_minore = _tmax[0] - _tmin[0];
    indice_diff_minore = 0;

    for(i=1; i<_length; i++){
        differenza = _tmax[i] - _tmin[i];
        if(differenza < diff_minore){
            diff_minore = differenza;
            indice_diff_minore = i;
        }
    } 
    return(indice_diff_minore);
}