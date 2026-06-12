#include <stdio.h>
#include "lib.h"

int inputNumeroFiltrato(int _x, int _y, int _z){
    int numInput;
    char junk;

    do{
        printf("Inserisci un numero compreso tra %d e %d e divisibile per %d: ", _x, _y, _z);
        scanf("%d", &numInput);
        junk = getchar();
    }while(numInput<_x || numInput>_y || numInput%_z!=0);
    return(numInput);
}

int isPrimo(int _x){
    int div;
    int cntDiv;
    if(_x <= 1)
        return(0);
    
    cntDiv = 0;
    for(div=1; div<=_x; div++){
        if(_x%div == 0)
            cntDiv++;
    }
    if(cntDiv>2)
        return(0);
    else
        return(1);
}

int trovamiPrimo(int _x, int _n){
    int num;
    int cnt;
    num = _x;
    cnt = _n;
    do{
        num = num + 1;
        if(isPrimo(num))
            cnt = cnt - 1;
    }while(cnt > 0);
    return(num);
}

void ordinaTreValori(int* _x, int* _y, int* _z){
    int scambiato;
    int tmp;

    do{
        scambiato = 0;
        if(*_x > *_y){
            tmp = *_x;
            *_x = *_y;
            *_y = tmp;
            scambiato = 1;
        }
        if(*_y > *_z){
            tmp = *_y;
            *_y = *_z;
            *_z = tmp;
            scambiato = 1;
        }
    }while(scambiato == 1);
}

int determinaFigura(int _x, int _y){
    if(_x==0 || _y==0)
        return(-1);
    if(_x == _y)
        return(_x*4);
    if(_x != _y)
        return(_x+_x+_y+_y);
}