#include <stdio.h>
const int DIM_STRINGA = 20;
const int NR_STRINGHE = 5;
int main(){
    /*dichiaro una matrice di caratteri formata da 5 righe e 20 colonne,
    ogni riga conterrà una stringa di massimo 19 caratteri più il terminatore.
    Utilizzo la matrice come un elenco di parole da analizzare, modificare, etc...*/
    char parole[NR_STRINGHE][DIM_STRINGA+1];

    int i;
    for(i=0; i<NR_STRINGHE; i++){
        printf("Inserisci la %d parola: ", i+1);
        gets(parole[i]);
    }

    for(i=0; i<NR_STRINGHE; i++){
        printf("%s ", parole[i]);
    }
    return(0);
}