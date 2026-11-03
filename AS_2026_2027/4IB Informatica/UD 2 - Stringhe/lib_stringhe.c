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

int isPalindroma(int _dim, char _str[]){
    int i;
    int lunghezza;
    int palindroma;

    lunghezza = lunghezzaStringa(_dim, _str);

    palindroma = 1;
    for(i=0; i<lunghezza; i++){
        if(_str[i] != _str[lunghezza-i-1])
            palindroma = 0;
    }

    return palindroma;
}
/*
    palindroma = 1;
    str[] = A N N A
    confronta A - A 
    Confronta N - N
    confronta N - N
    confronta A - A

    palindroma = 1;
    str[] = A S S O
    confronta A - O -> palindroma = 0;
    confronta S - S
    confronta S - S
    confronta O - A -> palindroma = 0;
*/