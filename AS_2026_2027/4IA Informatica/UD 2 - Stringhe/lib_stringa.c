#include <stdio.h>
#include <stdbool.h>
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

void contaInteroAlfabeto(char _str[]){
    int i;      // contatore per passare le 26 lettere dell'alfabeto
    char src;   // lettera da contare
    int cntLettera[26]; //array dei contatori per ogni lettera [0]->'a' [1]->'b'...

    src = 'a';
    /*for(i=0; i<26; i++){
        printf("%c -> %2d ", (src+i), contaCarattere(_str,(src+i)));
        if((i+1)%13 == 0)
            printf("\n");
    }*/
    for(i=0; i<26; i++){
        cntLettera[i] = 0;
        cntLettera[i] = contaCarattere(_str, (src+i));
    }

    for(i=0; i<26; i++){
        printf("%c -> %2d ", (src+i), cntLettera[i]);
        if((i+1) % 13 == 0)
            printf("\n");
    }
}

bool isAnagramma(char _str1[], char _str2[]){
    int cntLettera[26];
    int i;

    // verifico che siano di lunghezze uguali
    if(lunghezzaStringa(_str1) != lunghezzaStringa(_str2))
        return false;
    
    for(i=0; i<26; i++){
        /*
        cntLettera[i] = 0;
        cntLettera[i] = contaCarattere(_str1, ('a'+i)); //conto quante volte compare il caratteri su stringa 1
        cntLettera[i] -= contaCarattere(_str2, ('a'+i));

        if(cntLettera[i] != 0)
            return false;
        */
       // soluzione Malaspina
        if(contaCarattere(_str1, ('a'+i)) != contaCarattere(_str2, ('a'+i)))
           return false;
    }
    return true;
}