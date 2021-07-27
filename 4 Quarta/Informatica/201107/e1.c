/*
Date: 07.11.2020
Auth: Pradella F.
Traccia:
Realizza un algoritmo che ricevute 5 stringhe, determina quali
presentano delle doppie e verifica se sono sono state inserite due stringhe uguali.

1. Banana
2. Mela
3. Banana
4. Scacco
5. Tetto

Stringhi con doppie: Scacco - Tetto
Esistono stringhe duplicate (1. Banana - 3 Banana)
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define RIGHE 5
#define CARATTERI 15

void stampaStringhe(char **, int);

int main(){
    char stringhe[RIGHE][CARATTERI];
    int i,j,k;
    int trovato, uguali;

    // carico le stringhe
    for(i=0; i<RIGHE; i++){
        printf("Stringa: ");
        scanf("%s", stringhe[i]);
        fflush(stdin);
    }

    printf("\n\n");
    stampaStringhe((char **)stringhe,RIGHE);
/*
    // visualizzo le stringhe a verifica.
    for(i=0; i<RIGHE; i++){
        printf("%d. %s\n", i+1, stringhe[i]);
    }

    // VERIFICA PRESENZA PAROLE CON DOPPIE
    printf("\n\n-- PAROLE CHE PRESENTANO DELLE DOPPI --\n");
    for(i=0; i<RIGHE; i++){
        trovato = 0;
        for(j=0; j<strlen(stringhe[i])-1; j++){
            if(stringhe[i][j] == stringhe[i][j+1])
                //printf("La stringa %s contiene una doppia.\n", stringhe[i]);
                trovato = 1;
        }
        if(trovato)
            printf("La stringa %s contiene una doppia.\n", stringhe[i]);
    }

    // VERIFICO LA PRESENZA DI STRINGHE UGUALI
    printf("\n -- VERIFICA PAROLE UGUALI NELLA LISTA --\n");
    trovato = 0;
    for(i=0; i<RIGHE-1; i++){
        for(j=i+1; j<RIGHE; j++){
            uguali = 1;
            if(strlen(stringhe[i]) == strlen(stringhe[j])){
                for(k=0; k<strlen(stringhe[i]); k++){
                    if(stringhe[i][k] != stringhe[j][k])
                        uguali = 0;
                }
            }
            else
                uguali = 0;
            
            if(uguali){
                trovato = 1;
                printf("%d %s --> %d %s\n", i+1, stringhe[i], j+1, stringhe[j]);
            }
        } 
    }
    if(!trovato)
        printf("Non sono state trovate stringhe uguali tra loro.\n\n");
    */
    return(0);
}

//#######################
void stampaStringhe(char **_s, int r){
    int i;
    for(i=0; i<r; i++)
        printf("%d %s\n", i+1, *(_s+i));
}