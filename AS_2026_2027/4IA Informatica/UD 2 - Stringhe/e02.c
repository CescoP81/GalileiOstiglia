/* esempio per testare la funzionalità della libreria creata*/
#include <stdio.h>
#include "lib_stringa.c"

#define DIM 20

int main(){
    char str[DIM];
    int junk;

    initStringa(DIM, str);

    printf("Inserisci una parola: ");
    scanf("%s", str);
    junk = getchar();

    printf("Stringa %s lunga: %d caratteri.\n", str, lunghezzaStringa(DIM, str));
    return 0;
}