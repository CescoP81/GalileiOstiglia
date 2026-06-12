/*
    1° step -> ACQUISIZIONE VALORI INIZIALI
    Programma che richiede in input due valori interi, 

    2° STEP -> DECISIONE SU COSA CALCOLARE (un'area o un perimetro)
    se i valori sono uguali comunica che si tratta di un quadrato e ne calcola l'area, 
    altrimenti comunica che si tratta di un rettangolo e comunica il perimetro.

    3° STEP -> COMUNICAZIONE DEI RISULTATI OTTENUTI
*/
#include <stdio.h>

int main(){
    int v1;     // variabile per il primo valore in input.
    int v2;     // variabile per il secondo valore in input.
    char junk;  // variabile per pulizia buffer di tastiera.

    printf("Inserisci il primo valore: ");
    scanf("%d", &v1);
    junk = getchar();

    printf("Inserisci il secondo valore: ");
    scanf("%d", &v2);
    junk = getchar();

    printf("-- %d %d --\n", v1, v2);    // debug operativo, riga per controllare se l'input è corretto.

    if(v1 == v2){
        // questo blocco equivale a risposta VERA
        printf("Si tratta di un quadrato... l'area vale: %d", (v1*v2));
    }
    else{
        // questo blocco equivale a risposta FALSA
        printf("Si tratta di un rettangolo... il perimetro vale: %d", (v1+v1+v2+v2));
    }

    return(0);
}