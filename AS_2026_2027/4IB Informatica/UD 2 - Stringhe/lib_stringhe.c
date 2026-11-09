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

void contaLettere(int _dim, char _str[]){
    /* sfrutta le informazioni della ASCII TABLE dove una lettera è rappresentata
        da 8bit ovvero 1byte, quindi le possibili combinazioni sono 255.
        In particolare l'alfabeto minuscolo inizia dal carattere 97
        mentre l'alfabeto maiuscolo inizia dal carattere 65
    */
    int cnt_lettera[26]; // vettore dei contatori
    int indice;          // indice da usare sul vettore dei contatori
    int i;               // indice da usare con ciclo for sulla _str

    // azzero tutti i contatori.
    for(indice=0; indice<26; indice++)
        cnt_lettera[indice] = 0;

    // analizzo tutta la stringa _str utilizzando ogni singolo carattere per calcolare l'indice
    // sul vettore cnt_lettera
    for(i=0; i<lunghezzaStringa(_dim, _str); i++){
        //indice = _str[i] - 'a'; // calcolo l'indice nel vettore dei contatori associato alla lettera in esame.
        if(_str[i]>='a' && _str[i]<='z')
            indice = _str[i] - 'a';
        if(_str[i]>='A' && _str[i]<='Z')
            indice = _str[i] - 'A';

        cnt_lettera[indice]++;
    }

    // Stampo a video tutti i contatori per verificare che siano stati incrementati solo quelli della parola inserita.
    for(indice=0; indice<26; indice++){
        printf("%c -> %d\t", ('a'+indice), cnt_lettera[indice]);
        if((indice+1)%13 == 0)
            printf("\n");        
        
        /*if(cnt_lettera[indice] != 0){
            printf("%c -> %d\t", ('a'+indice), cnt_lettera[indice]);
            if((indice+1)%5 == 0)
                printf("\n");
        }*/
    }
}