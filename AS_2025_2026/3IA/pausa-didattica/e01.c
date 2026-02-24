/*
    Esercitazione 1 della pausa didattica.
    Data: 2026.02.24

    PER COMPILARE:
    gcc nomefile.c [invio] -> se tutto ok crea un file a.out (a.exe su windows)
    PER ESEGUIRE 
    ./a.out (./a.exe sotto windows)
*/
#include <stdio.h>

int main(){
    int a;      // variabile iniziale per fare alcune prove.
    char junk;  // cattura il carattere [invio] premuto dopo il valore di input.

    // assegnazione MANUALE di un valore iniziale ad una variabile 'a', realtiva stampa con printf.
    a = 5;
    printf("%d\n", a);

    // assegnazione con INPUT da tastiera di un valore alla variabile 'a'
    printf("Inserisci un valore per A: ");
    scanf("%d", &a); // &variabile -> indica l'indirizzo in memoria dove è allocata la variabile.
    junk = getchar();

    printf("%d\n", a);

    a = a * 2;      // moltiplico il valore per due
    a *= 2;         // come sopra ma in forma 'contratta'

    a = a + 6;
    a += 6;

    a = a + 1;      // tre formule per incrementare una variabile di una unità.
    a += 1;
    a++;
    printf("%d\n", a);

    // eseguire dei test sulla variabile.
    if(a >= 20){    // selezione unaria -> NON HA un ELSE [altrimenti]
        printf("A e' maggiore o uguale a 20.\n");
    }

    if(a >= 20){    // selezione binaria -> presenta il rampo ELSE.
        printf("A e' maggiore o uguale a 20.\n");
    }
    else{
        printf("A e' inferiore a 20.\n");
    }

    if(a >= 20){
        
    }
    else{
        printf("A e' minore di 20.\n");
    }
    /* forma errata, la trasformo girando il segno di confronto ed eliminando il ramo else
    if(a < 20){
        printf("A e' minore di 20.\n");
    }
    */

    // selezioni con operatore logico 'and'
    // il numero è multiplo di 2 e multiplo di 5
    if(a%2 == 0){
        if(a%5 == 0){
            printf("Il velore di A e' multiplo di 2 e di 5.\n");
        }
    }
    // con connettore logico E [&&]
    // if((a%2==0) && (a%5==0)){
    //    printf("Il velore di A e' multiplo di 2 e di 5");
    // }

    // selezioni con operatore logico 'or'
    // il numero è multiplo di 2 o multiplo di 5
    if(a%2 == 0){
        printf("il valore di A e' multiplo di 2\n");
    }
    if(a%5 == 0){
        printf("Il valore di A e' multiplo di 5.");
    }

    if((a%2 == 0) || (a%5 == 0)){
        printf("il valore di A e' multiplo di 2 oppure di 5, o di entrambi\n");
    }

    return(0);
}