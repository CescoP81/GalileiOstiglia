#include <stdio.h>
#include "lib_stringhe.c"

#define DIM 30

int main(){
    char str1[DIM];
    char str2[DIM];
    char junk;

    printf("Inserisci la prima parola: ");
    scanf("%s", &str1);
    junk = getchar();

    printf("Inserisci la seconda parola: ");
    scanf("%s", &str2);
    junk = getchar();

    if(isAnagramma(str1, str2))
        printf("Le due parole %s - %s SONO anangrammi!\n", str1, str2);
    else
        printf("Le due parole %s - %s NON sono anangrammi!\n", str1, str2);
    
    return 0;
}