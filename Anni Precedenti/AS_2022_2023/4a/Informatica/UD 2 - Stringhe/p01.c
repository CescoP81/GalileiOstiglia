/*

*/
#include <stdio.h>

#define DIM 21

/**
 * Funzione che azzera una stringa ponendo il carattere '\0' in ogni singola cella.
 * @param char[] Stringa da utilizzare.
 * @param int Dimensione della stringa.
*/
void clearStr(char[], int);

/**
 * Funzione che inizializza una stringa righiedendola da tastiera.
 * @param char[] Stringa da utilizzare.
 * @param int Dimensione della stringa.
*/
void initStringa(char[], int);

void printStringa(char[], int);

int getStringLength(char[], int);

int main(){
    char str[DIM];

    clearStr(str, DIM);
    initStringa(str, DIM);
    printStringa(str, DIM);
    printf("\nStringa lunga: %d", getStringLength(str, DIM));
    return(0);
}

void clearStr(char _str[], int _dim){
    int i;
    for(i=0; i<_dim; i++)
        _str[i] = '\0';
}

void initStringa(char _str[], int _dim){
    printf("Inserisci stringa: ");
    scanf("%s", _str);
    fflush(stdin);
}

void printStringa(char _str[], int _dim){
    int i;
    i=0;
    while(_str[i] != '\0' && i<_dim){
        printf("%c", _str[i]);
        i++;
    }
    
    //printf("\n\n");
    //printf("%s", _str);
}

int getStringLength(char _str[], int _dim){
    int i;

    i=0;
    while(_str[i] != '\0' && i < _dim){
        i++;
    }
    return(i);
}

