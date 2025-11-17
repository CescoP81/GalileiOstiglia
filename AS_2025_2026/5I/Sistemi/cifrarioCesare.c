#include <stdio.h>
#include <string.h>

void cript(char originale[], int _chiave);

int main(){
    char str[100];
    char criptata[100];
    int chiave;

    printf("Inserisci la stringa: ");
    gets(str);
    fflush(stdin);

    printf("Stringa originale: %s\n", str);

    chiave = 4;
    cript(str, chiave);
    //printf("Criptata:")
    return(0);
}

void cript(char _originale[], int _chiave){
    int i;
    char strCriptata[100]="\0";
    int len;
    char carattere;

    printf("Numero caratteri: %d\n", strlen(_originale));
    
    len = strlen(_originale);
    for(i=0; i<len; i++){
        carattere = _originale[i] - 'a';
        carattere = carattere + _chiave;
        if(carattere > 26) carattere = carattere - 26;
        
        strCriptata[i] = carattere + 'a';
        printf("%c -> %c\n", _originale[i], strCriptata[i]);
    }
    strCriptata[len] = '\0';
    printf("Cripta: %s", strCriptata);
}