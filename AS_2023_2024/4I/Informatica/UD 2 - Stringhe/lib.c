// lib.c contiene tutte le definizioni delle funzioni.
// include tutte le librerie necessarie alle funzioni.
// include il file header lib.h con i prototipi.
#include <stdio.h>
#include "lib.h"

void initStringa(char _s[], int _dim){
    int i;
    for(i=0; i<_dim; i++)
        _s[i] = '\0';
}
void inputStringa(char _s[]){
    printf("Inserisci una parola: ");
    scanf("%s", _s);
}
int lunghezzaStringa(char _s[]){
    int i=0;
    while(_s[i] != '\0')
        i = i + 1;
    return(i);
}
int contaLetteraStringa(char _s[], char _c){
    int i;
    int cnt;

    i=0; 
    cnt=0;

    while(_s[i]!='\0'){
        if(_s[i] == _c){
            cnt = cnt + 1;
        }
        i = i + 1;
    }
    return(cnt);
}
int contaVocaliStringa(char _s[]){
    int i;
    int cnt;

    i = 0;
    cnt = 0;
    while(_s[i] != '\0'){
        if(_s[i]=='a' || _s[i]=='e' || _s[i]=='i' || _s[i]=='o' || _s[i]=='u'){
            cnt = cnt + 1;
        }
        i = i + 1;
    } 
    return(cnt);
}
void sostituisciCarattereStringa(char _s[], char _src, char _dst){
    int i;

    i = 0;
    while(_s[i] != '\0'){
        if(_s[i] == _src)
            _s[i] = _dst;
        i = i + 1;
    }
}
void stampaContrarioStringa(char _s[]){
    int i;
    for(i=lunghezzaStringa(_s)-1; i>=0; i--)
        printf("%c", _s[i]);
}
int verificaPalindroma(char _s[]){
    int i;
    int lung = lunghezzaStringa(_s);
    for(i=0; i<lung; i++){
        if(_s[i] != _s[lung-i-1]){
            return(0);
        }
    }
    return(1);
}