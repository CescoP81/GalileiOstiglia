/*
    Esempio di utilizzo di stringhe come PUNTATORI a caratteri.
*/
#include <stdio.h>
#include <stdlib.h>

void initStringa(char*);
void printStringa(char*);
int getStringLength(char*);

int main(){
    char *str;
    // alloco memoria per 100 caratteri e assegno l'indirizzo iniaziale al puntatore str
    str = malloc(sizeof(char)*100);

    initStringa(str);
    printStringa(str);
    printf("\nLunghezza: %d", getStringLength(str));
    return(0);
}

void initStringa(char *_str){
    printf("Inserisci la stringa: ");
    scanf("%s", _str);
    fflush(stdin);
}
void printStringa(char *_str){
    printf("%s", _str);
}
int getStringLength(char *_str){
    int i;
    i=0;
    while(*(_str+i) != '\0')
        i++;
    return(i);
}