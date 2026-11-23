#include <stdio.h>
#include "lib_stringhe.c"

int main(){
    char _str1[40];
    int i;
    int indice;
    int cnt_lettera[26];
    char junk;

    printf("Inserisci una parola: ");
    scanf("%s", &_str1);
    junk = getchar();

    // azzero i contatori
    for(i=0; i<26; i++)
        cnt_lettera[i] = 0;

    // conto le lettere
    for(i=0; i<lunghezzaStringa(_str1); i++){ // incremento i contatori usando str1
        indice = _str1[i] - 'a';
        cnt_lettera[indice]++;
    }

    // visualizzo i contatori con la relativa lettera
    for(i=0; i<26; i++){
        printf("%c=%d ", ('a'+i), cnt_lettera[i]);
        //if((i+1)%13 == 0) // andata a capo dopo le prime 13 lettere
        //    printf("\n");
    }
    return 0;
}