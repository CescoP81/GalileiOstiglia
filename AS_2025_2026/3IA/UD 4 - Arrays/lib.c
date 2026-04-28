#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void initVettore(int _vet[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        _vet[i] = 1 + rand()%10;
    }
}
void stampaVettore(int _vet[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        printf("%3d ", _vet[i]);
    }
}
void stampaVettoreGrafico(int _vet[], int _dim){
    int i;
    // put your code here...
    printf("%c", 218);
    for(i=0; i<_dim; i++){
        printf("%c%c%c", 196,196,196);
        if(i<_dim-1)
            printf("%c", 194);
        else
            printf("%c", 191);
    }

    printf("\n");
    printf("%c", 179);
    for(i=0; i<_dim; i++){
        printf("%3d%c", _vet[i],179);
    }
    printf("\n");
    printf("%c", 192);
    for(i=0; i<_dim; i++){
        printf("%c%c%c", 196,196,196);
        if(i<_dim-1)
            printf("%c", 193);
        else
            printf("%c", 217);
    }

    printf("\n");
    for(i=0; i<_dim; i++){
        printf("%4d", i);
    }
}

void stampaVettoreGraficoBasic(int _vet[], int _dim){
    int i;
    // put your code here...
    printf("|");
    for(i=0; i<_dim; i++){
        printf("---");
        if(i<_dim-1)
            printf("|");
        else
            printf("|");
    }

    printf("\n");
    printf("|");
    for(i=0; i<_dim; i++){
        printf("%3d|", _vet[i],179);
    }
    printf("\n");
    printf("|");
    for(i=0; i<_dim; i++){
        printf("---", 196,196,196);
        if(i<_dim-1)
            printf("|");
        else
            printf("|");
    }

    printf("\n");
    for(i=0; i<_dim; i++){
        printf("%4d", i);
    }
}

void inputManualeArray(int _vet[], int _dim, int _min, int _max){
    int i;
    char junk;
    int val;

    if(_min < _max){
        for(i=0; i<_dim; i++){
            do{
                printf("Inserisci valore cella [%d]: ", i);
                scanf("%d", &val);
                junk = getchar();
            }while(val<_min || val>_max);
            _vet[i] = val;
        }
    }
    else{
        printf("Estremi errati.");
    }
}