#include <stdio.h>
#include "lib_stringa.h"

void initStringa(int _dim, char _str[]){
    int i;
    for(i=0; i<_dim; i++)
        _str[i] = '\0';
}

int lunghezzaStringa(char _str[]){
    int len;
    len = 0;
    while(_str[len] != '\0')
        len++;
    
    return len;
}

void stampaContrario(char _str[]){
    int i;      // indice sulla stringa.
    int len;

    len = lunghezzaStringa(_str);   // contiene la lunghezza della stringa.
    /*for(i=len-1; i>=0; i--){
        printf("%c", _str[i]);
    }// */
    /* OPPURE ED EQUIVALENTE */
    for(i=0; i<len; i++){
        printf("%c", _str[len-i-1]);
    }
}

int contaCarattere(char _str[], char _src){
    int i;      // indice per muovermi sulla stringa.
    int len;    // lunghezza effettiva della stringa.
    int cnt;    // contatore delle occorrenze realative alla lettera cercata.

    len = lunghezzaStringa(_str);
    cnt = 0;
    for(i=0; i<len; i++){
        if(_str[i] == _src) // confronto ogni cella della stringa con il carattere ricercato.
            cnt++;
    }

    return cnt;
}
