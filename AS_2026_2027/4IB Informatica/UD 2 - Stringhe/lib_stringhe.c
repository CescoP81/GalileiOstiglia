#include <stdio.h>
#include "lib_stringhe.h"

void initStringa(int _dim, char _str[]){
    int i;
    for(i=0; i<_dim; i++)
        _str[i] = '\0';
}

void strCharByChar(int _dim, char _str[]){
    int i;
    for(i=0; i<_dim; i++)
        printf("%c", _str[i]);
}

int lunghezzaStringa(int _dim, char _str[]){
    int len;
    
    len = 0;
    while(_str[len] != '\0')
        len++;
    
    if(len > _dim)
        return -1;
    else
        return len;
}