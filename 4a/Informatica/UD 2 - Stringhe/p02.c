/*
    Esempio di utilizzo di stringhe come PUNTATORI a caratteri.
*/
#include <stdio.h>

int getStringLength(char*);

int main(){
    char *str;
    *str = '\0';

    printf("Inserisci stringa: ");
    scanf("%s", str);
    fflush(stdin);

    printf("Inserita: %s", str);
    printf("\nLunghezza: %d", getStringLength(str));
    return(0);
}

int getStringLength(char *_str){
    int i;
    i=0;
    while(*(_str+i) != '\0')
        i++;
    return(i);
}