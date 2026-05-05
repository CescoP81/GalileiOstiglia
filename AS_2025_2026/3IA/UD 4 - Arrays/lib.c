#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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

// --- Funzioni per e03.c ---
int convertiBinario(int _n, int _v[], int _dim){
    int i;
    //if(_n<=255){  // limitata a 8 bit
    if(_n < pow(2, _dim)){
        for(i=0; i<_dim; i++){
            _v[i] = _n % 2;     // salvo il resto della divisione x2 quindi il bit di posto i.
            _n = _n / 2;        // divido il numero restante x2 per proseguire la scomposizione.
        }
        return(1);
    }
    else{
        return(0);
    }
}
void stampaBinario(int _v[], int _dim){
    int i;
    for(i=_dim-1; i>=0; i--){   // visualizzo il vettore dei bit binari partendo dall'ultima cella fino alla prima
        printf("%d", _v[i]);
    }
}
void stampaBinarioBasic(int _vet[], int _dim){
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
    for(i=_dim-1; i>=0; i--){
        printf("%4d", i);
    }   
}