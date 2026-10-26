#include <stdio.h>
#include "lib_stringa.h"

void initStringa(int _dim, char _str[]){
    int i;
    for(i=0; i<_dim; i++)
        _str[i] = '\0';
}

int lunghezzaStringa(int _dim, char _str[]){
    int len;
    len = 0;
    while(_str[len] != '\0')
        len++;
    
    if(len < _dim)
        return len;
    else
        return -1;
}